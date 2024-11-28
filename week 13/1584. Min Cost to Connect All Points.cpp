// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         vector<vector<pair<int, int>>> adj_list(points.size(), vector<pair<int, int>>());
//         for(int i = 0 ; i < points.size(); i++) {
//             vector<int> curr = points[i];
//             for(int j = 0; j < points.size(); j++) {
//                 if(j == i) continue;
//                 adj_list[i].push_back({abs(curr[0] - points[j][0]) + abs(curr[1] - points[j][1]), j});
//             }
//         }
// 		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
//         vector<int> visited(points.size(), 0);
//         pq.push({0, 0});
//         int ans = 0;
//         while(!pq.empty()) {
//             int curr = pq.top().second;
//             int wt = pq.top().first;
//             pq.pop();
//             if(visited[curr]) continue;
//             visited[curr] = true;
//             ans += wt;
//             for(pair<int, int> neighb: adj_list[curr]) {
//                 if(visited[neighb.second]) continue;
//                 pq.push(neighb);
//             }
//         }
//         return ans;
//     }
// };


class Solution 
{
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;
        int n = points.size();
        int distance;
        for ( int i = 1 ; i < n ; i++ )
        {
            distance = abs ( points[0][0] - points[i][0]) + abs ( points[0][1] - points[i][1] );
            pq.push({distance , i});
        }

        vector<bool> ifvisited ( n , false);
        ifvisited[0] = true;
        int vcount = 1;
        int cur_distance = 0;
        int cur_points = 0;

        while ( pq.size() > 0 && vcount < n)
        {
            pair<int,int> temp = pq.top();
            pq.pop();

            cur_distance = temp.first;
            cur_points = temp.second;

            if ( ifvisited[cur_points] )
            {
                continue;
            }
            else
            {
                ifvisited[cur_points] = true;
                vcount++;
                ans += cur_distance;
                for ( int i = 0 ; i < n ; i++ )
                {
                    if ( ifvisited[i] )
                    {
                        continue;
                    }
                    distance = abs ( points[cur_points][0] - points[i][0]) + abs ( points[cur_points][1] - points[i][1] );
                    pq.push({ distance , i});
                }
            }
        }
        return ans;
    }
    int ans = 0;
};
