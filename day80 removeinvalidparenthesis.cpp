class Solution {
public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> result;
        std::queue<std::string> q;
        std::unordered_set<std::string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            std::string current = q.front();
            q.pop();

            if (isValid(current)) {
                result.push_back(current);
                found = true;
            }

            if (found) {
                continue;
            }

            for (int i = 0; i < current.size(); ++i) {
                if (current[i] == '(' || current[i] == ')') {
                    std::string next = current.substr(0, i) + current.substr(i + 1);
                    if (visited.find(next) == visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }

        return result;
    }

private:
    bool isValid(const std::string& s) {
        int count = 0;

        for (char ch : s) {
            if (ch == '(') {
                count++;
            } else if (ch == ')') {
                count--;
                if (count < 0) {
                    return false;
                }
            }
        }

        return count == 0;
    }
};
