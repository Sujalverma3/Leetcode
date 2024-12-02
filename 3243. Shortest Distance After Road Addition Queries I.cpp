//METHOD dijistra
// class Solution {
// public:
//     int dj(int &n, vector<vector<int>> roads){

//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         vector<int> dist(n, INT_MAX);

//         pq.push({ 0, 0 });
//         dist[0] = 0;

//         while(!pq.empty()){

//             auto [distance, node] = pq.top();
//             pq.pop(); 
         
//             for(auto adjRoad : roads[node]){
//                 if(1 + distance < dist[adjRoad]){
//                     dist[adjRoad] = 1 + distance;
//                     pq.push({ 1 + distance,  adjRoad });
//                 }
//             }

//         }
     
//         return dist[n-1];
//     }

//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
//         vector<vector<int>> roads(n);

//         for(int i = 0; i < n-1; i++){
//             roads[i].push_back(i+1);
//             // roads[i+1].push_back(i);
//         }

//         vector<int> ans(queries.size());

//         for(int i = 0; i < queries.size(); i++){

//             int u = queries[i][0];
//             int v = queries[i][1];

//             roads[u].push_back(v);
//             // roads[v].push_back(u);

//             ans[i] = dj(n, roads);
//         }

//         return ans;
//     }
// };

//METHOD DFS
// class Solution {
//     void dfs(vector<vector<int>>& tree, int c, vector<int>& dp) {
//         int d=dp[c]+1;
//         for (int x : tree[c]) {
//             if (dp[x]<=d) continue;
//             dp[x]=d;
//             dfs(tree,x,dp);
//         }
//     }
// public:
//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
//         vector<int> dp(n);
//         for (int i=0; i<n; ++i) dp[i]=n-1-i;
//         vector<vector<int>> tree(n);
//         for (int i=0; i+1<n; ++i)
//             tree[i+1].push_back(i);
//         int m=int(queries.size());
//         vector<int> res(m);
//         int i=0;
//         for (auto& q : queries) {
//             int a=q[0], b=q[1];
//             tree[b].push_back(a);
//             dp[a]=min(dp[a],dp[b]+1);
//             dfs(tree,a,dp);
//             res[i]=dp[0];
//             ++i;
//         }
//         return res;
//     }
// };


// METHOD BFS
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {

        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> dist(n);

        iota(dist.begin(), dist.end(), 0); //fills the array with 0,1,2,3...
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        
        for (auto it : queries) {

            int src = it[0], des = it[1];
            adj[src].push_back(des);

            if (dist[src] + 1 < dist[des]) {
                //BFS
                queue<int> q;
                q.push(des);
                dist[des] = dist[src] + 1;

                while (q.size()) {

                    int idx = q.front();
                    q.pop();

                    for (auto e : adj[idx]) {

                        if (dist[idx] + 1 < dist[e]) {
                            dist[e] = dist[idx] + 1;
                            q.push(e);
                        }

                    }
                }
            }

            ans.emplace_back(dist.back());
        }
        return ans;
    }
};