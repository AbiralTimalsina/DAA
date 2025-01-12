#include<iostream>
using namespace std;

int selectionSort(int arr[], int n, int &steps){
    for(int i = 0; i < n; i++){
        steps++;
        int min = i;
        for(int j = i + 1; j < n; j++){
            steps++;
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}
int main(){
    int n;
    int steps=0;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    selectionSort(arr,n, steps);
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Number of steps: "<<steps<<endl;
    return 0;
}