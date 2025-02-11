#include<iostream>
using namespace std;

void Merge(int *a, int low, int high, int mid, int &steps){
    int i,j,k,temp[high-low+1];
    i=low;
    k=0;
    j=mid+1;

    while(i<=mid && j<=high){
        steps++;
        if(a[i]<a[j]){
            temp[k]=a[i];
            k++;
            i++;
        }
        else{
            temp[k]=a[j];
            k++;
            j++;
        }
    }

    while(i<=mid){
        steps++;
        temp[k]=a[i];
        k++;
        i++;
    }
    while (j<=high)
    {
        steps++;
        temp[k]=a[j];
        k++;
        j++;
    }

    for(i=low; i<=high;i++){
        steps++;
        a[i]=temp[i-low];
    }
    
}

void MergeSort(int *a, int low, int high, int &steps){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        MergeSort(a,low,mid, steps);
        MergeSort(a, mid+1, high, steps);
        Merge(a,low,high,mid, steps);
    }
}

int main(){
    int n,i, steps=0;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    MergeSort(arr,0,n-1, steps);
    cout<<"Sorted Elements: ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Number of steps: "<<steps<<endl;
    return 0;
}