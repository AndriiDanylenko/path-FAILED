#include "findpath.h"
#include "../inc/libmx.h"

int main(int argc, const char **argv) {
    fp_validation(argc, argv);
    
    char **Islands = NULL;
    int **Matrix = NULL;
    int **WayMatrix = NULL;
    island_list *islandlist = NULL;
    
    fp_store_data(&Islands, &Matrix, argv[ARGC_NUMBER], &WayMatrix, &islandlist);
    fp_floyd(&Matrix/*, &WayMatrix*/);
    // fp_print_output(Matrix, WayMatrix, Islands, argv[ARGC_NUMBER]);
    mx_del_strarr(&Islands);
    mx_delintarr(&Matrix);
    mx_delintarr(&WayMatrix);
    
    return 0;
}
//gcc -Wall -Werror -Wpedantic -Wextra -o o -I libmx/inc -I inc src/*.c libmx/src/*.c

