class Solution {
public:
    int getLucky(string s, int k) {
        int ans[40];
        int res = 0, i = 0, temp = 0;
        for (i = 0; i < s.size(); i++) {
            temp = (int(s[i])- 96);
            if ((temp) < 9)
                ans[i] = (int(s[i]) - 96);
            else {
                ans[i] = ((temp) % 10);
                temp /= 10;
                i++;
                ans[i] = ((temp) % 10);
            }
        }

        
        while (k) {
            i = 0;
            while (i < (sizeof(ans))) {
                res += ans[i];
                i++;
            }
            k--;
        }

        return res;
    }
};