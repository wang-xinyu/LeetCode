/**
 * Contains Duplicate III
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 1 || t < 0) return false;
        unordered_map<long, long> map;
        for (int i = 0; i < nums.size(); i++) {
            long remap = (long)nums[i] - INT_MIN;
            long bucket = remap/((long)t + 1);
            if (map.count(bucket) || map.count(bucket-1) && remap - map[bucket-1] <= t || map.count(bucket+1) && map[bucket+1] - remap <= t) {
                return true;
            }
            if (map.size() >= k) {
                long lastBucket = ((long)nums[i-k] - INT_MIN)/((long)t+1);
                map.erase(lastBucket);
            }
            map[bucket] = remap;
        }
        return false;
    }
};
