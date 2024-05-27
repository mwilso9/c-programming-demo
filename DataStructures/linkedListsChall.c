#include "linkedListsChall.h"

//#define DEBUG
#define FAILURE 0
#define SUCCESS 1

static void challenge1();

typedef struct inode {
    int data;
    struct inode *nextPtr;
} inode_t;

typedef inode_t *ListINodePtr;

static int insertAtFirst(ListINodePtr*, const int);
static int insertAtLast(ListINodePtr*, const int);
static int insertAtPosition(ListINodePtr*, const int, const int);
static int deleteFromPosition(ListINodePtr*, const int);
static int updateValue(const ListINodePtr*, const int, const int);
static int searchElementInList(const ListINodePtr, const int);
static int isEmpty(const ListINodePtr);
static void displayList(ListINodePtr);

int linkedListsChallenge() {
    challenge1();
    return 0;
}

void challenge1() {
    ListINodePtr head = NULL;    //initially there are no nodes
    int choice = 0, val = 0, pos = 0;       //values entered by user
    int result = 0; //function return values, success or failure
    
    do {
    // display menu
    printf("\n----------------------------------\n"
           "Operations on a linked list\n"
           "----------------------------------\n"
           "1.Insert node at beginning\n"           //insert value before first position
           "2.Insert node at end\n"                 //insert value after last position
           "3.Insert node at specific position\n"   //insert value at entered position, position is 1-based
           "4.Delete node from any position\n"      //delete value at entered position, position is 1-based
           "5.Update node value\n"                  //update first instance of entered value to new entered value
           "6.Search element in linked list\n"      //find entered value in list and return position, position is 1-based
           "7.Display list\n"                       //display list
           "8.Exit\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "Enter your choice:\n");
    scanf("%d",&choice);
    
    //loop while user does not choose 3
        switch(choice) {
            case 1: //insert element at start
                printf("Enter the value for the node: ");
                scanf("\n%d",&val);
                if(insertAtFirst(&head,val)) //insert item in list
                    printf("Element inserted.\n");
                else
                    fprintf(stderr,"Failed to insert at beginning.\n");
                #ifdef DEBUG
                displayList(head);
                #endif
                break;
            case 2: //insert element at end
                printf("Enter the value for the node: ");
                scanf("\n%d",&val);
                if(insertAtLast(&head,val)) //insert item in list
                    printf("Element inserted.\n");
                else
                    fprintf(stderr,"Failed to insert at end.\n");
                #ifdef DEBUG
                displayList(head);
                #endif
                break;
            case 3: //insert an element based on position
                printf("Enter the value for the node: ");
                scanf("\n%d",&val);
                printf("Enter the position: ");
                scanf("\n%d",&pos);
                if(insertAtPosition(&head,val,pos)) //insert item in list
                    printf("Element inserted.\n");
                else
                    fprintf(stderr,"Position %d not found.\n",pos);
                #ifdef DEBUG
                displayList(head);
                #endif
                break;
            case 4: //delete an element based on position
                //if list is not empty
                if(!isEmpty(head)) {
                    printf("Enter position of the value to be deleted: ");
                    scanf("\n%d",&pos);
                    
                    //if position exists, remove it
                    if(deleteFromPosition(&head,pos)) { //remove item
                        printf("Element deleted.\n");
                        #ifdef DEBUG
                        displayList(head);
                        #endif
                    } //end if
                    else {
                        fprintf(stderr,"Position %d not found.\n",pos);
                    } //end else
                } //end if
                else {
                    fprintf(stderr,"List is empty.\n");
                } //end else
                break;
            case 5: //update value
                //if list is not empty
                if(!isEmpty(head)) {
                    printf("Enter the value to be updated: ");
                    scanf("\n%d",&val);
                    printf("Enter the new value: ");
                    scanf("\n%d",&pos);
                    //if value is found, update it
                    if(updateValue(&head,val,pos))
                        printf("Element updated.\n");
                    else
                       fprintf(stderr,"Element %d not found.\n",val);
                    #ifdef DEBUG
                    displayList(head);
                    #endif
                } //end if
                else {
                    fprintf(stderr,"List is empty.\n");
                }
                break;
            case 6:
                //if list is not empty
                if(!isEmpty(head)) {
                    printf("Enter the value to search: ");
                    scanf("\n%d",&val);
                    //if value is found, update it
                    result = searchElementInList(head,val);
                    if(result)
                        printf("Element %d found at position %d\n",val,result);
                    else
                        fprintf(stderr,"Element %d not found.\n",val);
                    #ifdef DEBUG
                    displayList(head);
                    #endif
                } //end if
                else {
                    fprintf(stderr,"List is empty.\n");
                }            
                break;
            case 7:
                if(!isEmpty(head))
                    displayList(head);
                else
                    fprintf(stderr,"List is empty.\n");
                break;
            case 8:
                break;
            default:
                fprintf(stderr,"Invalid choice.\n");
                break;
        } //end switch
    } while(choice != 8); //end while
    //free allocated list
    while(head != NULL) {
        deleteFromPosition(&head,1);
        #ifdef DEBUG
        displayList(head);
        #endif
    }
    return;
}

int insertAtPosition(ListINodePtr *head, const int value, const int position) {
    ListINodePtr newPtr = NULL;    //pointer to new node
    ListINodePtr prevPtr = NULL;   //pointer to previous node in list
    ListINodePtr currentPtr = NULL;
    int count = 1;
    
    newPtr = malloc(sizeof(inode_t));
    if(newPtr == NULL) { //no space available
        fprintf(stderr,"Element %d not inserted. No memory available.\n",value);
        return FAILURE;
    }
    newPtr->data = value; //place value in node
    newPtr->nextPtr = NULL; //node does not link to another node

    //insert at first position
    if(count == position) {
        newPtr->nextPtr = *head;
        *head = newPtr;
        return SUCCESS;
    }    
    prevPtr = NULL;
    currentPtr = *head;
    //loop to find the correct location in the list
    while(currentPtr != NULL && count < position) {
        prevPtr = currentPtr;               //walk to..........
        currentPtr = currentPtr->nextPtr;   //........next node
        count++;
    } //end while
    
    //list is empty or position is larger than list
    if((prevPtr == NULL) || (count != position)) {
        return FAILURE;
    } //end if
    else { //insert new node between previousPtr and current Ptr
        prevPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
        return SUCCESS;
    } //end else

} //end function insert

int insertAtLast(ListINodePtr *head, const int value) {
    ListINodePtr current = *head;
    if(current != NULL) {
        while(current->nextPtr != NULL) {
            current = current->nextPtr;
        }
        //now we can add a new variable
        current->nextPtr = malloc(sizeof(inode_t));
        if(current->nextPtr == NULL) {
            fprintf(stderr,"Element %d not inserted. No memory available.\n",value);
            return FAILURE;
        }
        else {
            current->nextPtr->data = value;
            current->nextPtr->nextPtr = NULL;
            return SUCCESS;
        }
    }
    else {
        current = malloc(sizeof(inode_t));
        if(current == NULL) {
            fprintf(stderr,"Element %d not inserted. No memory available.\n",value);
            return FAILURE;
        }
        else {
            current->data = value;
            current->nextPtr = NULL;
            *head = current;
            return SUCCESS;
        }
    }
}

int insertAtFirst(ListINodePtr *head, const int value) {
    ListINodePtr new_node = malloc(sizeof(inode_t));
    if(new_node == NULL) {
        fprintf(stderr,"Element %d not inserted. No memory available.\n",value);
        return FAILURE;
    }
    else {
        new_node->data = value;
        new_node->nextPtr = *head;
        *head = new_node;
        return SUCCESS;
    }
}
int deleteFromPosition(ListINodePtr *head, const int position) {
    ListINodePtr prevPtr;    //pointer to previous node in list
    ListINodePtr currPtr;    //pointer to current in list
    ListINodePtr tempPtr;    //temporary node pointer
    int count = 1;
    
    //delete first node
    if(count == position) {
        tempPtr = *head; //hold onto node being removed
        *head = (*head)->nextPtr; //de-thread the node
        free(tempPtr); //free the de-threaded
        return SUCCESS;
    } //end if
    else {
        prevPtr = *head;
        currPtr = (*head)->nextPtr;
        count++;
        
        //loop to find the correct location in the list
        while(currPtr != NULL && count < position) {
            prevPtr = currPtr;          //walk to..........
            currPtr = currPtr->nextPtr; //........next node
            count++;
        } //end while
        
        //delete node at currPtr
        if((currPtr != NULL) && (count == position)) {
            tempPtr = currPtr;
            prevPtr->nextPtr = currPtr->nextPtr;
            free(tempPtr);
            return SUCCESS;
        } //end if
        else {
            return FAILURE;
        }
    } //end else
}

int updateValue(const ListINodePtr *head, const int orig_val, const int new_val) {
    ListINodePtr currPtr = NULL;
    
    //update first node
    if(orig_val == (*head)->data) {
        (*head)->data = new_val;
        return SUCCESS;
    } //end if
    else {
        currPtr = (*head)->nextPtr;
        
        //loop to find the correct location in the list
        while(currPtr != NULL && orig_val != currPtr->data) {
            currPtr = currPtr->nextPtr; //walk to next node
        } //end while
        
        //update node at currPtr
        if(currPtr != NULL) {
            currPtr->data = new_val;
            return SUCCESS;
        } //end if
        else {
            return FAILURE;
        }
    } //end else
}

static int searchElementInList(const ListINodePtr head, const int val) {
    ListINodePtr currPtr = NULL;
    int position = 1;
    
    //update first node
    if(val == head->data) {
        return position;
    } //end if
    else {
        currPtr = head->nextPtr;
        position++;
        
        //loop to find the correct location in the list
        while(currPtr != NULL && val != currPtr->data) {
            currPtr = currPtr->nextPtr; //walk to next node
            position++;
        } //end while
        
        //update node at currPtr
        if(currPtr != NULL) {
            return position;
        } //end if
        else {
            return FAILURE;
        }
    } //end else
}

int isEmpty(const ListINodePtr head) {
    return (head == NULL);
}

void displayList(ListINodePtr currentPtr) {
    //if list is empty
    if(currentPtr == NULL) {
        fprintf(stderr,"List is empty.\n");
    } //end if
    else {
        //while not the end of the list
        while(currentPtr != NULL) {
            printf("%d\t",currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        } //end while
    } //end else
}
