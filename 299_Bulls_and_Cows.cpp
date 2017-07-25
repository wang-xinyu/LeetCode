/**
 * Bulls and Cows
 * 
 */
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size(), bull = 0, cow = 0;
        unordered_map<char, int> map;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) bull++;
            else map[secret[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) continue;
            if (map[guess[i]]) {
                cow++;
                map[guess[i]]--;
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
