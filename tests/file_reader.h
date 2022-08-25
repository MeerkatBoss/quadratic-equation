#ifndef FILE_READER_H
#define FILE_READER_H

/* TODO: Use buffer for file contents */

struct FileReader;
typedef struct FileReader FileReader;

FileReader *open_file(const char*);
int get_line_number(FileReader*);
int next_line(FileReader*, int, char*);
void close_file(FileReader*);

#endif
