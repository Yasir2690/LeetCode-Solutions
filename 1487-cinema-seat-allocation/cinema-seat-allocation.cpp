class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &x : reservedSeats)
            mp[x[0]] |= 1 << x[1];

        int ans = 2 * n;

        for (auto &[row, mask] : mp) {
            int groups = 0;

            if ((mask & ((1<<2)|(1<<3)|(1<<4)|(1<<5))) == 0)
                groups++;

            if ((mask & ((1<<6)|(1<<7)|(1<<8)|(1<<9))) == 0)
                groups++;

            if (groups == 0 &&
                (mask & ((1<<4)|(1<<5)|(1<<6)|(1<<7))) == 0)
                groups++;

            ans -= 2 - groups;
        }

        return ans;
    }
};