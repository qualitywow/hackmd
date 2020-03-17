#include <iostream>
#include <cmath>
using namespace std;


void selection_sort(int list[]) {
    int min_index;
    for (int i = 0; i < n-1; i++) {
        min_index = i;
        for (int j = i+1; j < n; j++) {
            if (list[min_index] > list[j]) min_index = j;
        }
        swap(list[min_index], list[i]);
    }
}


// Program 1.3: Swap function
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
} // swap

// Random generate n number
void ran_gen(int * list, int n) {
    list = (int *) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        list[i] = rand() % 1000;
        cout << list[i] << " ";
    } // for
    cout << endl;
} // ran_gen()
/*
sudo dpkg -i *17.12*.deb
sudo apt-get install -f
*/
int main() {
    // int list[10] = {1, 3, 5, 2, 7, 4, 8, 6, 0, 9};

}


