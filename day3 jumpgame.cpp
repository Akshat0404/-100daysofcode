class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxPos = 0; // maximum reachable position
        for (int i = 0; i < n; i++) {
            if (i > maxPos) return false; // current position is not reachable
            maxPos = max(maxPos, i + nums[i]); // update maximum reachable position
            if (maxPos >= n - 1) return true; // reach the last index
        }
        return true;
    }
};
