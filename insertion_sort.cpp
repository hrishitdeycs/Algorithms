#include <iostream>
using namespace std;
void insertionSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;   // counting actual comparison: arr[j] > key
            arr[j + 1] = arr[j];
            j--;
        }
        if (j >= 0) {
            comparisons++;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int comparisons = 0;
    insertionSort(arr, n, comparisons);
    cout << "\nSorted array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nNumber of comparisons: " << comparisons << endl;
    delete[] arr;
    return 0;
}
