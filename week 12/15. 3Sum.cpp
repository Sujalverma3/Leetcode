class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int find, start, end;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            find = 0 - nums[i];
            start = i + 1;
            end = nums.size() - 1;
            while (start < end) {
                if (nums[start] + nums[end] == find) {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    while (start < nums.size() - 1 &&
                           nums[start + 1] == nums[start])
                        start++;
                    while (end > 0 && nums[end - 1] == nums[end])
                        end--;
                    start++;
                } else if (nums[start] + nums[end] > find)
                    end--;
                else
                    start++;
            }
        }
        return ans;
    }
};
