#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include "../src/quadio.h"
#include "testing.h"

struct TestFile
{
    FILE *fd;
    int line;
};

TestFile *test_file(char *path)
{
    assert(path != NULL);
    if (path == NULL)
    {
        errno = EINVAL;
        return NULL;
    }

    TestFile *tf = NULL;
    tf = (TestFile *) calloc(1, sizeof tf);

    if (tf == NULL) /* failed to allocate, errno set by malloc */
        return NULL;

    tf->line = 0;
    tf->fd = NULL;
    tf->fd = fopen(path, "r");

    if (tf->fd == NULL) /* failed to open file, errno set by fopen */
    {
        int tmp = errno;
        free(tf);
        errno = tmp;
        return NULL;
    }

    return tf;
}

int get_case_number(TestFile *tf)
{
    assert(tf != NULL);
    if (tf == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    return tf->line;
}

int next_case(TestFile *tf, int bufsize, char *buffer)
{
    assert(tf != NULL);
    if (tf == NULL)
    {
        errno = EINVAL;
        return -2;
    }

    assert(buffer != NULL);
    if (buffer == NULL)
    {
        errno = EDESTADDRREQ;
        return -2;
    }

    if (feof(tf->fd)) /* already finished reading file */
        return EOF;

    fgets(buffer, bufsize, tf->fd);

    if (ferror(tf->fd)) /* problem when reading file */
    {
        errno = EIO;
        return -2;
    }

    tf->line++;

    if (feof(tf->fd)) /* last line read */
        return EOF;
    if (buffer[bufsize - 2] != '\n') /* did not read to the end */
    {
        flush_input(tf->fd);
        errno = EOVERFLOW;
        return -2;
    }
    return 0;
}

void close_test_file(TestFile *tf)
{
    assert(tf != NULL);
    if (tf == NULL)
    {
        errno = EINVAL;
        return;
    }

    fclose(tf->fd);
    free(tf);
}

