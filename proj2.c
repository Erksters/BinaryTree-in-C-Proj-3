#include <stdio.h>
#include "io.h"
#include "Bst.h"
#include <ctype.h>
#include <stdlib.h>


/*
 * Description: This is the Main function to be run
 * Input: None
 * Output: None
 */
int main() {
    char UXInput = 'Z';
    UXInput = toupper(printOptions(UXInput));
    int value = 0;
    node * newTree = malloc(sizeof(node));
    newTree ->value = 0;
    newTree ->leftchild = NULL;
    newTree ->rightchild = NULL;
    while (UXInput != 'Q'){

        //Call insert function here
        if(UXInput == 'I'){
            value = printInsert(value);
            Insert(value,newTree);
        }

        //Call Search method here
        if(UXInput == 'S'){
            value = printSearch(value);
            if(SearchTree(value, newTree) == 1){
                printf("%d is in the Tree!\n", value);
            } else {
                printf("%d is not in the Tree.\n", value);
            }
        }

        //Call Traverse method here
        if(UXInput == 'T'){
            printALL(newTree);
            printf("\n");
        }

        UXInput = toupper(printOptions(UXInput));
    }
    printQuit();
    free(newTree);
    return 0;
}
