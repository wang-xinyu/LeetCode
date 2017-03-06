/**
 * Count and Say
 */
class Solution {
public:
    string countAndSay(int n) {
        string r = "1";
        for (int i = 1; i < n; i++) {
            string t = "";
            char last = '-';
            int count = 0;
            for (int j = 0; j < r.size(); j++) {
                if (r[j] != last) {
                    if (count) {
                        t += to_string(count);
                        t.push_back(last);
                    }
                    last = r[j];
                    count = 1;
                } else {
                    count++;
                }
            }
            if (count) {
                t += to_string(count);
                t.push_back(last);
            }
            r = t;
        }
        return r;
    }
};
