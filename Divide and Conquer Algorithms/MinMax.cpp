//Wap to find Min max using min-max algorithm using iterative method.
#include<iostream>
using namespace std;
int minmax(int arr[],int n){
    int min=arr[0],max=arr[0], steps=0;
    for(int i=1;i<n;i++){
        steps++;
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    cout<<"Minimum: "<<min<<" Maximum: "<<max<<endl;
    cout<<"Number of steps: "<<steps;
    return 0;
}

int main(){
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    minmax(arr,n);
    return 0;
}
