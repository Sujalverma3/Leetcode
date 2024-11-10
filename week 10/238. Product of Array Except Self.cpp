class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];

        for(int i=1; i<nums.size(); i++){
            prefix[i] = prefix[i-1] * nums[i];
        }

        vector<int> suffix(n);
        suffix[n-1] = nums[n-1];

        for(int i=n-2; i>0; i--){
            suffix[i] = suffix[i+1] * nums[i];
        }

        vector<int> ans(n);

        for(int i=0; i<n; i++){
            if(i == 0){
                ans[i] = suffix[i+1];
            }
            else if(i == n-1){
                ans[i] = prefix[i-1];

            }
            else{
                ans[i] = prefix[i-1] * suffix[i+1];
            }
        }

        return ans;
    }
};
//OPTIMAL APPROACH
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];//prefix value
        }
        int suffix=1;
        for (int i = n - 2; i >= 0; i--) {
            suffix*=nums[i+1]; //suffix value
            res[i] *= suffix;
        }
        return res;
    }
};