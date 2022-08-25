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

all: bin/quad

bin/quad: obj/main.o obj/quadratic.o obj/quadio.o obj/double_utils.o
	$(CC) $(COPTIONS) obj/* -o bin/quad

obj/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o obj/main.o

obj/quadratic.o: quadratic.cpp
	$(CC) $(CFLAGS) -c quadratic.cpp -o obj/quadratic.o

obj/quadio.o: quadio.cpp
	$(CC) $(CFLAGS) -c quadio.cpp -o obj/quadio.o

obj/double_utils.o: double_utils.cpp
	$(CC) $(CFLAGS) -c double_utils.cpp -o obj/double_utils.o

clean:
	rm bin/* obj/*
