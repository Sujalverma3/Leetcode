class Solution {
public:
    bool check(vector<int>& nums) {
        int c=0;
        if(nums[0]<nums[nums.size()-1]) c++;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1]) c++;
            if(c>1) return false;
        }
        return true;
    }
};