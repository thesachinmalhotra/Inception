class MinStack {

private:
      std::stack<std::pair<int, int>> stack;

public:
    MinStack() {}
    
    void push(int val) {
        int minValue = stack.empty() ? val : std::min(val, stack.top().second);

        stack.push({val, minValue});
    }
    
    void pop() {
        stack.pop();
    }
    
    int top() {
       return stack.top().first;        
    }
    
    int getMin() {
        return stack.top().second;
    }
};
