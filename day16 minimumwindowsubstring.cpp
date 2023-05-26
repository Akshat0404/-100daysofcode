class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }
        
        unordered_map<char, int> tFreq, sFreq;
        for (char ch : t) {
            tFreq[ch]++;
        }
        
        int required = tFreq.size();
    
        int left = 0, right = 0;
        int formed = 0; 
        int minLen = INT_MAX, minStart = -1; 
        
        while (right < s.length()) {
            char ch = s[right];
            sFreq[ch]++;
            
            if (tFreq.count(ch) && sFreq[ch] == tFreq[ch]) {
                formed++;
            }
            
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                char leftChar = s[left];
                sFreq[leftChar]--;
                
                if (tFreq.count(leftChar) && sFreq[leftChar] < tFreq[leftChar]) {
                    formed--;
                }
                
                left++; 
            }
            
            right++;  
        }
        
        return (minStart == -1) ? "" : s.substr(minStart, minLen);
    }
};
