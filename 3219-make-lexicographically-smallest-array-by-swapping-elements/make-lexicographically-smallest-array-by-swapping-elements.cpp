class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> v;

        for (int i = 0; i < nums.size(); i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        int i = 0;

        while (i < v.size()) {
            int j = i;

            while (j + 1 < v.size() && v[j + 1].first - v[j].first <= limit)
                j++;

            vector<int> values;
            vector<int> indices;

            for (int k = i; k <= j; k++) {
                values.push_back(v[k].first);
                indices.push_back(v[k].second);
            }

            sort(indices.begin(), indices.end());

            for (int k = 0; k < values.size(); k++)
                nums[indices[k]] = values[k];

            i = j + 1;
        }

        return nums;
    }
};