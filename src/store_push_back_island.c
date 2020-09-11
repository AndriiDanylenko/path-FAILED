#include "findpath.h"
#include "../inc/libmx.h"

// static int island_amount(island_list *head) {
//     int counter = 0;
    
//     if (!head)
//         return 0;

//     island_list *current = head;

//     while(current) {
//         current = current->next;
//         counter++;
//     }
//     return counter;
// }

void store_push_back_island(island_list **head, char *name, int number, int island_amount) {
    if (!*head && head) {
        *head = store_create_island(name, number, island_amount);
        return;
    } 
    
    island_list *current_island = *head;
    island_list *back_island = store_create_island(name, number, island_amount);

    if (!back_island)
        return;

    while(current_island->next != NULL) {
        current_island = current_island->next;
    }
    back_island->previous = current_island;
    current_island->next = back_island;
}
