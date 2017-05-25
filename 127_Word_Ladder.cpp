/**
 * Word Ladder
 * 
 * Just like a level node traversal
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> levelNodes;
        addNextLevelNodes(beginWord, wordList, levelNodes);
        int depth = 2;
        while (!levelNodes.empty()) {
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
private:
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
