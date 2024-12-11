class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        vector<bool>res;
        int Max=*max_element(candies.begin(),candies.end());
        for(auto it=candies.begin();it<candies.end();it++){
            if(*it+extra>=Max){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
    }
};