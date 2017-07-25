/**
 * Find Median from Data Stream
 * 
 */
class MedianFinder {
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        if (!q2.empty() && num >= q2.top()) q2.push(num);
        else q1.push(num);
        
        if (q1.size() > q2.size() + 1) {
            q2.push(q1.top());
            q1.pop();
        } else if (q2.size() > q1.size() + 1) {
            q1.push(q2.top());
            q2.pop();
        }
    }
    
    double findMedian() {
        if (q1.size() > q2.size()) return (double)q1.top();
        else if (q2.size() > q1.size()) return (double)q2.top();
        return (double)(q1.top() + q2.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
