/**
 * Verify Preorder Serialization of a Binary Tree
 *
 */
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string item;
        vector<string> elems;
        while (getline(ss, item, ',')) {
            elems.push_back(item);
        }
        removeLeaves(elems);
        return elems.size() == 1 && elems[0] == "#";
    }
private:
    void removeLeaves(vector<string> &elems) {
        int pos = -1;
        for (int i = 0; i < (int)elems.size()-2; i++) {
            if (elems[i] != "#" && elems[i+1] == "#" && elems[i+2] == "#") {
                pos = i;
                break;
            }
        }
        if (pos >= 0) {
            elems.erase(elems.begin()+pos, elems.begin()+pos+2);
            removeLeaves(elems);
        }
    }
};
