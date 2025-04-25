// WAP to demonstrate zero-one knapsack problem using backtracking
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of knapsack: ";
    cin >> W;
    int val[n], wt[n];
    cout << "Enter the values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (wt[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int i = n, j = W;
    vector<int> items;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else {
            items.push_back(i - 1);
            j -= wt[i - 1];
            i--;
        }
    }
    cout << "Maximum value: " << dp[n][W] << endl;
    cout << "Items: ";
    for (int i = items.size() - 1; i >= 0; i--) {
        cout << items[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}