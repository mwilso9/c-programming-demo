#include "functionPointers.h"
#include <stdlib.h>

static void class1();
static void challenge1();
int somedisplay();

void funct1(int);
void funct2(int);
typedef void FuncType(int);

int add(int,int);
int subtract(int,int);
int multiply(int,int);
int divide(int,int);
int quit(int,int);
int error(int,int);
typedef int (*FuncArrType)(int,int);
int *performOp(int*,int*,int,FuncArrType);
void display(int*,int);

int functionPointersClass() {
    class1();
    return 0;
}

int functionPointersChallenge() {
    challenge1();
    return 0;
}

int somedisplay() {
    printf("--Displaying some text--\n\n");
    return 0;
}

void funct1(int arg) {
    printf("funct1 got an argument of %d\n",arg);
}

void funct2(int arg) {
    printf("funct2 got an argument of %d\n",arg);
}

void class1() {
    // example declaration: int (*pfunction)(int);
    
    int (*func_ptr) ();
    FuncType *func_ptr2 = NULL;
    
    func_ptr = somedisplay;
    printf("Address of function somedisplay is %p\n", func_ptr);
    (*func_ptr)();
    
    func_ptr2 = funct1;
    (*func_ptr2)(100);
    func_ptr2 = funct2;
    (*func_ptr2)(200);

    //example use of function pointers is compare function parameter for standard qsort function:
    //
    //void qsort(void *base, size_t num_elements, size_t element_size, int (*compare)(void const *,void const *));
    //compare function must return <0, 0, or >0 for 1st<2nd, 1st=2nd, and 1st>2nd respectively
    
    return;
}

void challenge1() {
    char entry[2] = {'\0','\0'};
    int choice = 0;
    int arr1[] = {10, 20, 30, 40, 50,  60,  70, 80, 90, 100};
    int arr2[] = {38, 27, 87, 63, 59, 223, 132,  1, 19,   7};
    int *result = NULL;
    unsigned int size = 0;
//    FuncArrType chosenFunc[] = {add,subtract,multiply,divide};
    FuncArrType chosenFunc[] = {&add,&subtract,&multiply,&divide};
    
    size = (sizeof(arr1) < sizeof(arr2) ? sizeof(arr1) : sizeof(arr2))/sizeof(int);
    
    while(1) {
        printf("Which operation do you want to perform?\n"
            "1.Add\n"
            "2.Subtract\n"
            "3.Multiply\n"
            "4.Divide\n"
            "5.None ...\n"
            "Enter choice: ");

        do {
            scanf("%c",&(entry[0]));
        } while(entry[0] == '\n');

        choice = atoi(entry);

        if(choice == 5) {
            printf("\nQuitting...\n\n");
            break;
        }
        else if((choice < 1) || (choice > 5)) {
            printf("\nInvalid choice. Try again...\n\n");
            continue;
        }
        else {
            result = performOp(arr1,arr2,size,chosenFunc[choice - 1]);
            //result = performOp(arr1,arr2,size,(*(chosenFunc[choice - 1])));
            display(result,size);
        }
    }
    
    if(result != NULL)
        free(result);
        
    return;
}
int *performOp(int *a, int *b, int size, FuncArrType operation) {
    int *result = NULL;

    result = (int *)malloc(size*sizeof(int));

    for(int i = 0; i < size; i++) {
        result[i] = operation(a[i],b[i]);
        //result[i] = (*operation)(a[i],b[i]);
    }
    return result;
}
void display(int *arr, int size) {
    int i = 0;
    
    if(arr == NULL) {
        printf("Print Error\n");
        return;
    }
    printf("\nThe Results are ...\n");
    for(i = 0; i < size; i++) {
        printf("\t%d",arr[i]);
    }
    printf("\n\n");
}

int add(int a,int b)      { return a+b; }
int subtract(int a,int b) { return a-b; }
int multiply(int a,int b) { return a*b; }
int divide(int a,int b)   { return a/b; }
