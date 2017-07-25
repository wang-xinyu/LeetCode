/**
 * Range Sum Query - Mutable
 * 
 */
class NumArray {
    vector<int> blk, localNums;
    int blkSize, numOfBlk;
public:
    NumArray(vector<int> nums) {
        localNums.assign(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0) return;
        blkSize = ceil(sqrt(n));
        numOfBlk = n/blkSize + ((n%blkSize == 0) ? 0 : 1);
        //cout << blkSize << " " << numOfBlk;
        blk.assign(numOfBlk, 0);
        for (int i = 0; i < numOfBlk; i++) {
            for (int j = 0; j < blkSize && i*blkSize + j < n; j++) {
                blk[i] += nums[i*blkSize + j];
            }
        }
        
    }
    
    void update(int i, int val) {
        int diff = val - localNums[i];
        localNums[i] = val;
        blk[i/blkSize] += diff;
    }
    
    int sumRange(int i, int j) {
        int blknum1 = i/blkSize, blknum2 = j/blkSize, index1 = i%blkSize, index2 = j%blkSize, sum = 0;
        if (blknum1 == blknum2) return accumulate(localNums.begin() + i, localNums.begin() + j + 1, 0);
        for (int t = blknum1 + 1; t < blknum2; t++) sum += blk[t];
        for (int t = index1; t < blkSize; t++) sum += localNums[blknum1*blkSize + t];
        for (int t = 0; t <= index2; t++) sum += localNums[blknum2*blkSize + t];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
