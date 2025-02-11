#include <iostream>
using namespace std;

int partition(int *a, int start, int end) {
    int pivot = a[end];  
    int P_index = start; 
    for (int i = start; i < end; i++) {
        if (a[i] <= pivot) {
            swap(a[i], a[P_index]);
            P_index++;
        }
    }
    swap(a[P_index], a[end]); 
    return P_index;
}

void Quicksort(int *a, int start, int end) {
    if (start >= end) 
        return; 

    int P_index = partition(a, start, end);
    Quicksort(a, start, P_index - 1);
    Quicksort(a, P_index + 1, end);
}

int main() {
    int n;
    cout << "Enter Number of elements: ";
    cin >> n;
    int a[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Quicksort(a, 0, n - 1);

    cout << "Sorted Elements: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
