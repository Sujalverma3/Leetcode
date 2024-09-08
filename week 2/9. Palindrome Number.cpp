class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x;
        int rev=0;
        while(temp>0)
        {
            if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10)) {
                break;
            }
            rev=rev*10+(temp%10);
            temp/=10;
        }
        if(x==rev)
        return true;
        else
        return false;
    }
};