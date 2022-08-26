#include "io_utils.h"
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

enum line_skip_status skip_line(FILE *fd)
{
    while (1)
    {
        switch(getc(fd))
        {
            case EOF:
                return FILE_END;
            case '\n':
                return LINE_END;
            default:
                break;
        }
    }
}

/**
 * @brief Maps file lines to memory
 * 
 * @param[in] path - path to file
 * @param[out] file_size - pointer to file size
 * @return file contents
 */
static char* map_file(const char *path, size_t *file_size)
{
    assert(path != NULL);

    /* Open file descriptor */
    int fd = open(path, O_RDONLY);
    if (fd < 0) {/* Cannot open file, errno set by open */
        perror("Cannot open file.");
        return NULL;
    }

    /* Get file size */
    struct stat file_stat;
    if (fstat(fd, &file_stat) < 0) /* Cannot read file, errno set by fstat */
    {
        int tmp = errno;
        close(fd);
        errno = tmp;
        return NULL;
    }

    /* Call mmap */
    char *mapping = (char*) mmap( /* Map extra byte for '\0' */
        NULL, (size_t)file_stat.st_size + 1u,
        PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    close(fd);
    if (mapping == MAP_FAILED) /* Mapping failed, errno set by mmap */
    {
        perror("Failed to read file.");
        return NULL;
    }

    *file_size = (size_t)file_stat.st_size + 1u;
    return mapping;
}

const LineFileReader *read_file(const char *path)
{
    char *text = NULL;
    size_t text_len = 0;

    text = map_file(path, &text_len);

    if (text == NULL)
        return NULL;

    size_t line_count = 1;
    for (int i = 0; i < text_len - 1; i++) /* NUL-terminate each line */
        if (text[i] == '\n')
        {
            text[i] = '\0';
            line_count++;
        }
    text[text_len - 1] = '\0';

    char ** lines = (char**) calloc(line_count, sizeof(char*));
    char *last_line = text; /* Pointer to the beginning of last line */
    int line_num = 0;
    for (int i = 0; i < text_len; i++)
        if (text[i] == '\0') /* Line ended */
        {
            lines[line_num] = last_line; /* Store line */
            last_line = &text[i + 1]; /* Next line begins on i+1st position */
            line_num++; /* Increment line number */
        }

    /* Allocate struct */
    LineFileReader *lfreader = (LineFileReader*) calloc(1, sizeof(LineFileReader));

    /* Store file contents */
    *lfreader = {
            .text = (const char*) text,
            .text_len = text_len,
            .lines = (const char* const *) lines,
            .line_count = line_count
        };
    return lfreader;
}

void close_reader(const LineFileReader *lfreader)
{
    if (lfreader == NULL)
        return;

    munmap((char *)lfreader->text, lfreader->text_len);
    free((char **)lfreader->lines);
    free((void *)lfreader);
}
