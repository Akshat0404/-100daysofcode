class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        int i = 0, j = 1;
        while (j < intervals.size()) {
            if (intervals[j][0] <= intervals[i][1]) {
                intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                j++;
            } else {
                i++;
                intervals[i] = intervals[j];
                j++;
            }
        }
        intervals.resize(i+1);
        return intervals;
    }

};
