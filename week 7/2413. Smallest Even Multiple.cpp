class Solution {
public:
    int smallestEvenMultiple(int n) {
        int ans = 0;
        for (int i = n; i % n == 0; i += n) {
            if (i % 2 == 0) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};