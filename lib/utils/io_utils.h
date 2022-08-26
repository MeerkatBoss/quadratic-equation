#ifndef IO_UTILS_H
#define IO_UTILS_H

#include <stdio.h>

enum line_skip_status
{
    LINE_END = 0,
    FILE_END = -1
};

/**
 * @brief Reads and discards all symbols until '\\n'
 * from stream
 * 
 * @param[in] fd - file descriptor of a stream
 * @return 0 upon success; EOF upon encountering end-of-file
 */
enum line_skip_status skip_line(FILE *fd);

/* TODO: Use buffer for file contents */

struct FileReader;
typedef struct FileReader FileReader;

FileReader *open_file(const char*);
int get_line_number(FileReader*);
int next_line(FileReader*, int, char*);
void close_file(FileReader*);

#endif