// fibonacci series in iterative method
#include <iostream>
using namespace std;
int main()
{
    int n, steps =0;
    cout << "Enter the number of terms: ";
    cin >> n;
    int a = 0;
    int b = 1;
    cout << a << " " << b << " ";
    steps=steps+2;
    for (int i = 2; i < n; i++)
    {
        steps++;
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
    cout<<"Number of steps: "<<steps<<endl;
    return 0;
}