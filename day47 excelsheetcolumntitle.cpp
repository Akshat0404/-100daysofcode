class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            int remainder = columnNumber % 26;
            
            if (remainder == 0) {
                result = 'Z' + result;
                columnNumber = (columnNumber - 1) / 26;
            } else {
                result = char('A' + remainder - 1) + result;
                columnNumber /= 26;
            }
        }
        
        return result;
    }
};
