#include "queues.h"

#define MAX 50

static void class1();
static void class2();

void enqueueArr(int);
int dequeueArr();
static void displayArr();

int queue_array[MAX];
int rearArr = -1;
int frontArr = -1;

struct QNodeLL {
    int key;
    struct QNodeLL *next;
};

struct QueueLL {
    struct QNodeLL *front, *rear;
};

struct QNodeLL *newNode(int k) {
    struct QNodeLL *temp = (struct QNodeLL *)malloc(sizeof(struct QNodeLL));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

struct QueueLL *createQueue() {
    struct QueueLL *q = (struct QueueLL *)malloc(sizeof(struct QueueLL));
    q->front = q->rear = NULL;
    return q;
}

void enQueueLL(struct QueueLL *q, int k) {
    struct QNodeLL *temp = newNode(k);
    //If queue is empty, then new node is front and rear both
    if(q->rear == NULL) {
        q->front = q->rear = temp;
    }
    else {
        //Add the new node at end of queue and change rear
        q->rear->next = temp;
        q->rear = temp;
    }
}

struct QNodeLL *deQueueLL(struct QueueLL *q) {
    //If queue is empty, return NUll
    if(q->front == NULL)
        return NULL;
    
    //Store previous front and move front one node ahead
    struct QNodeLL *temp = q->front;
    q->front = q->front->next;
    
    //If front becomes NULL, then change rear also to NULL
    if(q->front == NULL)
        q->rear = NULL;
    
    return temp;
}


int queuesClass() {
    class1();
    class2();
    return 0;
}

void class1() {
    struct QueueLL *q = createQueue();
    enQueueLL(q,1);
    enQueueLL(q,2);
    deQueueLL(q);
    deQueueLL(q);
    enQueueLL(q,3);
    enQueueLL(q,4);
    enQueueLL(q,5);
    struct QNodeLL *n = deQueueLL(q);
    if(n != NULL)
        printf("Dequeued item is %d\n",n->key);
    while(n != NULL) {
        free(n);
        n = deQueueLL(q);
    }
    return;
}

void class2() {
    enqueueArr(6);
    enqueueArr(2);
    enqueueArr(7);
    displayArr();
    printf("Element deleted from queue is : %d\n",dequeueArr());
    displayArr();
    printf("Element deleted from queue is : %d\n",dequeueArr());
    displayArr();
    return;
}

void enqueueArr(int data) {
    if(rearArr == MAX - 1)
        printf("Queue overflow\n");
    else {
        if(frontArr == -1)
            frontArr = 0;
            
        rearArr = rearArr+1;
        queue_array[rearArr] = data;
    }
}

int dequeueArr() {
    int num = 0;
    if(frontArr == -1 || frontArr > rearArr) {
        printf("Queue underflow\n");
        return 0;
    }
    else {
        num = queue_array[frontArr];
        frontArr = frontArr + 1;
        return num;
    }
}

void displayArr() {
    int i = 0;
    if(frontArr == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue is :\n");
        for(i = frontArr; i <= rearArr; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}