class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while (left <= right && top <= bottom) {
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            for (int i = top + 1; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            if (top < bottom) {
                for (int j = right - 1; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
            }
            if (left < right) {
                for (int i = bottom - 1; i > top; i--) {
                    result.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return result;
    }
};
