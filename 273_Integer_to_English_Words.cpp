/**
 *  Integer to English Words 
 *
 */
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string ans = "";
        string ones[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tens[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        for (int i = num, count = 0; i; i /= 1000, count++) {
            int j = i%1000;
            if (j == 0) continue;
            int hun = j/100, ten = j%100/10, one = j%10;
            string temp = "";
            if (hun) temp += ones[hun-1] + " Hundred ";
            if (ten >= 2) {
                temp += tens[ten-2] + " ";
                if (one) temp += ones[one-1] + " ";
            } else if (one || ten) {
                temp += ones[ten*10 + one - 1] + " ";
            }            
            if (count == 1) temp += "Thousand ";
            else if (count == 2) temp += "Million ";
            else if (count == 3) temp += "Billion ";
            ans = temp + ans;
        }
        ans.pop_back();
        return ans;
    }
};
