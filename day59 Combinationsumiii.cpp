class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(result, current, k, n, 1);
        return result;
    }

private:
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& current, int k, int remaining, int start) {
        if (k == 0 && remaining == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            current.push_back(i);
            backtrack(result, current, k - 1, remaining - i, i + 1);
            current.pop_back();
        }
    }
};
