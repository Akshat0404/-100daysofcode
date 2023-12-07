class MyQueue {
private:
    std::stack<int> inputStack;
    std::stack<int> outputStack;

    void moveElements() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:
    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (outputStack.empty()) {
            moveElements();
        }

        if (!outputStack.empty()) {
            int front = outputStack.top();
            outputStack.pop();
            return front;
        }

        return -1; 
    }

    int peek() {
        if (outputStack.empty()) {
            moveElements();
        }

        if (!outputStack.empty()) {
            return outputStack.top();
        }

        return -1;
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};
