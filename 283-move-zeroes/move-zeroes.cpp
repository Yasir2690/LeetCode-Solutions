class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writeIdx = 0;

        for (int current = 0; current < nums.size(); current++) {
            if (nums[current] != 0) {
                nums[writeIdx] = nums[current];
                writeIdx++;
            }
        }

        while (writeIdx < nums.size()) {
            nums[writeIdx] = 0;
            writeIdx++;
        }
    }
};