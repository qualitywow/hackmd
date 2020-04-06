#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void alloc_dealloc();
void sel_sort_alg(int list[], int n);

#define MAX_SIZE 101
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
void swap(int *x, int *y, int temp);
void sel_sort(int list[], int n);

#define COMPARE(x, y) (((x) < (y))? -1: ((x) == (y))? 0: 1)
int compare(int x, int y);
int binserch(int list[], int searchnum, int left, int right);
int binserch_r(int list[], int searchnum, int left, int right);

void perm(char *list, int i, int n);

int main() {

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

// Program 1.2: Selection sort algorithm(pseudo)
void sel_sort_alg(int list[], int n) {
    // for (int i = 0; i < n; i++) {
    //     Examime list[i] to list[n-1] and
    //     suppose that the smallest integer is at list[min];

    //     Interchange list[i] and list[min]
    // } // for
} // sel_sort_alg()

// Program 1.3: Swap function
/*
    int x = 6, y = 2;
    swap(&x, &y);
    printf("%d, %d", x, y);
*/
void swap(int *x, int *y, int temp) {
   // both parameters are pointers to ints

   // declares temp as an int and
   // assigns to it the contents of what x points to
   temp = *x;

   // stores what y points to into
   // the location where x points
   *x = *y;

   // places the contents of temp in
   // location pointed to by y
   *y = temp;
} // swap()

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
        } // for
        SWAP(list[i], list[min], temp);
    } // for
} // sel_sort()

// Program 1.5: Searching a sorted list(pseudo)
/*
    while (there are more integers to check) {
        middle = (left + right) / 2;
        if (searchnum < list[middle])
            right = middle - 1;
        else if (searchnum == list[middle])
            return middle;
        else
            left = middle + 1;
    }
*/

// Program 1.6: Comparison of two integers
/*
#define COMPARE(x, y) (((x) < (y))? -1: ((x) == (y))? 0: 1)
*/
int compare(int x, int y) {
    // compare x and y
    // return -1 for less than, 0 for equal, 1 for greater
    if (x < y) return -1;
    else if (x == y) return 0;
    else return 1;
} // compare()

// Program 1.7: Searching an ordered list
/*
    const int n = 10;
    int list[10] = {1, 2, 8, 12, 13, 14, 17, 23, 37, 42};
    printf("%d\n", binserch(list, 1, 0, n-1));
    printf("%d\n", binserch(list, 37, 0, n-1));
 g   printf("%d\n", binserch(list, 32, 0, n-1));
*/
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
} // binsearch()

// Program 1.8: Recursive implementation of binary search
/*
    const int n = 10;
    int list[10] = {1, 2, 8, 12, 13, 14, 17, 23, 37, 42};
    printf("%d\n", binserch(list, 1, 0, n-1));
    printf("%d\n", binserch(list, 37, 0, n-1));
    printf("%d\n", binserch(list, 32, 0, n-1));
*/
int binserch_r(int list[], int searchnum, int left, int right) {
    // search list[0] <= list[1] <= ... <= list[n-1] for searchnum.
    // Return its position if found
    // Otherwise return -1.

    while (left <= right) {
        int middle = (left + right) / 2;
        switch (COMPARE(list[middle], searchnum)) {
            case -1:
                return binserch_r(list, searchnum, middle+1, right);
            case 0:
                return middle;
            case 1:
                return binserch_r(list, searchnum, left, middle-1);
        }
    }
    return -1;
} // binsearch()

// Program 1.9: Recursive permutation generator
/*
    char list[3] = "123";
    perm(list, 0, 2);
*/
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

// 1.10 Simple arithmetic function
float abc(float a, float b, float c) {
    return a+b+b*c+(a+b-c)/(a+b)+4.00;
} // abc()

// 1.11 Iterative function for summing a list of numbers
float sum(float list[], int n) {
    float tempsum = 0;
    int i;
    for (i = 0; i < n; i++)
        tempsum += list[i];
    return tempsum;
} // sum()


// 1.12 Recursive function for summing a list of numbers
float sum_r(float list[], int n) {
    if (n)
        return sum_r(list, n-1) + list[n-1];
    return 0;
} // sum_r()


// 1.13 Program 1.11 with count statements
float sum(float list[], int n) {
    int count = 0;
    float tempsum = 0;
    count++; // for assignment

    int i;
    for (i = 0; i < n; i++) {
        count++; // for the for loop
        tempsum += list[i];
        count++; // for assignment
    } // for
    count++; // last execution of for loop
    count++; // for return
    return tempsum;
} // sum()

// 1.14 Simple version of Program 1.13
float sum(float list[], int n) {
    int count = 0;
    float tmepsum = 0;
    int i;
    for (i = 0; i < n; i++)
        count += 2;
    count += 3;
} // sum()

// 1.15 Program 1.12 with count statements added
float sum_r(float list[], int n) {
    int count = 0;
    count++; // for if conditional
    if (n) {
        count++; // for return and sum_r() invocation
        return sum_r(list, n-1) + list[n-1];
    } // if

    count++; // for return
    return list[0];
} // sum_r()

// 1.16 Matrix addtion
void add(int a[][MAX_SIZE], int b[][MAX_SIZE], 
         int c[][MAX_SIZE], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            c[i][j] = a[i][j] + b[i][j];
} // add()

// 1.17 Matrix addition with count statements
void add(int a[][MAX_SIZE], int b[][MAX_SIZE], 
         int c[][MAX_SIZE], int rows, int cols) {
    int count = 0;
    int i, j;
    for (i = 0; i < rows; i++) {
        count++; // for i for loop
        for (j = 0; j < cols; j++) {
            count++; // for j for loop
            c[i][j] = a[i][j] + b[i][j];
            count++; // for assigment statement
        } // for
        count++; // last time of j for loop
    } // for

    count++; // last time of i for loop
} // add()

// 1.18 Simplification of Program 1.17
void add(int a[][MAX_SIZE], int b[][MAX_SIZE], 
         int c[][MAX_SIZE], int rows, int cols) {
    int count = 0;
    int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            count += 2;
        } // for
        count += 2;
    } // for
    count++;
} // add()

// 1.19 Printing out a matrix
void printMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
        } // for
        printf("\n");
    } // for
} // printMatrix()

// 1.20: Matrix multiplication function
void mult(int a[][MAX_SIZE], int b[][MAX_SIZE], 
          int c[][MAX_SIZE]) {
    int i, j, k;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            c[i][j] = 0;
            for (k = 0; k < MAX_SIZE; k++) {
                c[i][j] += a[i][k] * b[k][j];
            } // for
        } // for
    } // for
} // mult()

// 1.21 Matrix product function
// a[] rowsa x colsa
// b[] colsa x colsb
// c[] rowsa x colsb
void prod(int a[][MAX_SIZE], int b[][MAX_SIZE], 
          int c[][MAX_SIZE], int rowsa, int colsb, int colsa) {
    int i, j, k;
    for (i = 0; i < rowsa; i++) {
        for (j = 0; j < colsb; j++) {
            c[i][j] = 0;
            for (k = 0; k < colsa; k++) {
                c[i][j] += a[i][k] * b[k][j];
            } // for
        } // for
    } // for
} // prod()

// 1.22: Matrix transposition function
void transpose(int a[][MAX_SIZE]) {
    int i, j, temp;
    for (i = 0; i < MAX_SIZE-1; i++)
        for (j = i+1; j < MAX_SIZE; j++)
            SWAP(a[i][j], a[j][i], temp);
} // transpose()

// Program 1.23: Magic square program
/*
    #include <stdio.h>
    #define MAX_SIZE 15 // maximum size of square

    void main(void) {
        // construct a magic square, iteratively
        int square[MAX_SIZE][MAX_SIZE];
        int i, j, row, column;
        int count;
        int size;

        printf("Enter the size of the square: ");
        scanf("%d", &size);
        // check for inpit errors
        if (size < 1 || size > MAX_SIZE) {
            fprintf(stderr, "Error! Size is out of range\n");
            exit(EXIT_FAILURE);
        } // if
        if (!(size % 2)) {
            fprintf(stderr, "Error! Size is even\n");
            exit(EXIT_FAILURE);
        } // if

        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++)
                square[i][j] = 0;
        } // for

        square[0][(size-1) / 2] = 1; // middle of first row
        // i and j are current position
        i = 0;
        j = (size -1) / 2;
        for (count = 2; count <= size * size; count++) {
            row = (i-1 < 0) ? (size-1) : (i-1); // up
            column = (j-1 < 0) ? (size-1) : (j-1); // left
            if (square[row][column]) // down
                i = (++i) % size;
            else {
                i = row;
                j = (j-1 < 0) ? (size -1) : --j;
            } // else

            square[i][j] = count;
        } // for

        // output the magic square
        printf("Magic Square of size %d: \n\n", size);
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) 
                printf("%5d", square[i][j]);
            printf("\n");
        } // for
        printf("\n\n");
    } // main
*/