class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int ans=0;
        // for(int n:nums){
        //     int freq=0;
        //     ans=n;
        //     for(int ele:nums){
        //         if(n==ele){
        //             freq++;
        //         }
        //     }
        //     if(freq >(nums.size())/2){
        //         break;
        //     }
        // }
        // return ans;

        //METHOD 2
        int n=nums.size(),freq=0,ans=0;
        for(int i=0;i<n;i++){
            if(freq==0){
                ans=nums[i];
            }
            if(ans==nums[i]) freq++;
            else freq--;
        }
        return ans;

    }
};