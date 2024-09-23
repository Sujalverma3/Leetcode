class Solution {
public:
    bool isPowerOfTwo(int num) {
        if(num<1) return false;
        while(num!=1)
        {
            if(num%2==1) return false;
            num/=2;
        }
        return true;
    }
};