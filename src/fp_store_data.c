#include "../inc/libmx.h"
#include "findpath.h"
#define N 6 

void fp_store_data(char ***Islands, int ***Matrix, const char *filename, int ***WayMatrix) {
    IslandArray(Islands, filename);
    FillTheMatrix(Matrix, *Islands, filename);
    FillTheWayMatrix(WayMatrix, Matrix);
    for (int i =0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Warr[%d][%d] = %d\n", i, j, (*WayMatrix)[i][j]);
        }
    }
}
