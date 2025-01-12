#include<iostream>
using namespace std;

int insertionSort(int arr[], int n, int &steps) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        steps++;
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            steps++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    return 0;
}

int main() {
     int n;
    int steps=0;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(arr,n, steps);
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Number of steps: "<<steps<<endl;
    return 0;
}