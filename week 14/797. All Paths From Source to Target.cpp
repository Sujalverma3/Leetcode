// class Solution {
// public:
//     void dfs(vector<vector<int>>& graph, vector<vector<int>>& v, vector<int>& path, int curr){
//         path.push_back(curr);
//         if(curr == graph.size()-1){
//             v.push_back(path);
//         }
//         else{
//             for(auto i: graph[curr]){
//                 dfs(graph, v, path, i);
//             }
//         }
//         path.pop_back();
//     }

//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         vector<vector<int>> v;
//         vector<int> path;

//         dfs(graph, v, path, 0);
//         return v;
//     }
// };
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> indeg(n, 0);
        vector<int> vis(n, 0);
        vector<vector<int>> ans;
        vector<int> cur;
        cur.push_back(0);
        vis[0] = 1;
        dfs(0, g, cur, ans, vis, n);
        return ans;
    }
    void dfs(int idx, vector<vector<int>>& g, vector<int>& cur,
             vector<vector<int>>& ans, vector<int>& vis, int n) {
        if (idx == (n - 1)) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < g[idx].size(); i++) {
            int id = g[idx][i];
            if (vis[id] == 0) {
                vis[id] = 1;
                cur.push_back(id);
                dfs(id, g, cur, ans, vis, n);
                cur.pop_back();
                vis[id] = 0;
            }
        }
    }
};