class Solution {
public:
    int minPatches(std::vector<int>& nums, int n) {
        long long miss = 1;
        int patches = 0;
        int i = 0;

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss *= 2;
                patches++;
            }
        }

        return patches;
    }
};
