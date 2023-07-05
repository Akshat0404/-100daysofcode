class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> current;

        backtrack(s, 0, current, results);

        return results;
    }

    void backtrack(const string& s, int start, vector<string>& current, vector<vector<string>>& results) {
        if (start >= s.length()) {
            results.push_back(current);
            return;
        }

        for (int end = start; end < s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                string substring = s.substr(start, end - start + 1);
                current.push_back(substring);
                backtrack(s, end + 1, current, results);
                current.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
