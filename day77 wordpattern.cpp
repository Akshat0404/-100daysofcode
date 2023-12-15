class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::unordered_map<char, std::string> charToWord;
        std::unordered_map<std::string, char> wordToChar;

        std::istringstream ss(s);
        std::vector<std::string> words;
        std::string word;
      
        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            std::string word = words[i];

            if (charToWord.find(c) != charToWord.end() && charToWord[c] != word) {
                return false;
            }

            if (wordToChar.find(word) != wordToChar.end() && wordToChar[word] != c) {
                return false;
            }

            charToWord[c] = word;
            wordToChar[word] = c;
        }

        return true;
    }
};
