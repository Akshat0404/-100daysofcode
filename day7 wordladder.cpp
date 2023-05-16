class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0; 
        }
        
        unordered_map<string, int> wordDistance;
        wordDistance[beginWord] = 1;
        
        queue<string> q;
        q.push(beginWord);
        
        while (!q.empty()) {
            string currentWord = q.front();
            q.pop();
            
            for (int i = 0; i < currentWord.length(); i++) {
                string nextWord = currentWord;
                
                for (char c = 'a'; c <= 'z'; c++) {
                    nextWord[i] = c; 
                    
                    if (nextWord == currentWord) {
                        continue; 
                    }
                    
                    if (nextWord == endWord) {
                        return wordDistance[currentWord] + 1;
                    }
                    
                    if (wordSet.find(nextWord) != wordSet.end() && wordDistance.find(nextWord) == wordDistance.end()) {
                        wordDistance[nextWord] = wordDistance[currentWord] + 1;
                        q.push(nextWord);
                    }
                }
            }
        }
        
        return 0;
    }
};
