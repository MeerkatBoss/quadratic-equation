#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include "../src/quadio.h"
#include "file_reader.h"

struct FileReader
{
    FILE *fd;
    int line;
};

FileReader *open_file(const char *path)
{
    assert(path != NULL);
    if (path == NULL)
    {
        errno = EINVAL;
        return NULL;
    }

    FileReader *tf = (FileReader *) calloc(1, sizeof(FileReader));

    if (tf == NULL) /* failed to allocate, errno set by malloc */
        return NULL;

    *tf = { .fd = fopen(path, "r"), .line = 0 };

    if (tf->fd == NULL) /* failed to open file, errno set by fopen */
    {
        free(tf);
        return NULL;
    }

    return tf;
}

int get_line_number(FileReader *tf)
{
    assert(tf != NULL);
    if (tf == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    return tf->line;
}

int next_line(FileReader *tf, int bufsize, char *buffer)
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
    if (strchr(buffer, '\n') == NULL) /* did not read to the end */
    {
        skip_line(tf->fd);
        errno = EOVERFLOW;
        return -2;
    }
    return 0;
}

void close_file(FileReader *tf)
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

