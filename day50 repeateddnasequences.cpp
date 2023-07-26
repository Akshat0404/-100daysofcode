class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> result;

        vector<string> sequences;

        int n = s.length();
        if (n < 10) return sequences;

        for (int i = 0; i <= n - 10; i++) {
            string subsequence = s.substr(i, 10);
            if (seen.count(subsequence) > 0) {
                result.insert(subsequence);
            } else {
                seen.insert(subsequence);
            }
        }

        for (const auto& sequence : result) {
            sequences.push_back(sequence);
        }

        return sequences;
    }
};
