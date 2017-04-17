/**
 * Length of Last Word 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int tail = s.size() - 1;
        while (tail >= 0 && s[tail] == ' ') tail--;
        int head = tail;
        while (head >= 0 && s[head] != ' ') head--;
        return tail - head;
    }
};
