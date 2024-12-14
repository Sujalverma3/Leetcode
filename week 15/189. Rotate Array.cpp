// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n=nums.size(),temp;
//         if(k>=n) k%=n;
//         while(k){
//             temp=nums[n-1];
//             for(int i=n-1;i>0;i--){
//                 nums[i]=nums[i-1];
//             }
//             nums[0]=temp;
//             k--;
//         }

//     }
// };
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k%=n;

//         vector<int> dup(k);
//         for(int i=0;i<k;i++){
//             dup[i] = nums[n - k + i];
//         }

//         for(int i = n - 1; i >= k; i--) {
//             nums[i] = nums[i - k];
//         }

//         for(int i=0;i<k;i++){
//             nums[i] = dup[i];
//         }
//     }
// };
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};