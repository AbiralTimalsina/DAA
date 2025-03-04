#include<iostream>
using namespace std;
#define INT_MAX 999

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    
    int a[n][n];
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (i == j) a[i][j] = INT_MAX; // Avoid self-loop selection
        }
    }
    
    int visited[n] = {0};
    visited[0] = 1;
    int current = 0;
    
    cout << "The path is: 0";
    for (int count = 1; count < n; count++) {
        int min = INT_MAX, min_index = -1;
        
        for (int j = 0; j < n; j++) {
            if (!visited[j] && a[current][j] < min) {
                min = a[current][j];
                min_index = j;
            }
        }
        
        if (min_index != -1) {
            cout << " -> " << min_index;
            visited[min_index] = 1;
            current = min_index;
        }
    }
    
    cout << " -> 0\n"; // Returning to the starting node
    return 0;
}
