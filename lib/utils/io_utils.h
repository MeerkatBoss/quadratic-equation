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

/**
 * @brief Wraps FILE*, provides access to line-by-line
 * reading of a file. Counts lines automatically,
 * starting at 0
 */
typedef struct
{
    const char *text;
    size_t text_len;
    const char * const * lines;
    size_t line_count;
} LineFileReader;

/**
 * @brief Allocates LineFileReader, opens specified file
 * 
 * @param[in] path - path to opened file
 * @return Allocated LineFileReader with opened file 
 */
const LineFileReader *read_file(const char* path);

/**
 * @brief Frees allocated LineFileReader and closes associated file
 * 
 * @param[in] lfreader - LineFileReader instance
 */
void close_reader(const LineFileReader* lfreader);

#endif