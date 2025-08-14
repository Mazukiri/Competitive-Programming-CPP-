class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Sort the vector in the ascending order
        sort(nums.begin(), nums.end());
        
        //In a vector, mode is the value that 
        int mode = nums[0], currFreq = 1, modeFreq = 1;
        

        for (int i = 1; i<nums.size(); i++){
            if (nums[i] == nums[i - 1]) {
                currFreq++;
                if (currFreq > modeFreq) {
                    modeFreq = currFreq;
                    mode = nums[i];
                }
            }

            else {
                currFreq = 1;
            }
        }

        return mode;
    }
};