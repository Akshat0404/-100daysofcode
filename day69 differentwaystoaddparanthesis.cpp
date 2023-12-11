class Solution {
public:
    std::vector<int> diffWaysToCompute(std::string expression) {
        std::vector<int> result;

        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*') {
                std::string leftExpr = expression.substr(0, i);
                std::string rightExpr = expression.substr(i + 1);

                std::vector<int> leftResults = diffWaysToCompute(leftExpr);
                std::vector<int> rightResults = diffWaysToCompute(rightExpr);

                for (int left : leftResults) {
                    for (int right : rightResults) {
                        if (c == '+') {
                            result.push_back(left + right);
                        } else if (c == '-') {
                            result.push_back(left - right);
                        } else if (c == '*') {
                            result.push_back(left * right);
                        }
                    }
                }
            }
        }

        if (result.empty()) {
            result.push_back(std::stoi(expression));
        }

        return result;
    }
};
