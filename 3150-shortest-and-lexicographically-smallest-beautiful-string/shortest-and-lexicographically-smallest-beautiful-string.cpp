class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0, len = n + 1;
        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;

            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            if (ones == k) {
                while (s[left] == '0')
                    left++;

                int curLen = right - left + 1;
                string cur = s.substr(left, curLen);

                if (curLen < len || (curLen == len && cur < ans)) {
                    len = curLen;
                    ans = cur;
                }
            }
        }

        return ans;
    }
};