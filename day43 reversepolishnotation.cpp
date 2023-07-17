class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        
        for (const string& token : tokens) {
            if (isOperator(token)) {
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                
                int result;
                if (token == "+") {
                    result = operand1 + operand2;
                } else if (token == "-") {
                    result = operand1 - operand2;
                } else if (token == "*") {
                    result = operand1 * operand2;
                } else if (token == "/") {
                    result = operand1 / operand2;
                }
                
                operands.push(result);
            } else {
                operands.push(stoi(token));
            }
        }
        
        return operands.top();
    }
    
private:
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
};
