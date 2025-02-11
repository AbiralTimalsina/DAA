#include <iostream>
using namespace std;



int gcd(int a, int b, int &steps){
    int temp;
    if(a==0){
        return b;
    }
    else if(b==0){
        return a;
    }
    else {
        while(b!=0){
            steps++;
            temp= a%b;
            a=b;
            b=temp;
        }
    }

    return a;
}


int main()
{
int steps = 0;
   cout<<"Enter two numbers: ";
   int a, b;
   cin>>a>>b;
   cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a,b,steps)<<endl;
   cout<<"Steps: "<<steps<<endl;
   return 0;
}