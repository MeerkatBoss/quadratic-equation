#ifndef IO_UTILS_H
#define IO_UTILS_H

/**
 * @file io_utils.h
 * @author MeerkatBoss
 * @brief Contains helper functions for IO
 * @version 0.1
 * @date 2022-08-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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

/**
 * @brief Wraps FILE*, provides access to line-by-line
 * reading of a file. Counts lines automatically,
 * starting at 1
 */
struct FileReader;
typedef struct FileReader FileReader;

/**
 * @brief Allocates FileReader, opens specified file
 * 
 * @param[in] path - path to opened file
 * @return Allocated FileReader with opened file 
 */
FileReader *open_file(const char* path);

/**
 * @brief Gets number of last read line. Lines are numerated
 * starting at 1
 * 
 * @param[in] freader - FileReader instance
 * @return Number of line
 */
int get_line_number(FileReader* freader);

/**
 * @brief Reads no more than buflen-1 characters from next
 * line into buffer
 * 
 * @param[in] freader - FileReader instance
 * @param[in] buflen - buffer size
 * @param[out] buffer - output buffer
 * @return 0 upon success, EOF upon encountering end of file,
 * -2 upon failure
 */
int next_line(FileReader* freader, int buflen, char* buffer);

/**
 * @brief Frees allocated FileReader and closes associated file
 * 
 * @param[in] freader - FileReader instance
 */
void close_file(FileReader* freader);

#endif