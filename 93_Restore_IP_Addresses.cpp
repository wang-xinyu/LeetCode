/**
 * Restore IP Addresses
 * DFS
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string ip = "";
        int len = s.size();
        restoreIp(ans, s, len, 0, ip, 0);
        return ans;
    }
private:
    void restoreIp(vector<string> &ans, string &s, int &len, int head, string &ip, int n) {
        if (n == 4 && len + 4 == ip.size()) {
            ip.pop_back();
            ans.push_back(ip);
            return;
        }
        if (head >= len || n > 4 || len-head < 4-n || len-head > 3*(4-n)) return;
        for (int i = 1; i <= 3; i++) {
            if (s.size() - head < i || i > 1 && s[head] == '0') continue;
            string str = s.substr(head, i);
            int num = atoi(str.c_str());
            if (num > 255) continue;
            string temp = ip;
            ip = ip + str + ".";
            restoreIp(ans, s, len, head+i, ip, n+1);
            ip = temp;
        }
    }
};
