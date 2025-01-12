#include<iostream>
using namespace std;
int fibo(int n, int &steps){
    steps++;
    if(n==0 || n==1){
        return n;
    }
    return fibo(n-1, steps) + fibo(n-2,steps);
}

int main(){
    int n;
    int steps=0;
    cout<<"Enter a number: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<fibo(i, steps)<<" ";
    }
    
    cout<<"\n Number of steps: "<<steps<<endl;
    return 0;