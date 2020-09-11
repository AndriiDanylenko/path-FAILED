#include "findpath.h"
#include "../inc/libmx.h"

island_list *store_create_island(char *name, int number, int island_amount) {
    island_list *head = NULL;
    island_list *island = (island_list *)malloc(sizeof(island_list));

    if (!island)
        return NULL;

    island->name = mx_strdup(name);
    island->number = number;
    island->next = NULL;
    island->previous = NULL;
    island->const_neighbours = (island_list **)malloc(sizeof(island_list *) * (island_amount + 1));
    island->temp_neighbours = (island_list **)malloc(sizeof(island_list *) * (island_amount + 1));

    for (int i = 0; i < island_amount + 1; i++) {
        island->const_neighbours[i] = NULL;
        island->temp_neighbours[i] = NULL;
    }
    
    head = island;
    return head;
}
