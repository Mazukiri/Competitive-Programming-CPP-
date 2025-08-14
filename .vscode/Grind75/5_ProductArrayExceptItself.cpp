class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZeroes = 0;
        
        for (int i = 0 ; i<nums.size(); i++) {
            if (nums[i] == 0) countZeroes++;
        }

        vector<int> answer;

        if (countZeroes > 1) {
            for (int i = 0; i<nums.size(); i++) answer.push_back(0);
            return answer;
        }

        if (countZeroes == 1) {
            int nonZeroElement = 1;

            for (int i = 0; i<nums.size(); i++) {
                if (nums[i] == 0) continue;
                nonZeroElement *= nums[i];
            }

            for (int i = 0; i<nums.size(); i++) {
                if (nums[i] == 0) {
                    answer.push_back(nonZeroElement);
                }

                else answer.push_back(0);
            }
        }

        if (countZeroes == 0) {
            int product = 1;
            
            for (int i = 0; i<nums.size(); i++) {
                product *= nums[i];
            }

            for (int i = 0; i<nums.size(); i++) {
                answer.push_back(product/nums[i]);
            }
        }

        return answer;


    }
};