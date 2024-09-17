class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int k=0;
        for(int x:nums)
        {
            if(x%3!=0)
            {
                k++;//only one operation is required always
            }
        }
        return k;

    }
};