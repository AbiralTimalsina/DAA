#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int temp;
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&arr[l]>arr[largest])
        largest=l;
    if(r<n&&arr[r]>arr[largest])
        largest=r;
    if(largest!=i){
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[],int n){
    int temp;
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(int i=n-1;i>=0; i--){
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,i,0);
    }
}

int main(){
    int n,i;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cout<<"Enter element"<<i+1<<": ";
        cin>>arr[i];
    }
    heapsort(arr,n);
    cout<<"Sorted Elements: ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}