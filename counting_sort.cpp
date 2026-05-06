#include <iostream>
using namespace std;
// COUNTING-SORT(A, n, k) — 0-based indexing
// A[0...n-1] : input array
// n          : number of elements
// k          : maximum value in A
int* countingSort(int* A, int n, int k) {
    // Step 1 : Create array C[0...k] and initialize all elements to 0
    int* C = new int[k + 1];
    for (int i = 0; i <= k; i++)
        C[i] = 0;
    // Step 2 : Create array B[0...n-1] (output array)
    int* B = new int[n];
    // Step 3 : for j = 0 to n-1  →  C[A[j]] = C[A[j]] + 1
    //          Count occurrences of each value
    for (int j = 0; j < n; j++)
        C[A[j]] = C[A[j]] + 1;
    // Step 4 : for i = 1 to k  →  C[i] = C[i] + C[i-1]
    //          Compute cumulative counts
    for (int i = 1; i <= k; i++)
        C[i] = C[i] + C[i - 1];
    // Step 5 : for j = n-1 down to 0
    //              B[C[A[j]] - 1] = A[j]   (−1 converts 1-based position → 0-based index)
    //              C[A[j]]        = C[A[j]] - 1
    //          Build output array (stable sort)
    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]        = C[A[j]] - 1;
    }
    // Step 6 : Free auxiliary array and return B
    delete[] C;
    return B;   
}
int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    int* A = new int[n];
    cout << "Enter " << n << " non-negative integer elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    // Find maximum value k (upper bound of value range)
    k = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > k)
            k = A[i];
    int* B = countingSort(A, n, k);
    cout << "\nOriginal array : ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\nSorted array   : ";
    for (int i = 0; i < n; i++)
        cout << B[i] << " ";
    cout << endl;
    delete[] A;
    delete[] B;
    return 0;
}
