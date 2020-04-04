#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void alloc_dealloc();
void sel_sort_alg(int list[], int n);
void swap(int *x, int *y);
void sel_sort(int list[], int n);

#define MAX_SIZE 101
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int main() {
    int i, n, temp;
    i = 9;
    n = 4;
    SWAP(i, n, temp);
    printf("%d %d", i, n);

//    int list[MAX_SIZE];
//    printf("Enter the number of numbers to generate: ");
//    scanf("%d", &n);
//    if ( n < 1 || n > MAX_SIZE) {
//        fprintf(stderr, "Improper value of n\n");
//        exit(EXIT_FAILURE);
//    } // if
//
//    for (i = 0; i < n; i++) {
//        // randomly generates numbers
//        list[i] = rand() % 1000;
//        printf("%d ", list[i]);
//    } // for
//
//    sel_sort(list, n);
//    printf("\nSorted array: \n");
//    // print out sorted numbers
//    for (i = 0; i < n; i++)
//        printf("%d ", list[i]);
//    printf("\n");
} // main()

// Program 1.1: Allocation and deallocation of memory
void alloc_dealloc() {
    int i, *pi;
    float f, *pf;
    pi = (int *) malloc(sizeof(int));
    pf = (float *) malloc(sizeof(float));
    *pi = 1024;
    *pf = 3.14;
    printf("an integer = %d, a float = %f\n", *pi, *pf);
    free(pi);
    free(pf);
} // alloc_dealloc()

// Program 1.2: Selection sort algorithm
void sel_sort_alg(int list[], int n) {
    for (int i = 0; i < n; i++) {
        // Examime list[i] to list[n-1] and
        // suppose that the smallest integer is at list[min];

        // Interchange list[i] and list[min]
    } // for
} // sel_sort_alg()

// Program 1.3: Swap function
/*
    int x = 6, y = 2;
    swap(&x, &y);
    printf("%d, %d", x, y);
*/
//void swap(int *x, int *y, int temp) {
//    // both parameters are pointers to ints
//
//    // declares temp as an int and
//    // assigns to it the contents of what x points to
//    temp = *x;
//
//    // stores what y points to into
//    // the location where x points
//    *x = *y;
//
//    // places the contents of temp in
//    // location pointed to by y
//    *y = temp;
//} // swap()

// Program 1.4: Selection sort


/*
    int i, n;
    int list[MAX_SIZE];
    printf("Enter the number of numbers to generate: ");
    scanf("%d", &n);
    if ( n < 1 || n > MAX_SIZE) {
        fprintf(stderr, "Improper value of n\n");
        exit(EXIT_FAILURE);
    } // if

    for (i = 0; i < n; i++) {
        // randomly generates numbers
        list[i] = rand() % 1000;
        printf("%d ", list[i]);
    } // for

    sel_sort(list, n);
    printf("\nSorted array: \n");
    // print out sorted numbers
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
*/
void sel_sort(int list[], int n) {
    int i, j, min, temp;
    for (int i = 0; i < n-1; i++) {
        min = i;
        for (int j = i+1; j < n; j++) {
            if (list[j] < list[min])
                min = j;
            SWAP(list[i], list[min], temp);
        } // for
    } // for
} // sel_sort()

// Program 1.5: Searching a sorted list
