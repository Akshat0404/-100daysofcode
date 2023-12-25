class Solution {
public:
    bool isValidSerialization(std::string preorder) {
        std::istringstream input(preorder);
        std::stack<std::string> stack;

        std::string token;
        while (std::getline(input, token, ',')) {
            while (!stack.empty() && token == "#" && stack.top() == "#") {
                stack.pop();
                if (stack.empty()) {
                    return false;
                }
                stack.pop();
            }
            stack.push(token);
        }

        return stack.size() == 1 && stack.top() == "#";
    }
};
