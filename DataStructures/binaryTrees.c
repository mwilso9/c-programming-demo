#include "binaryTrees.h"
#include <time.h>

static void class1();

/* inorder traversal = left, root, right
 * preorder traversal = left, right, root
 * postorder traversal = root, left, right
 */

typedef struct treeNode {
    int data;                   // node value
    struct treeNode *leftPtr;   // pointer to left subtree
    struct treeNode *rightPtr;  // pointer to right subtree
} treeNode_t;

typedef treeNode_t * treeNodePtr;

void insertNode(treeNodePtr *treePtr, int value);
void inOrder(treeNodePtr treePtr);
void preOrder(treeNodePtr treePtr);
void postOrder(treeNodePtr treePtr);

int binaryTreeClass() {
    class1();
    return 0;
}

void class1() {
    int i = 0; //counter to loop from 1-10
    int item = 0; // variable to hold rand values
    treeNodePtr rootPtr = NULL; //tree, initially empty
    //int num[] = {5,6,13,11,7,1,14,5,2,3};
    
    srand(time(NULL));
    printf("The numbers being placed in the tree are:\n");
    
    //insert rand vals between 0 and 14 in tree
    for(i = 1; i <= 10; i++) {
        item = rand() % 15;
        printf("%3d",item);
        insertNode(&rootPtr,item);
        //printf("%3d",num[i-1]);
        //insertNode(&rootPtr,num[i-1]);
    }
    
    printf("\n\nThe preorder traversal is:\n");
    preOrder(rootPtr);
    printf("\n\nThe inorder traversal is:\n");
    inOrder(rootPtr);
    printf("\n\nThe postorder traversal is:\n");
    postOrder(rootPtr);
    return;
}

void insertNode(treeNodePtr *treePtr, int value) {
    if(*treePtr == NULL) { //tree empty
        *treePtr = malloc (sizeof(treeNode_t));
        //if memory was allocated then assign data
        if(*treePtr == NULL) {
            printf("%d not inserted. No memory available.\n",value);
        }
        (*treePtr)->data = value;
        (*treePtr)->leftPtr = NULL;
        (*treePtr)->rightPtr = NULL;
    }
    else { //tree not empty
        if(value < (*treePtr)->data) {
            insertNode(&((*treePtr)->leftPtr),value);
        }
        else if(value > (*treePtr)->data) {
            insertNode(&((*treePtr)->rightPtr),value);
        }
        else {
            printf("dup");
        }
    }
}

void inOrder(treeNodePtr treePtr) {
    if(treePtr!=NULL) {
        inOrder(treePtr->leftPtr);
        printf("%3d",treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

void preOrder(treeNodePtr treePtr) {
    if(treePtr!=NULL) {
        printf("%3d",treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }    
}

void postOrder(treeNodePtr treePtr) {
    if(treePtr!=NULL) {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d",treePtr->data);
    }    
}