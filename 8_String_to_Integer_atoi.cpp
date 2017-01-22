/**
 * String to Integer (atoi)
 */
class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, head = 0, tail, num = 0, tmp;
        while (str[head] == ' ') head++;
        if (str[head] == '-' || str[head] == '+') {
            sign = (str[head] == '-') ? -1 : 1;
            head++;
        }
        while (str[head] == '0') head++;
        tail = head;
        while (str[tail] >= '0' && str[tail] <= '9' && tail - head < 11) tail++;
        string real = str.substr(head, tail - head);
        for (int i = 0; real[i] != '\0'; i++) {
            tmp = num*10 + (real[i] - '0');
            if (tmp/10 != num) return (sign == 1) ? 0x7FFFFFFF : 0x80000000;
            num = tmp;
        }
        return sign*num;
    }
};
