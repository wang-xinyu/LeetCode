/**
 * Word Search II 
 */
class TrieNode {
public:
    TrieNode *next[26];
    bool isWord;
    TrieNode () {
        memset(next, NULL, sizeof(next));
        isWord = false;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->next[word[i] - 'a'] == NULL) p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->next[word[i] - 'a'] == NULL) return false;
            p = p->next[word[i] - 'a'];
        }
        if (p->isWord) {
            p->isWord = false;
           return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (p->next[prefix[i] - 'a'] == NULL) return false;
            p = p->next[prefix[i] - 'a'];
        }
        return true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (int i = 0; i < words.size(); i++) {
            trie.insert(words[i]);
        }
        vector<string> ans;
        string word = "";
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(ans, board, trie, word, i, j);
            }
        }
        return ans;
    }
private:
    void dfs(vector<string> &ans, vector<vector<char>>& board, Trie &trie, string &word, int i, int j) {
        if (trie.search(word)) ans.push_back(word);
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '.' || !trie.startsWith(word)) return;
        word.push_back(board[i][j]);
        board[i][j] = '.';
        dfs(ans, board, trie, word, i+1, j);
        dfs(ans, board, trie, word, i-1, j);
        dfs(ans, board, trie, word, i, j+1);
        dfs(ans, board, trie, word, i, j-1);
        board[i][j] = word.back()
        word.pop_back();
    }
};
