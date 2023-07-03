class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(3, INT_MIN);
        vector<int> sell(3, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= 2; ++j) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        
        return sell[2];
    }
};
