#include <iostream>
using namespace std;



int gcd(int a, int b, int &steps){
    steps++;
    if(b == 0)
    return a;

    return gcd(b, a%b, steps);
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