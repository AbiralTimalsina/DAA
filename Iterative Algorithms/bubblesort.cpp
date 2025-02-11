#include<iostream>
using namespace std;
int bubblesort(int arr[],int n, int &steps){

for(int i=0;i<n-1;i++){
    steps++;
    for(int j=0;j<n-i-1;j++){
        steps++;
        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
return 0;
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
    bubblesort(arr,n, steps);
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Number of steps: "<<steps<<endl;
    return 0;
}