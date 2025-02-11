#include<iostream>
using namespace std;

int factorial(int n, int &steps){
    steps++;
    int facto=1;
    if(n==0 || n==1){
        return 1;
    }
    else{
        for(int i=1;i<=n;i++){
            steps++;
            facto*=i;
        }
        return facto;
    }
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