class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;

        for (int i = 0; i < s.size(); ++i) {
            char charS = s[i];
            char charT = t[i];

            if (s_to_t.find(charS) != s_to_t.end()) {
                if (s_to_t[charS] != charT) {
                    return false;
                }
            } else {
                s_to_t[charS] = charT;
            }

            if (t_to_s.find(charT) != t_to_s.end()) {
                if (t_to_s[charT] != charS) {
                    return false;
                }
            } else {
                t_to_s[charT] = charS;
            }
        }

        return true;
    }
};
