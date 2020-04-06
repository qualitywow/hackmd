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
// (pseudo)
for (int i = 0; i < n; i++) {
    Examime list[i] to list[n-1] and
    suppose that the smallest integer is at list[min];

    Interchange list[i] and list[min]
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
void main(void) {
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
        } // for
        SWAP(list[i], list[min], temp);
    } // for
} // sel_sort()
```

##### Program 1.5: Searching a sorted list
```c=
// (pseudo)
while (there are more integers to check) {
    middle = (left + right) / 2;
    if (searchnum < list[middle])
        right = middle - 1;
    else if (searchnum == list[middle])
        return middle;
    else
        left = middle + 1;
}
```

##### Program 1.6: Comparison of two integers
```c=
#define COMPARE(x, y) (((x) < (y))? -1: ((x) == (y))? 0: 1)
int compare(int x, int y) {
    // compare x and y
    // return -1 for less than, 0 for equal, 1 for greater
    if (x < y) return -1;
    else if (x == y) return 0;
    else return 1;
} // compare()
```

##### Program 1.7: Searching an ordered list
```c=
int binserch(int list[], int searchnum, int left, int right) {
    // search list[0] <= list[1] <= ... <= list[n-1] for searchnum.
    // Return its position if found
    // Otherwise return -1.

    while (left <= right) {
        int middle = (left + right) / 2;
        switch (COMPARE(list[middle], searchnum)) {
            case -1:
                left = middle + 1;
                break;
            case 0:
                return middle;
            case 1:
                right = middle - 1;
                break;
        }
    }
    return -1;
}
```

##### Program 1.8: Recursive implementation of binary search
```c=
int binserch(int list[], int searchnum, int left, int right) {
    // search list[0] <= list[1] <= ... <= list[n-1] for searchnum.
    // Return its position if found
    // Otherwise return -1.

    while (left <= right) {
        int middle = (left + right) / 2;
        switch (COMPARE(list[middle], searchnum)) {
            case -1:
                return binserch(list, searchnum, middle+1, right);
            case 0:
                return middle;
            case 1:
                return binserch(list, searchnum, left, middle-1);
        }
    }
    return -1;
} // binsearch()
```

##### Program 1.9: Recursive permutation generator
void perm(char *list, int i, int n) {
    // generate all the permutations of list[i] to list[n]
    int j, temp;
    if (i == n) {
        for (j = 0; j <= n; j++)
            printf("%c", list[j]);
        printf("\n");
    } // if
    else {
        for (j = i; j <= n; j++) {
            SWAP(list[i], list[j], temp);
            perm(list, i+1, n);
            SWAP(list[i], list[j], temp);
        } // for
    } // else
} // perm()
