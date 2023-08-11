#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>
#include <ports.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double

#define ABS(a)      ((a) < 0 ? -(a) : (a))
#define MAX(a, b)   ((a + b + ABS(a-b)) / 2)
#define MIN(a, b)   ((a) < (b) ? (a) : (b))
#define SWAP(a, b, T)  {T tmp = a; a = b; b = tmp;}
#define SWAPI(arr, i, j, T) {SWAP(arr[i], arr[j], T);}


#ifdef DEBUG
#define DEBUGPRINT(_msg, ...) fprintf(stderr, ".\\%s:%d " _msg, __FILE__, __LINE__, ##__VA_ARGS__);
#else
#define DEBUGPRINT(_msg, ...) // do nothing
#endif

#define GENERROR(code, _msg, ...) fprintf(stderr, "ERROR: Code %d,\nMessage from : .\\%s:%d\nMore details :\n\t" _msg "\n", code, __FILE__, __LINE__, ##__VA_ARGS__);

#define NULLContainer (Container){.id = 0};

typedef enum ExitCode {
    SUCCESS = EXIT_SUCCESS,
    ERROR,
    MALLOC_FAILED,
    FILE_ERROR,
    EMPTY_STACK,
    FULL_STACK,
} ExitCode;

typedef struct Container {
    int id; // container ID
    int From;
    int Dest;
    // other stuff we don't care rn
} Container;

void print_Container(Container c);

#endif
