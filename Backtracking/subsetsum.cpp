#include <iostream>
#include <vector>

using namespace std;


void findSubsets(vector<int>& nums, int n, int sum, vector<int>& subset, vector<vector<int>>& result) {
    if (sum == 0) {
        result.push_back(subset);
        return;
    }
    if (n == 0) return;
    
   
    findSubsets(nums, n - 1, sum, subset, result);
    
    
    if (nums[n - 1] <= sum) {
        subset.push_back(nums[n - 1]);
        findSubsets(nums, n - 1, sum - nums[n - 1], subset, result);
        subset.pop_back(); 
    }
}

int main() {
    int n, sum;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter the target sum: ";
    cin >> sum;
    
    vector<vector<int>> result;
    vector<int> subset;
    
    findSubsets(nums, n, sum, subset, result);
    
    if (result.empty()) {
        cout << "No subset with given sum." << endl;
    } else {
        cout << "Subsets with given sum: " << endl;
        vector<int> optimalSubset;
        for (const auto& s : result) {
            if (optimalSubset.empty() || s.size() < optimalSubset.size()) {
                optimalSubset = s;
            }
            cout << "[ ";
            for (int num : s) {
                cout << num << " ";
            }
            cout << "]" << endl;
        }
        cout << "\nOptimal subset (smallest size): [ ";
        for (int num : optimalSubset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
