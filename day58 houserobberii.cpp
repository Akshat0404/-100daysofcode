#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) {
            return *max_element(nums.begin(), nums.end());
        }
        int maxRob1 = robHelper(nums, 0, n - 2);
        int maxRob2 = robHelper(nums, 1, n - 1);
        return max(maxRob1, maxRob2);
    }

private:
    int robHelper(vector<int>& nums, int start, int end) {
        int prevMax = 0;
        int currMax = 0;

        for (int i = start; i <= end; ++i) {
            int temp = currMax;
            currMax = max(prevMax + nums[i], currMax);
            prevMax = temp;
        }

        return currMax;
    }
};
