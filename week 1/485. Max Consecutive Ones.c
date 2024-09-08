class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0,count=0;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {

            if(nums[i]==1)
            {
                count+=1;
            } 
            else
            {
                if(max < count)
                    max=count;
                count=0;
            }

        }
        if(count>max){
            return count;
        }
        return max; 
    }
};