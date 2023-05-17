class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int lastWordLength = 0;
        
        for (char c : s) {
            if (c == ' ') {
                if (length > 0) {
                    lastWordLength = length;
                }
                length = 0;
            } else {
                length++;
            }
        }
        
        if (length > 0) {
            lastWordLength = length;
        }
        
        return lastWordLength;
    }
};
