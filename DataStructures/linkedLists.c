#include "linkedLists.h"

static void class1();

typedef struct node {
    char data;
    struct node *nextPtr;
} node_t;

typedef node_t *ListNodePtr;

static void insert(ListNodePtr *head, char value);
static void insertAtEnd(ListNodePtr *head, char value);
static void insertAtBeg(ListNodePtr *head, char value);
static char delete(ListNodePtr *head, char value);
static void deleteAtBeg(ListNodePtr *head);
static int isEmpty(ListNodePtr head);
static void printList(ListNodePtr currentPtr);

int linkedListsClass() {
    class1();
    return 0;
}

void class1() {
    ListNodePtr head = NULL;    //initially there are no nodes
    int choice = 0;             //user's choice
    char item = '\0';              //char entered by user
    
    // display menu
    printf("Enter your choice:\n"
        "\t1 to insert an element into the list in alphabetical order.\n"
        "\t2 to insert an element at the end of the list.\n"
        "\t3 to insert an element at the beginning of the list.\n"
        "\t4 to delete an element from the list.\n"
        "\t5 to delete an element from the beginning of the list.\n"
        "\t6 to end.\n");
    
    printf(":: ");
    scanf("%d",&choice);
    
    //loop while user does not choose 3
    while(choice != 6) {
        switch(choice) {
            case 1:
                printf("Enter a character: ");
                scanf("\n%c",&item);
                insert(&head,item); //insert item in list
                printList(head);
                break;
            case 2:
                printf("Enter a character: ");
                scanf("\n%c",&item);
                insertAtEnd(&head,item); //insert item in list
                printList(head);
                break;
            case 3:
                printf("Enter a character: ");
                scanf("\n%c",&item);
                insertAtBeg(&head,item); //insert item in list
                printList(head);
                break;
            case 4: //delete an element
                //if list is not empty
                if(!isEmpty(head)) {
                    printf("Enter character to be deleted: ");
                    scanf("\n%c",&item);
                    
                    //if character is found, remove it
                    if(delete(&head,item)) { //remove item
                        printf("'%c' deleted.\n", item);
                        printList(head);
                    } //end if
                    else {
                        printf("'%c' not found.\n\n",item);
                    } //end else
                } //end if
                else {
                    printf("List is empty.\n\n");
                } //end else
                break;
            case 5: //delete an element at beginning
                //if list is not empty
                if(!isEmpty(head)) {
                    //if character is found, remove it
                    deleteAtBeg(&head);
                    printf("'%c' deleted.\n",item);
                    printList(head);
                } //end if
                else {
                    printf("List is empty.\n\n");
                }
                break;
            default:
                printf("Invalid choice.\n\n");
                //dipslay menu
                /*printf("Enter your choice:\n"
                    "\t1 to insert an element into the list.\n"
                    "\t2 to delete an element from the list.\n"
                    "\t3 to end.\n");*/
                break;
        } //end switch
        printf("? ");
        scanf("%d",&choice);
    } //end while
    printf("End of run.\n");
    
    //free allocated list
    while(head != NULL) {
        deleteAtBeg(&head);
    }
    return;
}

void insert(ListNodePtr *head, char value) {
    ListNodePtr newPtr; //pointer to new node
    ListNodePtr prevPtr;    //pointer to previous node in list
    ListNodePtr currentPtr;
    
    newPtr = malloc(sizeof(node_t));
    
    if(newPtr != NULL) { //is space available
        newPtr->data = value; //place value in node
        newPtr->nextPtr = NULL; //node does not link to another node
        
        prevPtr = NULL;
        currentPtr = *head;
        
        //loop to find the correct location in the list
        while(currentPtr != NULL && value > currentPtr->data) {
            prevPtr = currentPtr;               //walk to..........
            currentPtr = currentPtr->nextPtr;   //........next node
        } //end while
        
        //insert new node at beginnning of list
        if(prevPtr == NULL) {
            newPtr->nextPtr = *head;
            *head = newPtr;
        } //end if
        else { //insert new node between previousPtr and current Ptr
            prevPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        } //end else
    }
    else {
        printf("'%c' not inserted. No memory available.\n",value);
    } //end else
} //end function insert

void insertAtEnd(ListNodePtr *head, char value) {
    ListNodePtr current = *head;
    if(current != NULL) {
        while(current->nextPtr != NULL) {
            current = current->nextPtr;
        }
        //now we can add a new variable
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = value;
        current->nextPtr->nextPtr = NULL;
    }
    else {
        current = malloc(sizeof(node_t));
        current->data = value;
        current->nextPtr = NULL;
        *head = current;
    }
}

void insertAtBeg(ListNodePtr *head, char value) {
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->nextPtr = *head;
    *head = new_node;
}

char delete(ListNodePtr *head, char value) {
    ListNodePtr prevPtr;    //pointer to previous node in list
    ListNodePtr currPtr;    //pointer to current in list
    ListNodePtr tempPtr;    //temporary node pointer
    
    //delete first node
    if(value == (*head)->data) {
        tempPtr = *head; //hold onto node being removed
        *head = (*head)->nextPtr; //de-thread the node
        free(tempPtr); //free the de-threaded
        return value;
    } //end if
    else {
        prevPtr = *head;
        currPtr = (*head)->nextPtr;
        
        //loop to find the correct location in the list
        while(currPtr != NULL && currPtr->data != value) {
            prevPtr = currPtr;          //walk to..........
            currPtr = currPtr->nextPtr; //........next node
        } //end while
        
        //delete node at currPtr
        if(currPtr != NULL) {
            tempPtr = currPtr;
            prevPtr->nextPtr = currPtr->nextPtr;
            free(tempPtr);
            return value;            
        } //end if
    } //end else
    return '\0';
}

void deleteAtBeg(ListNodePtr *head) {
    ListNodePtr tempPtr = NULL; //temp node pointer
    
    if(head == NULL) {
        return;
    }
    else {
        tempPtr = *head;    //hold onto node being removed
        *head = (*head)->nextPtr; //de-thread the node
        free(tempPtr);      // free the de-threaded
    }
}

int isEmpty(ListNodePtr head) {
    return (head == NULL);
}

void printList(ListNodePtr currentPtr) {
    //if list is empty
    if(currentPtr == NULL) {
        printf("List is empty.\n\n");
    } //end if
    else {
        printf("The list is:\n");
        //while not the end of the list
        while(currentPtr != NULL) {
            printf("%c --> ",currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        } //end while
        printf("NULL\n\n");
    } //end else
} //end function printList
