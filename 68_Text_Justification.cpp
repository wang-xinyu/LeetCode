/**
 *  Text Justification 
 */
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0, j = 0, remainWidth = maxWidth, n = words.size();
        vector<string> res;
        string str = "";
        while (i < n) {
            if (j < n && (int)words[j].size() <= remainWidth) {
                remainWidth -= (words[j].size() + 1);
                j++;
            } else {
                int nbr = j - i;
                str = "";
                if (nbr == 1) {
                    str += words[i];
                    str.insert(str.end(), maxWidth - str.size(), ' ');
                } else if (j >= n) {
                    for (int k = i; k < j; k++) str = str + words[k] + " ";
                    if (str.size() > maxWidth) str.pop_back();
                    else str.insert(str.end(), maxWidth - str.size(), ' ');
                } else {
                    int charlen = 0;
                    for (int k = i; k < j; k++) charlen += words[k].size();
                    int spacelen = (maxWidth - charlen) / (nbr - 1);
                    int extraSpace = (maxWidth - charlen) % (nbr - 1);
                    for (int k = i; k < j; k++) {
                        str += words[k];
                        if (k-i < extraSpace) str.insert(str.end(), spacelen+1, ' ');
                        else if (k < j - 1) str.insert(str.end(), spacelen, ' ');
                    }
                }
                res.push_back(str);
                i = j;
                remainWidth = maxWidth;
            }
        }
        return res;
    }
};
