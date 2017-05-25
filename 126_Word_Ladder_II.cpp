/**
 * Word Ladder II
 * 
 * Build the tree and then find the path use DFS, i.e. BFS and then DFS
 */
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans, tree;
        int depth = ladderLength(beginWord, endWord, wordList, tree);
        if (depth == 0) return ans;
        //cout << depth << " " << tree.size() << endl;
        vector<string> seq;
        seq.push_back(beginWord);
        findLadders(endWord, tree, ans, seq);
        return ans;
    }
private:
    void findLadders(string &endWord, vector<vector<string>>& tree, vector<vector<string>> &ans, vector<string> &seq) {
        if (seq.size() == tree.size()) {
            if (seq.back() == endWord) ans.push_back(seq);
            return;
        }
        int level = seq.size();
        //cout << "level " << level << endl;
        for (int i = 0; i < tree[level].size(); i++) {
            if (!diffOneLetter(tree[level][i],seq.back())) continue;
            seq.push_back(tree[level][i]);
            findLadders(endWord, tree, ans, seq);
            seq.pop_back();
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList, vector<vector<string>>& tree) {
        vector<string> levelNodes;
        addNextLevelNodes(beginWord, wordList, levelNodes);
        int depth = 2;
        tree.push_back(vector<string>(1, beginWord));
        while (!levelNodes.empty()) {
            tree.push_back(levelNodes);
            int n = levelNodes.size();
            for (int i = 0; i < n; i++) {
                if (levelNodes[i] == endWord) return depth;
                addNextLevelNodes(levelNodes[i], wordList, levelNodes);
            }
            levelNodes.erase(levelNodes.begin(), levelNodes.begin() + n);
            depth++;
        }
        return 0;
    }
    void addNextLevelNodes(string beginWord, vector<string>& wordList, vector<string>& levelNodes) {
        for (int i = 0; i < wordList.size();) {
            if (diffOneLetter(beginWord, wordList[i])) {
                levelNodes.push_back(wordList[i]);
                wordList.erase(wordList.begin() + i);
            }
            else i++;
        }
    }
    bool diffOneLetter(string x, string y) {
        if (x.size() != y.size()) return false;
        int count = 0;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] != y[i]) count++;
        }
        return (count == 1);
    }
};
