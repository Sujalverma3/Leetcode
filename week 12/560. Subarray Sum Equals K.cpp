class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //     int n = nums.size(), count = 0;
        //     for (int i = 0; i < n; i++) {
        //         int sum = 0;
        //         for (int j = i; j < n; j++) {
        //             sum += nums[j];
        //             if (sum == k) {
        //                 count++;
        //             }
        //         }
        //     }
        //     return count;

        int n = nums.size(), count = 0;
        vector<int>presum(n,0);
        unordered_map<int, int> map;
        presum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            presum[i] = presum[i - 1] + nums[i];
        }
        for (int j = 0; j < n; j++) {
            if (presum[j] == k) {
                count++;
            }
            int val = presum[j] - k;
            if (map.find(val) != map.end()) {
                count += map[val];
            }
            if (map.find(presum[j]) == map.end()) {
                map[presum[j]] = 0;
            }
            map[presum[j]]++;
        }
        return count;
    }
};