class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        int * p =&nums[0];
        int * q =&nums[n];
        for(int i=0;i<n;i++)
        {
            ans.push_back(*(p+i));
            ans.push_back(*(q+i));
        }
        return ans;
    }
};