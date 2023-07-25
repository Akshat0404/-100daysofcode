class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    if (k >= n / 2) {
        int maxProfit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int j = 1; j <= k; j++) {
        int maxProfitWithPreviousTransaction = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][j] = max(dp[i - 1][j], prices[i] + maxProfitWithPreviousTransaction);
            maxProfitWithPreviousTransaction = max(maxProfitWithPreviousTransaction, dp[i - 1][j - 1] - prices[i]);
        }
    }

    return dp[n - 1][k];
    }

};
