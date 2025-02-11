#include <iostream>
#include <cstdlib>  
using namespace std;

int partition(int arr[], int p, int r) {
   
    int pivotindex = p + rand() % (r - p + 1);
    swap(arr[pivotindex], arr[r]);  
    int pivot = arr[r];

    int i = p - 1; 

    for (int j = p; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]); 
    return i + 1;
}

void quicksort(int arr[], int p, int q) {
    if (p < q) {
        int j = partition(arr, p, q);
        quicksort(arr, p, j - 1);
        quicksort(arr, j + 1, q);
    }
}

int main() {
    int i, n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter array elements: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];

    quicksort(arr, 0, n - 1);

    cout << "Sorted Elements: ";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
