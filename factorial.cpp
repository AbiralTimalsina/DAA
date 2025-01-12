#include<iostream>
using namespace std;

int factorial(int n, int &steps){
    steps++;
    if(n==0){
        return 1;
    }
    return n*factorial(n-1, steps);
}
int main(){
    int n;
    int steps=0;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"The Factorial of "<<n<<" is: "<<factorial(n, steps)<<"\n";
    cout<<"Number of steps: "<<steps<<endl;
    return 0;
}