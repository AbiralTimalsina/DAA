#include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int p[], int n) {
    int m[n][n]; // Cost matrix

    for (int i = 1; i < n; i++)
        m[i][i] = 0; 

    for (int len = 2; len < n; len++) { 
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int p[n + 1]; // Stores the dimensions of matrices
    cout << "Enter the dimensions:\n";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    cout << "The minimum number of multiplications required is: " 
         << matrixChainMultiplication(p, n + 1) << endl;

    return 0;
}
