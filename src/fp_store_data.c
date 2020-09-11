#include "../inc/libmx.h"
#include "findpath.h"
#define N 6 

static void print_islandlist(island_list *head) {
    island_list *current = head;

    while(current != NULL) {
        printf("name: %s; number: %d; ", current->name, current->number);
        for (int i = 0; current->const_neighbours[i] != NULL; i++) {
            printf("%s | ", current->const_neighbours[i]->name);
        }
        printf("\n");
        current = current->next;
    }
}

void fp_store_data(char ***Islands, int ***Matrix, const char *filename, int ***WayMatrix, 
                    island_list **islandlist) {
    IslandArray(Islands, filename);
    FillTheMatrix(Matrix, *Islands, filename);
    FillTheWayMatrix(WayMatrix, Matrix);
    *islandlist = fill_island_list(*Islands, *WayMatrix);
    print_islandlist(*islandlist);
    printf("end");
    // for (int i =0 ; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         printf("Warr[%d][%d] = %d\n", i, j, (*WayMatrix)[i][j]);
    //     }
    // }
}
