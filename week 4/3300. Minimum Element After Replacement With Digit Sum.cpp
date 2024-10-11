class Solution {
public:
    int minElement(vector<int>& nums) {
        int minNum = INT_MAX;
        int k = 0;
        for (int i : nums) {
            string s = to_string(i);
            int sum = 0;
            for (char c : s) {
                string ss;
                ss += c;
                sum += stoi(ss);
            }
            nums[k] = sum;
            minNum = min(minNum, nums[k]);
            k++;
        }

        return minNum;
    }
};