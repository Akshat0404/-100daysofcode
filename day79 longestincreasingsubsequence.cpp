class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        std::vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};
