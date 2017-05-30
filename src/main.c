#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "list.h"

void disp(void *data)
{
    int a = *(int*)data;
    printf("%d\n", a);
}

void free__(void *data)
{
    (void)data;
}

int comp(void *d1, void *d2){
    int a = *(int*)d1;
    int b = *(int*)d2;
    
    return (a - b);
}

int main(int ac, char **av) {
    int tab[20];
    t_list *list;

    srand(time(NULL));

list = NULL;
    int i = 0;
    while (i < 20) {
        tab[i] = rand() % 255;
        list = list_push_back(list, list_new_node(&tab[i], NULL, NULL));
        ++i;
    }

    printf("before - - - - - - -\n");
    list_display(list, &disp);
    printf("after - - - - - - -\n");
    list = list_sort(list, &comp);
    list_display(list, &disp);
    
    list_free(list, &free__);
    return (0);
}