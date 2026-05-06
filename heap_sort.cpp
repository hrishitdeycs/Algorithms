#include <iostream>
using namespace std;
int heapSize;
// MAX-HEAPIFY — 0-based: left child = 2i+1, right child = 2i+2
int maxHeapify(int* A, int i) {
    int comparisons = 0;
    int l = 2 * i + 1;      // left  child
    int r = 2 * i + 2;      // right child
    int largest = i;
    if (l < heapSize) {
        comparisons++;
        if (A[l] > A[i])
            largest = l;
    }
    if (r < heapSize) {
        comparisons++;
        if (A[r] > A[largest])
            largest = r;
    }
    if (largest != i) {
        swap(A[i], A[largest]);
        comparisons += maxHeapify(A, largest);
    }
    return comparisons;
}
// BUILD-MAX-HEAP — last non-leaf is at index (n/2 - 1), go downto 0
int buildMaxHeap(int* A, int n) {
    heapSize = n;
    int comparisons = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
        comparisons += maxHeapify(A, i);
    return comparisons;
}
// HEAPSORT — swap root (index 0) with last, shrink heap, re-heapify root
int heapSort(int* A, int n) {
    int comparisons = buildMaxHeap(A, n);
    for (int i = n - 1; i >= 1; i--) {
        swap(A[0], A[i]);
        heapSize--;
        comparisons += maxHeapify(A, 0);
    }
    return comparisons;
}
int main() {
    int n;
    cout << "Enter number of integers: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter " << n << " integers (one by one):" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int comps = heapSort(arr, n);
    cout << "Sorted integers: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Number of comparisons: " << comps << endl;
    delete[] arr;
    return 0;
}
