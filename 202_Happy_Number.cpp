/**
 * Happy Number
 *
 */
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> map;
        int i = n;
        while (map.count(i) == 0) {
            map[i]++;
            int t = 0;
            for (int j = i; j; j /= 10) {
                t += pow(j%10, 2);
            }
            i = t;
        }
        return (i == 1);
    }
};
