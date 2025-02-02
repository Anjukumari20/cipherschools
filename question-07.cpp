#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive function to find the maximum profit
int maxProfit(int n, vector<int>& prices) {
    // Base case: If the rod length is zero, no profit can be made
    if (n == 0)
        return 0;
    
    int max_val = INT_MIN;
    
    // Try cutting the rod at different lengths and calculate profit
    for (int i = 0; i < n; i++) {
        int current_profit = prices[i] + maxProfit(n - (i + 1), prices);
        max_val = max(max_val, current_profit);
    }
    
    return max_val;
}

int main() {
    int N = 8;
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    
    cout << maxProfit(N, prices) << endl;
    
    return 0;
}
