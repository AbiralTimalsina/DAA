#include<iostream>
using namespace std;

int BST(int arr[],int l, int r, int key, int &steps){
    steps++;
    int m;
    if(l<=r){
        m=(l+r)/2;
        if(arr[m]==key){
            return m;
        }
        else if(arr[m]>key){
            return BST(arr,l,m-1,key,steps);
        }
        else{
            return BST(arr,m+1,r,key,steps);
        }
    }
    else{
        return -1;
    }

}   

int main(){
    int n;
    int steps=0;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the sorted elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key: "<<endl;
    cin>>key;
    
    if(BST(arr,0,n-1,key,steps)==-1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<"Element found at index: "<<BST(arr,1,n-1,key,steps)<<endl;
    }

    cout<<"Steps: "<<steps<<endl;
    return 0;
}