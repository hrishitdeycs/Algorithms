#include <iostream>
using namespace std;
int merge(int* A, int p, int q, int r) { // Merges A[p..q] and A[q+1..r], returns number of comparisons made
    int comparisons = 0;
    int nL = q - p + 1;
    int nR = r - q;
    // Create temporary arrays
    int* L = new int[nL];
    int* R = new int[nR];
    // Copy left subarray A[p..q] into L[]
    for (int i = 0; i < nL; i++)
        L[i] = A[p + i];
    // Copy right subarray A[q+1..r] into R[]
    for (int j = 0; j < nR; j++)
        R[j] = A[q + 1 + j];
    int i = 0;   // index for L[]
    int j = 0;   // index for R[]
    int k = p;   // index for merged array A[]
    // Merge elements back into A[p..r]
    while (i < nL && j < nR) {
        comparisons++;              // every L[i] <= R[j] evaluation counts
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < nL) { A[k++] = L[i++]; } // Copy remaining elements of L[] 
    while (j < nR) { A[k++] = R[j++]; } // Copy remaining elements of R[]
    delete[] L;
    delete[] R;
    return comparisons;
}
// Sorts A[p..r], returns total comparisons across all recursive calls
int mergeSort(int* A, int p, int r) {
    if (p >= r) return 0;                       // base case: 0 or 1 element
    int q = (p + r) / 2;                        // middle index
    int comps = 0;
    comps += mergeSort(A, p, q);                // sort left half
    comps += mergeSort(A, q + 1, r);            // sort right half
    comps += merge(A, p, q, r);                 // merge sorted halves
    return comps;
}
int main() {
    int n;
    cout << "Enter number of integers: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " integers (one by one):" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int comps = mergeSort(arr, 0, n - 1);
    cout << "Sorted integers: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Number of comparisons: " << comps << endl;
    delete[] arr;
    return 0;
}
