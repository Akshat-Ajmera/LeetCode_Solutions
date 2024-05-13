/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
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
private:
    vector<int> ans;
    int pos = 0; // this is used after the list has been flattened to iterate through the flattened list using next() and hasNext()
    void helper(vector<NestedInteger> &nestedList) {
        for(int i=0; i<nestedList.size(); i++) {
            if(nestedList[i].isInteger()) ans.push_back(nestedList[i].getInteger());
            else helper(nestedList[i].getList());
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    int next() {
        return ans[pos++];
    }
    bool hasNext() {
        return pos < ans.size();
    }
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */