#include <stdio.h>
#include <malloc.h>
#include "list_utils.h"

void printList(List* list) {
    //goto first item
    while (hasPrevious(list)) {
        gotoPrevious(list);
    }

    printf("\nindex: %d, size: %d\nvalues:\n", list->index, list->size);
    for (int i = 0; hasNext(list); ++i) {
        gotoNext(list);
        printf("%d at %d: %d\n", i, list->index, *(int*) getValue(list));
    }
}

//this is a quick demonstration of how to use linked lists with list_utils
int main() {
    //create new list
    List* list = createList();

    //fill in values 42, 13, 21, 64, 117 into List
    int ar[] = {42, 13, 21, 64, 117};
    for (int i = 0; i < 5; ++i) {
        push(list, (void*) &ar[i]);
    }

    printList(list);

    //remove last element from list
    pop(list);
    printf("\nremoved item at last index\n");

    //add element to list at index 2 (allocated in heap)
    int* i = malloc(sizeof(int));
    *i = 1969;
    pushAtIndex(list, 2, (void*) i);
    printf("\nadded item at index 2\n");

    printList(list);

    //remove element at index 1
    popAtIndex(list, 1);
    printf("\nremoved item at index 1\n");

    printList(list);

    //print value at index 0
    gotoIndex(list, 0); //alternatively the listpointer can be moved with 'gotoNext' and 'gotoPrevious'
    printf("\nvalue at index 0 is %d\n", *(int*) getValue(list));

    //safely delete list
    free(i); //memory allocated with malloc still meeds to be freed manually
    deleteList(list);

    return 0;
}