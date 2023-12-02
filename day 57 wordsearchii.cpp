class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd;

    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
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
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (string word : words) {
            trie.insert(word);
        }

        vector<string> result;
        unordered_set<string> resultSet;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                string currentWord = "";
                dfs(board, i, j, visited, trie.root, currentWord, resultSet);
            }
        }

        for (const string& word : resultSet) {
            result.push_back(word);
        }

        return result;
    }

    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, TrieNode* node, string& currentWord, unordered_set<string>& resultSet) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || !node->children[board[i][j] - 'a']) {
            return;
        }

        visited[i][j] = true;
        currentWord += board[i][j];
        node = node->children[board[i][j] - 'a'];

        if (node->isEnd) {
            resultSet.insert(currentWord);
            node->isEnd = false; // Avoid duplicates
        }

        dfs(board, i + 1, j, visited, node, currentWord, resultSet);
        dfs(board, i - 1, j, visited, node, currentWord, resultSet);
        dfs(board, i, j + 1, visited, node, currentWord, resultSet);
        dfs(board, i, j - 1, visited, node, currentWord, resultSet);

        visited[i][j] = false;
        currentWord.pop_back();
    }
};
