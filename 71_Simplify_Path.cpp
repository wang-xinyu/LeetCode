/**
 *  Simplify Path
 */
class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string res = "/";
        for (int i = 0, j = 1; i < path.size(); j++) {
            if (j >= n || path[j] == '/') {
                string item = path.substr(i+1, j-i-1);
                i = j;
                if (item == ".") {
                    res.pop_back();
                } else if (item == "..") {
                    int pos = res.find_last_of('/', res.size() - 4);
                    res.erase(pos+1);
                } else if (item.size() > 0 && j < n - 1){
                    res.push_back(path[j]);
                }
            }
            else {
               res.push_back(path[j]);
            }
        }
        while (res.size() > 1 && res.back() == '/') res.pop_back();
        return res;
    }
};
