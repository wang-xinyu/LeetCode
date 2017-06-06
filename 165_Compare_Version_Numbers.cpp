/**
 * Compare Version Numbers
 *
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size(), i, j;
        for (i = 0, j = 0; i < n1 && j < n2; i++, j++) {
            int pre1 = i;
            int pre2 = j;
            while (i < n1 && version1[i] != '.') i++;
            while (j < n2 && version2[j] != '.') j++;
            int num1 = (i == pre1) ? 0 : atoi(version1.substr(pre1, i-pre1).c_str());
            int num2 = (j == pre2) ? 0 : atoi(version2.substr(pre2, j-pre2).c_str());
            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
        }
        if (n1-i != n2-j) return (n1-i > n2-j) ? compareVersion(version1.substr(i, n1-i), "0") : compareVersion("0", version2.substr(j, n2-j));
        return 0;
    }
};
