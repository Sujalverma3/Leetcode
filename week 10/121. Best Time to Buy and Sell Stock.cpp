class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro=0,buy=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>buy){
                maxpro=max(maxpro,prices[i]-buy);
            }
            buy=min(buy,prices[i]);
        }
        return maxpro;
    }
};