class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd;
    
    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
        isEnd = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool searchInTrie(string word, TrieNode* node) {
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (c == '.') {
                for (int j = 0; j < 26; ++j) {
                    if (node->children[j] && searchInTrie(word.substr(i + 1), node->children[j])) {
                        return true;
                    }
                }
                return false;
            } else {
                int index = c - 'a';
                if (!node->children[index]) {
                    return false; 
                }
                node = node->children[index];
            }
        }
        return node->isEnd;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return searchInTrie(word, root);
    }
};
