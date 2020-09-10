#include "findpath.h"
#include "../inc/libmx.h"

island_list *store_create_island(char *name, int number) {
    island_list *head = NULL;
    island_list *island = (island_list *)malloc(sizeof(island_list));

    if (!island)
        return NULL;

    island->name = mx_strdup(name);
    island->number = number;
    island->next = NULL;
    island->previous = NULL;
    head = island;
    return head;
}
