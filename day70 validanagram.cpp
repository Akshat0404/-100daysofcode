class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> charFrequency;

        for (char c : s) {
            charFrequency[c]++;
        }

        for (char c : t) {
            if (charFrequency.find(c) == charFrequency.end() || charFrequency[c] == 0) {
                return false;
            } else {
                charFrequency[c]--;
            }
        }

        return true;
    }
};
