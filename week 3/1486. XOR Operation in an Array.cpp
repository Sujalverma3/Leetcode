class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> temp;
        int ans = 0, i = 0;
        for (i; i < n; i++) {
            temp.push_back(start + (2 * i));
        }
        if(n>1){
        ans = temp[0] ^ temp[1];
        for (int j = 2; j < temp.size(); j++) {
                ans ^= temp[j];
        }}
        else
        ans=temp[0];
        return ans;
    }
};
//2nd method
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans ^= start + 2 * i;
        }
        return ans;
    }
};