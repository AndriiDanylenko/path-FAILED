#include "../inc/libmx.h"
#include "findpath.h"
#define N 6 

static void print_islandlist(island_list *head) {
    island_list *current = head;
    
    while(current != NULL) {
        printf("name: %s; number: %d\n", current->name, current->number);
        current = current->next;
    }
}

void fp_store_data(char ***Islands, int ***Matrix, const char *filename, int ***WayMatrix, 
                    island_list **islandlist) {
    IslandArray(Islands, filename);
    *islandlist = fill_island_list(*Islands);
    print_islandlist(*islandlist);
    
    FillTheMatrix(Matrix, *Islands, filename);
    FillTheWayMatrix(WayMatrix, Matrix);
    // for (int i =0 ; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         printf("Warr[%d][%d] = %d\n", i, j, (*WayMatrix)[i][j]);
    //     }
    // }
}
