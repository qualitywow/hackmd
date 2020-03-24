#include <iostream>
#include <cmath>
using namespace std;

void SelectionSort(int list[], int n) {
    int min_index;
    for (int i = 0; i < n-1; i++) {
        min_index = i;

        for (int j = i+1; j < n; j++) {
            if (list[min_index] > list[j])
                min_index = j;
        } // for

        swap(list[min_index], list[i]);
    } // for
} // SelectionSort()


// Randomly generate n number
void RanGen(int * list, int n) {
    for (int i = 0; i < n; i++) {
        list[i] = rand() % 1000;
        // cout << list[i] << " ";
    } // for
    // cout << endl;
} // RanGen()


int BinarySearch(int list[], int n, int search_num) {
    for (int i = 0; i < n; i++)
        cout << list[i] << " ";
    cout << endl;
    cout << search_num << endl;

    int l = 0, r = n-1, mid;

    // once they cross, nothing left to check
    while (l <= r) {
        mid = (l+r) / 2;

        if (list[mid] == search_num)
            return mid;
        else if (list[mid] < search_num)
            l = mid + 1;
        else // list[mid] > search_num
            r = mid - 1;
    } // while

    return -1; // cannot find search_num in list
} // BinarySearch()


int BinarySearch_R(int list[], int n, int search_num, int l, int r) {
    if (l > r) return -1;

    int mid = (l + r) / 2;
    if (list[mid] == search_num)
        return mid;
    else if (list[mid] < search_num)
        BinarySearch_R(list, n, search_num, mid+1, r); // l = mid + 1;
    else // list[mid] > search_num
        BinarySearch_R(list, n, search_num, l, mid-1); // r = mid - 1;
} // BinarySearch_R()

// Generate permutation from list[i] to list[n]
void Permutation(int list[], int i, int n) {
    int j;
    if (i == n) {
        /// this "j = 0" make function print from list[0]
        /// if you prefer not to print the items before list[i]
        /// 1. bring a "start" parameter in the function header
        /// 2. call "list" parameter by reference and
        ///    set the pointer point to list[i], but
        ///    the parameter i, n should be shift at the same time.
        for (j = 0; j <= n; j++) {
            cout << list[j] << " ";
        } // for
        cout << endl;
    } // if
    else {
        for (j = i; j <= n; j++) {
            swap(list[i], list[j]);
            Permutation(list, i+1, n);
            swap(list[i], list[j]);
        } // for
    } // else
} // Permutation()

// a: coefficient
// n: n level x function
int Horner(int a[], int n, int x) {
    int i = n-1, pow = 1, ans = 0;
    while (i >= 0) {
        ans += a[i] * pow;
        i = i - 1;
        pow = pow * x;
    } // while

    return ans;
} // Horner()

int Horner_R(int a[], int n, int x, int pow) {
    int ans = 0;
    if (n > 0)
        ans += a[n-1] * pow + Horner_R(a, n-1, x, pow*x);
    return ans;
} // Horner_R()

int main() {
    const int n = 10;
    int list[n] = {1, 2, 3, 4, 5};

    // RanGen(list, n);

    // for (int i = 0; i < n; i++)
    //     cout << list[i] << " ";
    // cout << endl;

    // SelectionSort(list, n);

    // cout << BinarySearch(list, n, 500) << endl;
    // cout << BinarySearch(list, n, 400) << endl;

    // cout << BinarySearch_R(list, n, 500, 0, n-1) << endl;
    // cout << BinarySearch_R(list, n, 400, 0, n-1) << endl;

    // Permutation(list, 0, 2);
    // Permutation(list+2, 0, 2);

    int a[4] = {2, -6, 2, -1};
    cout << Horner(a, 4, 3) << endl;
    cout << Horner_R(a, 4, 3, 1) << endl;
} // main()
