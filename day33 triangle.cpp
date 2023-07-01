class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int numRows = triangle.size();
        
        vector<vector<int>> dp(numRows, vector<int>(numRows));
        
        for (int i = 0; i < numRows; ++i) {
            dp[numRows - 1][i] = triangle[numRows - 1][i];
        }
        
        for (int i = numRows - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        
        return dp[0][0];
    }
};
