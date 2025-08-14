class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int countZeroes = 0;

        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                countZeroes++;
                nums.erase(nums.begin() + i);
                i--;
            }
        }

        for (int i = 1; i<=countZeroes; i++) nums.push_back(0);
    }
};