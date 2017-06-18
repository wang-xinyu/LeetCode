/**
 * Add and Search Word - Data structure design
 */
class TrieNode {
public:
    TrieNode *next[26];
    bool isWord;
    TrieNode() {
        memset(next, NULL, sizeof(next));
        isWord = false;
    }
};

class WordDictionary {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->next[word[i] - 'a'] == NULL) {
                p->next[word[i] - 'a'] = new TrieNode();
            }
            p = p->next[word[i] - 'a'];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, 0, root);
    }
    bool dfs(string &word, int start, TrieNode *p) {
        if (start == word.size()) return p->isWord;
        if (word[start] == '.') {
            for (int i = 0; i < 26; i++) {
                if (p->next[i] != NULL && dfs(word, start+1, p->next[i])) return true;
            }
            return false;
        }
        return (p->next[word[start] - 'a'] == NULL) ? false : dfs(word, start+1, p->next[word[start] - 'a']);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
