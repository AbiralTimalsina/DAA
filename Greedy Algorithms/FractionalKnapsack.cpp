#include <iostream>
#include <algorithm>

using namespace std;

// Greedy Fractional Knapsack function
double GreedyFracKnapsack(int wt[], int val[], int n, int W) {
    // Create an array of indices and sort based on value-to-weight ratio
    int indices[n];
    for (int i = 0; i < n; i++) indices[i] = i;

    // Sort indices based on value-to-weight ratio (descending order)
    sort(indices, indices + n, [&](int i, int j) {
        return (double)val[i] / wt[i] > (double)val[j] / wt[j];
    });

    double totalValue = 0.0;  
    double x[n] = {0};  // Array to store fractions

    for (int i = 0; i < n; i++) {
        int idx = indices[i]; // Get original index
        if (wt[idx] <= W) {  
            x[idx] = 1.0;  
            totalValue += val[idx];  
            W -= wt[idx];  
        } else {  
            x[idx] = (double)W / wt[idx];  
            totalValue += x[idx] * val[idx];  
            break;  
        }
    }

    // Output fractions taken
    cout << "Fractions taken: ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    cout << "Total value: " << totalValue << endl;
    return totalValue;
}

// Main function
int main() {
    // int n = 5;
    // int wt[] = {5, 10, 20, 30, 40};
    // int val[] = {30, 20, 100, 90, 160};
    // int W = 60;

    int n,W;
    cout<<"Enter the number of items: ";
    cin>>n;
    int wt[n],val[n];
    for(int i =0; i<n; i++){
        cout<<"Enter weight of item "<<i+1<<": ";
        cin>>wt[i];
        cout<<"Enter Value of item "<<i+1<<": ";
        cin>>val[i];
    }
    cout<<"Enter the capacity: ";
    cin>>W;

    GreedyFracKnapsack(wt, val, n, W);
    return 0;
}
