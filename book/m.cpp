#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
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

void PrintVecVecBool(vector<vector<bool>> bv) {
    for (int i = 0; i < bv.size(); i++) {
        for (int j = 0; j < bv[i].size(); j++) {
            cout << bv[i][j] << " ";
        } // for
        cout << endl;
    } // for
} // PrintVecVecBool()

void BoolCombination(int i, int n, vector<vector<bool>> & ans) {
    if (i == n)
        return;
    else if (i == 0) {
        vector<bool> v;
        v.push_back(true);
        ans.push_back(v);

        v.clear();
        v.push_back(false);
        ans.push_back(v);

        BoolCombination(i+1, n, ans);
    } // else if
    else { // (i < n)
        vector<vector<bool>> new_ans;
        for (int j = 0; j < ans.size(); j++) {
            ans[j].push_back(true);
            new_ans.push_back(ans[j]);
            ans[j].pop_back();
            ans[j].push_back(false);
            new_ans.push_back(ans[j]);
        } // for
        // PrintVecVecBool(new_ans);
        ans = new_ans;
        delete &new_ans;
        BoolCombination(i+1, n, ans);
    } // else

} // BoolCombination()

void PrintAscending(int x, int y, int z) {
    int arr[3] = {x, y, z};
    SelectionSort(arr, 3);
    for (int i = 0; i < 3; i++)
        cout << arr[i] << " ";
    cout << endl;
} // PrintAscending()

bool IsSumOfDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i < n; i++)
        if (n % i == 0)
            divisors.push_back(i);

    int k = 0;
    for (int i = 0; i < divisors.size(); i++)
        k += divisors[i];

    if (k == n)
        return true;
    else
        return false;
} // IsSumOfDivisors()

int Factorial(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans *= i;
    return ans;
} // Factorial()

int Factorial_R(int n) {
    int ans = 1;
    if (n == 0)
        return ans;
    else
        ans = n * Factorial_R(n-1);
} // Factorial_R()

int Fibonacci(int n) {
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);
    for (int i = 2; i <= n; i++)
        fib.push_back(fib[i-1]+fib[i-2]);
    return fib[n];
} // Fibonacci()

int Fibonacci_R(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else
        return Fibonacci_R(n-1) + Fibonacci_R(n-2);
} // Fibonacci_R()

int BinomialCoefficient(int n, int k) {

} // BinomialCoefficient()

int BinomialCoefficient_R(int n, int k) {
    int ans = 0;
    if (k == 0 || k == n) return 1;
    else {
        ans = ans
            + BinomialCoefficient_R(n-1, k)
            + BinomialCoefficient_R(n-1, k-1);
    } // else

    return ans;
} // BinomialCoefficient_R()

class NaturalNumber {
    public:
        int nn;

        NaturalNumber(int n) {
            nn = n;
        } // Constructor

        NaturalNumber Zero() {
            nn = 0;
        } // Zero()

        bool IsZero(NaturalNumber x) {
            if (x.nn == 0) return true;
            else return true;
        } // isZero()

        bool Equal(NaturalNumber x, NaturalNumber y) {
            if (x.nn == y.nn) return true;
            else return false;
        } // Equal()

        NaturalNumber Successor(NaturalNumber x) {
            if (x.nn == INT_MAX) return x;
            else {
                x.nn += 1;
                return x;
            } // else
        } // Successor()

        NaturalNumber Add(NaturalNumber x, NaturalNumber y) {
            if ((x.nn + y.nn) <= INT_MAX)
                return NaturalNumber(x.nn + y.nn);
            else
                return INT_MAX;
        } // Add()

        NaturalNumber Substract(NaturalNumber x, NaturalNumber y) {
            if ((x.nn - y.nn) <= 0)
                return NaturalNumber(0);
            else
                return NaturalNumber(x.nn - y.nn);
        } // Substract()
}; // NaturalNumber

int main() {
    // const int n = 10;
    // int list[n] = {1, 2, 3, 4, 5};

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

    // int a[4] = {2, -6, 2, -1};
    // cout << Horner(a, 4, 3) << endl;
    // cout << Horner_R(a, 4, 3, 1) << endl;

    // int n = 5;
    // vector<vector<bool>> ans;
    // BoolCombination(0, n, ans);
    // PrintVecVecBool(ans);
    /// 想想看真值表該怎麼產生，再重寫

    // PrintAscending(6, 3, 5);

    // Pigeon hole principle
    // no idea to write a program but
    // there's an example coming up
    // a != b, f(a) = f(b) = 1
    // f(x) = x / 10;
    // the range of a and b is 10 ~ 19

    // cout << IsSumOfDivisors(5) << endl;
    // cout << IsSumOfDivisors(6) << endl;
    // cout << IsSumOfDivisors(27) << endl;
    // cout << IsSumOfDivisors(28) << endl;

    // cout << Factorial(5) << endl;
    // cout << Factorial_R(5) << endl;
    // cout << Factorial(10) << endl;
    // cout << Factorial_R(10) << endl;

    // cout << Fibonacci(10) << endl;
    // cout << Fibonacci_R(10) << endl;
    // cout << Fibonacci(14) << endl;
    // cout << Fibonacci_R(14) << endl;

    // cout << BinomialCoefficient_R(4, 2) << endl;
    // cout << BinomialCoefficient_R(10, 3) << endl;

    NaturalNumber n1 = NaturalNumber(4);
    NaturalNumber n2 = NaturalNumber(6);
    cout << n1.nn << endl;
    cout << n2.nn << endl;
    NaturalNumber n = NaturalNumber(8);
    n = n.NaturalNumber::Add(n1, n2);
    cout << n.nn << endl;
    n = n.NaturalNumber::Substract(n1, n2);
    cout << n.nn << endl;
    n1.Zero();
    n = n.NaturalNumber::Add(n1, n2);
    cout << n.nn << endl;
    n = n.NaturalNumber::Substract(n1, n2);
    cout << n.nn << endl;

} // main()
