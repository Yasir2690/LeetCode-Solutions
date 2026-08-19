class Solution {
public:
    int maxVowels(string s, int k) {
        string v = "aeiou";
        int cnt = 0;

        for (int i = 0; i < k; i++)
            if (v.find(s[i]) != string::npos) cnt++;

        int ans = cnt;

        for (int i = k; i < s.size(); i++) {
            if (v.find(s[i]) != string::npos) cnt++;
            if (v.find(s[i-k]) != string::npos) cnt--;
            ans = max(ans, cnt);
        }

        return ans;
    }
};