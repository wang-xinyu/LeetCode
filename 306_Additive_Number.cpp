/**
 * Additive Number
 * 
 */
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= n-2 && i <= 10; i++) {
            if (num[0] == '0' && i > 1) break;
            string str1 = num.substr(0, i);
            long num1 = atol(str1.c_str());
            //if (num1 >= INT_MAX) break;
            for (int j = 1; j <= n-i-1 && j <= 10; j++) {
                if (i > n-i-j || j > n-i-j || num[i] == '0' && j > 1) break;
                string str2 = num.substr(i, j);
                long num2 = atol(str2.c_str());
                //if (num2 >= INT_MAX) break;
                //cout << num1 << " " << num2 << " " << i << " " << j << endl;
                if (dfs(num, num1, num2, i+j)) return true;
            }
        }
        return false;
    }
private:
    bool dfs(string &num, int num1, int num2, int start) {
        if (start == num.size()) return true;
        long sum = (long)num1 + (long)num2;
        //if (sum > INT_MAX || sum != 0 && num[start] == '0') return false;
        if (sum != 0 && num[start] == '0') return false;
        int i = start;
        for (int n = sum/10; n; n /= 10) i++;
        for (; i < num.size() && i < start+10; i++) {
            string str = num.substr(start, i-start+1);
            long temp = atol(str.c_str());
            //if (temp > INT_MAX) break;
            if (temp != sum) continue;
            //cout << "----" << sum << " " << temp << endl;
            if (dfs(num, num2, (int)temp, i+1)) return true;
        }
        return false;
    }
};
