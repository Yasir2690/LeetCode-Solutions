class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0;

        for (int tIndex = 0; tIndex < t.size(); tIndex++) {
            if (sIndex < s.size() &&
                s[sIndex] == t[tIndex]) {
                sIndex++;
            }
        }

        return sIndex == s.size();
    }
};