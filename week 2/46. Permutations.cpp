class Solution {
public:
    void f(vector<int>& nums, unordered_map <int,int> &numbers,vector<int> &path,vector<vector<int>> &ans){
        if(path.size()==nums.size()) {
                ans.push_back(path);
                return;
            }
        for(int i=0;i<nums.size();i++){
            if(numbers[nums[i]]==1){
                path.push_back(nums[i]);
                
                numbers[nums[i]] = 0;
                f(nums,numbers,path,ans);
                numbers[nums[i]] = 1;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map <int,int> numbers;
        for(int i=0;i<nums.size();i++){
            numbers[nums[i]] = 1;
        }
        vector<int> path;
        vector<vector<int>> ans;
        f(nums,numbers,path,ans);
        return ans;
    }
};