#ifndef TESTING_H
#define TESTING_H

#define TEST_SOURCE(func) "./test_cases/" #func "_test.txt"

struct TestFile;
typedef struct TestFile TestFile;

TestFile *test_file(const char*);
int get_case_number(TestFile*);
int next_test_case(TestFile*, int, char*);
void close_test_file(TestFile*);

#endif
