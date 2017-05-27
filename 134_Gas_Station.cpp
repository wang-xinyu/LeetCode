/**
 * Gas Station
 *
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size(), totalGas;
        for (int i = 0; i < N; i++) {
            gas[i] -= cost[i];
        }
        for (int start = 0; start < N;) {
            if (gas[start] < 0) {
                start++;
                continue;
            }
            int totalGas = 0, i = 0;
            for (; i < N; i++) {
                totalGas += gas[(i+start)%N];
                if (totalGas < 0) break;
            }
            if (totalGas >= 0) return start;
            start += (i+1);  // If car starts at A and can not reach B. Any station between A and B can not reach B.
        }
        return -1;
    }
};
