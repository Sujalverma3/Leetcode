class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elesum = 0, digsum = 0;
        for (int x : nums) {
            elesum += x;
            while (x) {
                digsum += x % 10;
                x /= 10;
            }
        }
        return abs(elesum - digsum);
    }
};