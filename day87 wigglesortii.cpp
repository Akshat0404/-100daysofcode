class Solution {
public:
    void wiggleSort(std::vector<int>& nums) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        std::vector<int> result(n, 0);

        int smallerIndex = (n - 1) / 2;
        int largerIndex = n - 1;

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                result[i] = nums[smallerIndex];
                --smallerIndex;
            } else {
                result[i] = nums[largerIndex];
                --largerIndex;
            }
        }

        nums = result;
    }
};
