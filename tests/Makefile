CC=g++
CFLAGS=-D _DEBUG -ggdb3 -std=c++2a -O0 -Wall -Wextra -Weffc++\
-Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations\
-Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported\
-Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral\
-Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op\
-Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith\
-Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo\
-Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn\
-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default\
-Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast\
-Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers\
-Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector 

COPTIONS=-fcheck-new\
-fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging\
-fno-omit-frame-pointer -fPIE -fsanitize=address,alignment,bool,${strip \
}bounds,enum,float-cast-overflow,float-divide-by-zero,${strip \
}integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,${strip \
}returns-nonnull-attribute,shift,signed-integer-overflow,undefined,${strip \
}unreachable,vla-bound,vptr\
-pie -Wlarger-than=8192 -Wstack-usage=8192

DEBUG?=0

ifeq ($(DEBUG), 0)
	CFLAGS+="-D NDEBUG"
endif

SRC=$(realpath ../src)
BUILDDIR=$(realpath ../build/tests)

run_tests: tests
	cd test_cases && $(BUILDDIR)/bin/tests

all: tests

tests: $(BUILDDIR)/obj/main.o\
	   $(BUILDDIR)/obj/quadratic_tests.o\
	   $(BUILDDIR)/obj/file_reader.o\
	   $(BUILDDIR)/obj/testing.o\
	   $(BUILDDIR)/obj/quadratic.o\
	   $(BUILDDIR)/obj/quadio.o\
	   $(BUILDDIR)/obj/double_utils.o
	$(CC) $(COPTIONS) $(BUILDDIR)/obj/* -o $(BUILDDIR)/bin/tests
	cp -r test_cases/ $(BUILDDIR)/

$(BUILDDIR)/obj/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o $(BUILDDIR)/obj/main.o

$(BUILDDIR)/obj/quadratic_tests.o: quadratic_tests.cpp
	$(CC) $(CFLAGS) -c quadratic_tests.cpp -o $(BUILDDIR)/obj/quadratic_tests.o

$(BUILDDIR)/obj/testing.o: testing.cpp
	$(CC) $(CFLAGS) -c testing.cpp -o $(BUILDDIR)/obj/testing.o

$(BUILDDIR)/obj/file_reader.o: file_reader.cpp
	$(CC) $(CFLAGS) -c file_reader.cpp -o $(BUILDDIR)/obj/file_reader.o

$(BUILDDIR)/obj/quadio.o: $(SRC)/quadio.cpp
	$(CC) $(CFLAGS) -c $(SRC)/quadio.cpp -o $(BUILDDIR)/obj/quadio.o

$(BUILDDIR)/obj/quadratic.o: $(SRC)/quadratic.cpp
	$(CC) $(CFLAGS) -c $(SRC)/quadratic.cpp -o $(BUILDDIR)/obj/quadratic.o

$(BUILDDIR)/obj/double_utils.o: ../src/double_utils.cpp
	$(CC) $(CFLAGS) -c $(SRC)/double_utils.cpp -o $(BUILDDIR)/obj/double_utils.o

clean:
	rm $(BUILDDIR)/bin/* $(BUILDDIR)/obj/*
	rm -r $(BUILDDIR)/test_cases
