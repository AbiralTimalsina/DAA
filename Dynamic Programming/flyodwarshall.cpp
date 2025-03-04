// Wap to demonstrate Floyd Warshall Algorithm using Dynamic Programming.

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of vertices : ";
    cin>>n;
    int a[n][n];
    cout<<"Enter the adjacency matrix :\n ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter the value of a["<<i<<"]["<<j<<"] : ";
            cin>>a[i][j];
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    cout<<"The shortest path matrix is :\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}