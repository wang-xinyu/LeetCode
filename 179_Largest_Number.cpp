/**
 * Largest Number
 *
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        if (nums.empty()) return ans;
        sort(nums.begin(), nums.end(), compare);
        int i = 0;
        while (nums[i] == 0) i++;
        for (;i < nums.size(); i++) {
            ans += to_string(nums[i]);
        }
        return ans.empty() ? "0" : ans;
    }
private:
    static bool compare(int a, int b) {
        string s1 = to_string(a), s2 = to_string(b);
        return s1+s2 > s2+s1;
    } 
};
