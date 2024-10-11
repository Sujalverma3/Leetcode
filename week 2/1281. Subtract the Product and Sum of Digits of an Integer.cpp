class Solution {
public:
    int subtractProductAndSum(int n) {
        int add=0,pro=1,x=0;
        while(n!=0)
        {
            x=n%10;
            add+=x;
            pro*=x;
            n/=10;
        }
        return pro-add;
    }
};