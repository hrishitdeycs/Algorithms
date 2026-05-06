#include <iostream>
using namespace std;
// PARTITION(A, p, r) — pivot is A[r], returns pivot index via reference,
// comparison count as return value
int partition(int* A, int p, int r, int& pivotIndex) {
    int comparisons = 0;
    int x = A[r];           // pivot
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        comparisons++;              // every evaluation of A[j] <= x counts
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);   // place pivot in correct position
    pivotIndex = i + 1;
    return comparisons;
}
// QUICKSORT(A, p, r) — returns total comparisons across all recursive calls
int quickSort(int* A, int p, int r) {
    if (p < r) {
        int q;
        int comps = partition(A, p, r, q);
        comps += quickSort(A, p, q - 1);
        comps += quickSort(A, q + 1, r);
        return comps;
    }
    return 0;
}
int main() {
    int n;
    cout << "Enter number of integers: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " integers (one by one):" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int comps = quickSort(arr, 0, n - 1);
    cout << "Sorted integers: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Number of comparisons: " << comps << endl;
    delete[] arr;
    return 0;
}
