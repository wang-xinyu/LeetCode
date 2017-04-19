/**
 * Valid Number
 */
class Solution {
public:
    bool isNumber(string s) {
        int head = 0, tail = s.size() - 1;
        while (s[head] == ' ') head++;
        while (s[tail] == ' ') tail--;
        if (s[head] == '+' || s[head] == '-') head++;
        s = s.substr(head, tail-head+1);
        for (int i = 0; i < s.size(); i++) if (!(s[i] >= '0' && s[i] <= '9' || s[i] == 'e' || s[i] == '.' || s[i] == '+' || s[i] == '-')) return false;
        int e_pos = s.find('e');
        int dot_pos = s.find('.');
        int plus_pos = s.find('+');
        int minus_pos = s.find('-');
        head = 0;
        tail = s.size() - 1;
        if (e_pos != s.find_last_of('e') || dot_pos != s.find_last_of('.') || plus_pos != s.find_last_of('+') || minus_pos != s.find_last_of('-')) return false;
        if (e_pos != -1 && dot_pos != -1 && e_pos < dot_pos) return false;
        if (e_pos == head || e_pos == tail) return false;
        if (dot_pos == head && dot_pos == tail) return false;
        if (dot_pos == head && e_pos == head + 1) return false;
        if (plus_pos != -1 && (plus_pos == head || plus_pos == tail || s[plus_pos - 1] != 'e')) return false;
        if (minus_pos != -1 && (minus_pos == head || minus_pos == tail || s[minus_pos - 1] != 'e')) return false;
        return true;
    }
};
