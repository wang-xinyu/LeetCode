/**
 * Range Sum Query - Immutable
 * 
 */
class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int> nums) {
        sum.assign(nums.begin(), nums.end());
        for (int i = 1; i < sum.size(); i++) {
            sum[i] += sum[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return i > 0 ? sum[j] - sum[i-1] : sum[j]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
