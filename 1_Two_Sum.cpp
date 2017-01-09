class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashTable;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            if(hashTable.find(complement) != hashTable.end()){
                result.push_back(hashTable[complement]);
                result.push_back(i);
            }
            hashTable[nums[i]] = i;
        }
        return result;
    }
};

