#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int maxProfit(int n, vector<int>& prices) {
   
    if (n == 0)
        return 0;
    
    int max_val = INT_MIN;
    
    
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