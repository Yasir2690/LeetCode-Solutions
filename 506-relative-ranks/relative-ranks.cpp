class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> a = score;
        sort(a.rbegin(), a.rend());

        unordered_map<int, string> mp;

        for (int i = 0; i < a.size(); i++) {
            if (i == 0)
                mp[a[i]] = "Gold Medal";
            else if (i == 1)
                mp[a[i]] = "Silver Medal";
            else if (i == 2)
                mp[a[i]] = "Bronze Medal";
            else
                mp[a[i]] = to_string(i + 1);
        }

        vector<string> ans;

        for (int x : score)
            ans.push_back(mp[x]);

        return ans;
    }
};