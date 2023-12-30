class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }

        std::sort(nums.begin(), nums.end());

        std::vector<int> dp(n, 1);
        std::vector<int> prevIndex(n, -1);

        int maxSize = 1, maxIndex = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prevIndex[i] = j;

                    if (dp[i] > maxSize) {
                        maxSize = dp[i];
                        maxIndex = i;
                    }
                }
            }
        }

        std::vector<int> result;
        while (maxIndex != -1) {
            result.push_back(nums[maxIndex]);
            maxIndex = prevIndex[maxIndex];
        }

        return result;
    }
};
