class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane's ALGORITHM
        int n = nums.size(), maxsum = INT_MIN;
        int cursum = 0;
        for (int i = 0; i < n; i++) {

            cursum += nums[i];
            maxsum = max(cursum, maxsum);
            if (cursum <= 0) {
                cursum = 0;
            }
        }

        return maxsum;
    }
};