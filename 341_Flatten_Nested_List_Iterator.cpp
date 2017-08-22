/**
 * Flatten Nested List Iterator
 *
 * Trick: recursively
 *
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    queue<int> q;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        fillTheQ(nestedList);
    }

    int next() {
        int t = q.front();
        q.pop();
        return t;
    }

    bool hasNext() {
        return !q.empty();
    }
private:
    void fillTheQ(vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger()) {
                q.push(nestedList[i].getInteger());
            } else {
                fillTheQ(nestedList[i].getList());
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
