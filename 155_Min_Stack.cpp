/**
 * Min Stack
 *
 */ 
class MinStack {
private:
    int min;
    stack<int> s;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (s.empty() || x <= min) {
            s.push(min);
            min = x;
        }
        s.push(x);
    }
    
    void pop() {
        int t = s.top();
        s.pop();
        if (t == min) {
            min = s.top();
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
