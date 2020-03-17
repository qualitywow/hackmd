# Fundamentals of Data Structures in C
###### tags: `CSIE`

##### Program 1.1: Allocation and deallocation of memory
```=c
// Program 1.1
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
```=c

```

##### Program 1.3: Swap function
```=c
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
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
