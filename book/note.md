# Fundamentals of Data Structures in C
###### tags: `CSIE`

##### Program 1.1: Allocation and deallocation of memory
```c=
int i, *pi;
float f, *pf;
i = (int *) malloc(sizeof(int));
f = (float *) malloc(sizeof(float));
*pi = 1024;
*pf = 3.14;
printf("an integer = %d, a float = %f\n, *pi, *pf");
free(pi);
free(pf);
```

##### Program 1.2: Selection sort algorithm
```c=
for (int i = 0; i < n; i++) {
    // Examime list[i] to list[n-1] and
    // suppose that the smallest integer is at list[min];

    // Interchange list[i] and list[min]
} // for
```

##### Program 1.3: Swap function
```c=
void swap(int *x, int *y) { 
    // both parameters are pointers to ints

    // declares temp as an int and 
    // assigns to it the contents of what x points to
    int temp = *x;

    // stores what y points to into
    // the location where x points
    *x = *y;

    // places the contents of temp in
    // location pointed to by y
    *y = temp;
} // swap()

int a, b; 

// a, b are the value that store at address &a, &b respectively.
// We can swap value stored at address &a, &b with the statement:
swap(&a, &b);

// MACRO version of swap()
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
```
readability: function > macro
functionality: macro version works with any data type

##### Program 1.4: Selection sort
```c=
#include <stdio.h>
#include <math.h>
#define MAX_SIZE 101
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
void sort(int [], int); /* selection sort */
void main() {
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
} // main()

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
```