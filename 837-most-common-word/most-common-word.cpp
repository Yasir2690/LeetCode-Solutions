class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> mp;

        string word, ans;
        int mx = 0;

        for (char c : paragraph + " ") {
            if (isalpha(c)) {
                word += tolower(c);
            } else if (!word.empty()) {
                if (!ban.count(word)) {
                    mp[word]++;

                    if (mp[word] > mx) {
                        mx = mp[word];
                        ans = word;
                    }
                }
                word = "";
            }
        }

        return ans;
    }
};