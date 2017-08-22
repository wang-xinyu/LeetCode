/**
 * Self Crossing
 *
 * Trick: the self crossing situation are devided into 3 situations
 */
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for (int i = 0; i < x.size(); i++) {
            if (i >= 3 && x[i] >= x[i-2] && x[i-1] <= x[i-3]) {
                return true;
            } else if (i >= 4 && x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2]) {
                return true;
            } else if (i >= 5 && x[i] + x[i-4] >= x[i-2] && x[i-1] + x[i-5] >= x[i-3] && x[i-2] >= x[i-4] && x[i-3] >= x[i-1]) {
                return true;
            }
        }
        return false;
    }
};
