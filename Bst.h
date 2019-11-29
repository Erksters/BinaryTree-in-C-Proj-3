#include <stdio.h>
#include <stdlib.h>

//This is my Bst Structure. It will hold pointer to its leftchld, rightchild, and a Value for itself.
typedef struct Bst{
    struct Bst *leftchild;
    struct Bst *rightchild;
    int value;
}node;

//Methods for the Bst.
void Insert(int Value , node * );
int SearchTree(int number, node * root);
void printALL(node * node);


//This method is able to traverse the tree beginning with the root.
//If the value is greater than the roots value it will first check if the root's rightchild exists.
//If the child does not exist, simply place the temporary node there. otherwise recursively check further into the branch.
//Same goes for left side of the Bst
void Insert(int Value, node * root){
    if (root->value == 0){
        root->value = Value;
    }
    else
    {
        if (Value < root->value){
            if( root->leftchild != NULL){
                Insert(Value, root->leftchild);
            }
            else{
                root->leftchild = malloc(sizeof(node));
                root->leftchild->value = Value;
                root->leftchild->leftchild = NULL;
                root->leftchild->rightchild = NULL;
            }
        }
        else{
            if(Value > root->value){
                if( root->rightchild != NULL){
                    Insert(Value, root->rightchild);
                }
                else{
                    root->rightchild = malloc(sizeof(node));
                    root->rightchild->value = Value;
                    root->rightchild->leftchild = NULL;
                    root->rightchild->rightchild = NULL;
                }
            }
        }
    }
}


//This method will search through the tree recursively until the value is found
//Otherwise it will return a '0' to indicate the value was not found A.K.A 'false'
//Input: int number , node * root == Root of the tree
//Output: 1 == True , 0 == False int
int SearchTree(int number, node * root){
    if(root->value == number){
        return 1;
    }
    else if(root->rightchild != 0){
        if(number > root->value){
            return SearchTree(number,root->rightchild);
        }

    } else if (root->leftchild != 0){
        if(number < root ->value){
            return SearchTree(number, root->leftchild);
        }
    }
    else{
        return 0;
    }
}

//This method is straight from 300. We will search on the leftchildren First and then search the right periodically.
// Input a Root of tree
// Output All the numbers found within tree
void printALL(node * node)
{
    if (node == NULL)
        return;
    if (node->leftchild != NULL)
        printALL(node->leftchild);
    if (node != NULL)
        printf("%d ", node->value);
    if (node->rightchild != NULL)
        printALL(node->rightchild);

}