// class Solution {
// public:
//     vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
//         // vector<int>res;
//         // int n=queries.size(),m=items.size(),max=0;
//         // for(int i=0;i<n;i++){
//         //     for(int j=0;j<m;j++){
//         //         if(items[j][0] <= queries[i] && max<items[j][1]){
//         //             max=int(items[j][1]);
//         //         }
//         //     }
//         //     res.push_back(max);
//         //     max=0;
//         // }
//         // return res;

//     }
// };


//method 2



// #include <vector>
// #include <algorithm>
// #include <climits>

// using namespace std;

// class Solution {
// public:
//     vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
//         int maxI = INT_MAX;
//         vector<vector<int>> res = {{0, 0, maxI}};

//         sort(items.begin(), items.end());

//         for (const auto& item : items) {
//             int price = item[0];
//             int beauty = item[1];
//             if (beauty > res.back()[1]) {
//                 res.back()[2] = price;
//                 res.push_back({price, beauty, maxI});
//             }
//         }

//         vector<int> ans;

//         for (int x : queries) {
//             for (int i = res.size() - 1; i >= 0; i--) {
//                 if (res[i][0] <= x) {
//                     ans.push_back(res[i][1]);
//                     break;
//                 }
//             }
//         }

//         return ans;
//     }
// };


//method 3


class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n = items.size();
        vector<int> maxBeauty(n),prices(n);
        maxBeauty[0] = items[0][1];
        prices[0] = items[0][0];
        for(int i =1;i<n;i++) {
            prices[i] = items[i][0];
            maxBeauty[i] = max(maxBeauty[i-1],items[i][1]);
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0;i<m;i++) {
            int idx = bs(prices,queries[i]);
            if(idx == -1) {
                ans[i] = 0;
            }
            else {
                ans[i] = maxBeauty[idx];
            }
        }
        return ans;
    }

    int bs(vector<int>& prices,int target) {
        int low = 0;
        int high = prices.size() - 1;
        int result = -1;
        while(low <= high) {
            int mid = low + (high -low) / 2;
            if(prices[mid] <= target) {
                result = mid;
                low = mid +1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }
};