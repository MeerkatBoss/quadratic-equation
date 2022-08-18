#ifndef TESTING_H
#define TESTING_H

#define TEST_SOURCE(func) "./test_cases/" #func "_test.txt"

struct _test_file;
typedef struct _test_file TestFile;

TestFile *test_file(const char*);
int get_case_number(TestFile*);
int next_test_case(TestFile*, unsigned int, char*);
void close_test_file(TestFile*);

#endif
