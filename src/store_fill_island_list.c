#include "../inc/libmx.h"
#include "findpath.h"


island_list *fill_island_list(char **Islands) {
    island_list *head = NULL;

    for (int i = 0; Islands[i] != NULL; i++) {
        store_push_back_island(&head, Islands[i], i);
    }
    return head;
}
