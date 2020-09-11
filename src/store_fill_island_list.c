#include "../inc/libmx.h"
#include "findpath.h"

static void connect(island_list *current_island, int needed_island, island_list *head);

island_list *fill_island_list(char **Islands, int **WayMatrix) {
    island_list *head = NULL;

    //создаю двусвязный список,(острова расположены последовательно) нумерую каждый остров и добавляю его имя
    int island_amount = 0;
    for (int i = 0; Islands[i] != NULL; i++, island_amount++); 
    for (int i = 0; Islands[i] != NULL; i++) {
        store_push_back_island(&head, Islands[i], i, island_amount - 1);
    }
    //----------------------------
    island_list *current = head;
    
    //создаю связи (быстрый доступ к соседям) между островами в const_neighbours && temp_neighbours
    for (int i = 0; WayMatrix[i] != NULL && current; i++) {
        for (int j = 0; WayMatrix[j] != NULL; j++) {
            if (WayMatrix[i][j] == 2147483647) {
                current->const_neighbours[j] = NULL;
                current->temp_neighbours[j] = NULL;
            }
            else {
                connect(current, j, head);   
            }
        }
        current = current->next;
    }
    return head;
}

static void connect(island_list *current_island, int needed_island, island_list *head) {
    island_list *tmpcur = current_island;
    island_list *tmphead = head;

    if (current_island->number > needed_island) {
        if ((current_island->number + head->number) / 2 >= needed_island) {
            // write(1, "Headnext", mx_strlen("Headnext"));
            // mx_printint(needed_island);
            // mx_printchar('\n');
            
            while (tmphead->number != needed_island)
                tmphead = tmphead->next;
            current_island->temp_neighbours[needed_island] = tmphead;
            current_island->const_neighbours[needed_island] = tmphead;
            // mx_print_chars('!', 5);
            // mx_printchar('\n');
        }
        else {
            // write(1, "CurPrevious", mx_strlen("CurPrevious"));
            // mx_printint(needed_island);
            // mx_printchar('\n');

            while(tmpcur->number != needed_island) {
                tmpcur = tmpcur->previous;
                // printf("+|");
            }
            current_island->temp_neighbours[needed_island] = tmpcur;
            current_island->const_neighbours[needed_island] = tmpcur;
            // mx_print_chars('?', 5);
            // mx_printchar('\n');
        }
    }
    else if (current_island->number < needed_island) {
        // write(1, "CurNext", mx_strlen("CurNext"));
        // mx_printint(needed_island);
        // mx_printchar('\n');
        while (tmpcur->number != needed_island) 
            tmpcur = tmpcur->next;
        current_island->temp_neighbours[needed_island] = tmpcur;
        current_island->const_neighbours[needed_island] = tmpcur;
        // mx_print_chars('.', 5);
        // mx_printchar('\n');
    }
}
