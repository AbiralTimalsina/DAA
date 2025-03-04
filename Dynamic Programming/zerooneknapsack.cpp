#include <iostream>
using namespace std;

int w[10], p[10], v[10][10], n, i, j, cap, x[10] = {0};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knap(int i, int j) {
    if (i == 0 || j == 0)
        return 0;
    if (v[i][j] < 0) {
        if (j < w[i - 1])
            v[i][j] = knap(i - 1, j);
        else
            v[i][j] = max(knap(i - 1, j), knap(i - 1, j - w[i - 1]) + p[i - 1]);
    }
    return v[i][j];
}

int main() {
    int profit;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the profit and weights of the items:\n";
    for (i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> p[i] >> w[i];
    }
    cout << "Enter the capacity of the knapsack: ";
    cin >> cap;
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= cap; j++) {
            v[i][j] = -1;
        }
    }
    
    profit = knap(n, cap);
    
    i = n;
    j = cap;
    while (i > 0 && j > 0) {
        if (v[i][j] != v[i - 1][j]) {
            x[i - 1] = 1;
            j -= w[i - 1];
        }
        i--;
    }
    
    cout << "Items included are: \n";
    cout << "S.N. \t Weight \t Profit\n";
    for (i = 0; i < n; i++) {
        if (x[i]) {
            cout << i + 1 << "\t    " << w[i] << "\t\t   " << p[i] << "\n";
        }
    }
    cout << "Total profit: " << profit << "\n";
    return 0;
}