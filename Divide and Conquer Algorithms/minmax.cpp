#include <iostream>
using namespace std;

pair<int, int> minmax(int arr[], int l, int r) {
    int minVal, maxVal;

    
    if (l == r) {
        minVal = maxVal = arr[l];
    } 
    
    else if (l == r - 1) {
        if (arr[l] < arr[r]) {
            minVal = arr[l];
            maxVal = arr[r];
        } else {
            minVal = arr[r];
            maxVal = arr[l];
        }
    } 
    
    else {
        int mid = (l + r) / 2;

        
        pair<int, int> leftMinMax = minmax(arr, l, mid);
        pair<int, int> rightMinMax = minmax(arr, mid + 1, r);

        
        minVal = min(leftMinMax.first, rightMinMax.first);
        maxVal = max(leftMinMax.second, rightMinMax.second);
    }

    return {minVal, maxVal}; 
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    pair<int, int> result = minmax(arr, 0, n - 1);

    cout << "Minimum: " << result.first << " and Maximum: " << result.second << endl;
    return 0;
}
