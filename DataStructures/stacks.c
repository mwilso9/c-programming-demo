#include "stacks.h"

#define MAXSIZE 5

static void class1();
static void class2();

static void push(int);
static void pop();
static int peek();
static int isEmpty();
static void display();

static void pushArr(int);
static int popArr();
static void displayArr();

typedef struct node {
    int data;
    struct node* link;
} node_t;

typedef node_t *nodePtr;

typedef struct stack {
    int stk[MAXSIZE];
    int stktop;
} STACK;

nodePtr top = NULL;
STACK s;

void push(int data) {
    nodePtr temp = (nodePtr) malloc(sizeof(node_t));
    if(temp != NULL) {
        temp->data = data;
        temp->link = top;
        top = temp;
    }
}

int isEmpty() {
    return (top == NULL);
}

void pop() {
    nodePtr temp = NULL;
    if(top != NULL) {
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

int peek() {
    return top->data;
}

void display() {
    nodePtr temp;
    if(top != NULL) {
        temp = top;
        while(temp != NULL) {
            printf("%d:\n",temp->data);
            temp=temp->link;
        }
    }
}

int stacksClass() {
    class1();
    class2();
    return 0;
}

void class1() {
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    
    pop();
    pop();
    display();
    
    if(!isEmpty()) peek();
    return;
}

void class2() {
    s.stktop = -1;
    pushArr(4);
    pushArr(8);
    pushArr(10);
    displayArr();
    
    printf("popped element is = %d\n",popArr());
    displayArr();

    return;
}

void pushArr(int num) {
    if(s.stktop == (MAXSIZE-1)) {
        printf("Stack is full\n");
        return;
    }
    else {
        s.stktop = s.stktop+1;
        s.stk[s.stktop] = num;
    }
    return;
}

int popArr() {
    int num = 0;
    if(s.stktop == -1) {
        printf("Stack is empty\n");
        return(s.stktop);
    }
    else {
        num = s.stk[s.stktop];
        s.stktop = s.stktop-1;
    }
    return num;
}

void displayArr() {
    int i = 0;
    if(s.stktop == -1) {
        printf("Stack is empty\n");
        return;
    }
    else {
        printf("\nThe status of the stack is \n");
        for(i = s.stktop; i >= 0; i--) {
            printf("%d:\n",s.stk[i]);
        }
    }
    printf("\n");
}