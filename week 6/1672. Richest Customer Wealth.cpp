class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max=INT_MIN,sum=0;
        for(vector<int> x:accounts)
        {
            sum=0;
            for(int i=0;i<x.size();i++)
            {
                sum+=x[i];
            }
            if(max<sum) max=sum;
        }
        return max;
    }
};
//solution 2
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth=0;
        for(int i=0;i<accounts.size();i++)
        {
            int wealth=0;
            for(int j=0;j<accounts[i].size();j++) wealth +=accounts[i][j];
            maxWealth = max(wealth, maxWealth);
        }
        return maxWealth;
    }
};