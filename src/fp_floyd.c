#include "findpath.h"
#include "../inc/libmx.h"
#define N 6

void Add(long long *sum, int first, int second) {
    long long dodanok1 = first;
    long long dodanok2 = second;
    *sum = dodanok1 + dodanok2;
}

void fp_floyd(int ***Matrix/*, int ***WayMatrix*/) {
    long long sum;
    long long element;

    for (int k = 0; (*Matrix)[k] != NULL; k++) {
        for (int i = 0; (*Matrix)[i] != NULL; i++) {
            for (int j = 0; (*Matrix)[j] != NULL; j++) {
                Add(&sum, (*Matrix)[i][k], (*Matrix)[k][j]);
                element = (*Matrix)[i][j];
                if (element > sum) {
                    (*Matrix)[i][j] = (*Matrix)[i][k] + (*Matrix)[k][j];
                    
                }
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("arr[%d][%d] = %d\n", i, j, (*Matrix)[i][j]);
        }
    }
}
