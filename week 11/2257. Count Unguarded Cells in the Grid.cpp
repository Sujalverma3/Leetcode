// class Solution {
// public:
//     int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
//         // vector<vector<int>> jail(m, vector<int>(n, 0));
//         // //0 UnGarded 1-Guard 2-Gaurded 3-Wall
//         // int i=0;
//         // for(i=0;i<walls.size();i++){
//         //     jail[walls[i][0]][walls[i][1]]=3;
//         // }
//         // for(i=0;i<guards.size();i++){
//         //     jail[guards[i][0]][guards[i][1]]=1;
//         // }
//         // for(auto val:guards){
//         //     int row = val[0], col = val[1];

//         //     // Down
//         //     for (i = row + 1; i < m; i++) {
//         //         if (jail[i][col] == 3 || jail[i][col] == 1) break; // Stop at wall or guard
//         //         jail[i][col] = 2; // Mark as guarded
//         //     }

//         //     // Up
//         //     for (i = row - 1; i >= 0; i--) {
//         //         if (jail[i][col] == 3 || jail[i][col] == 1) break;
//         //         jail[i][col] = 2;
//         //     }

//         //     // Right
//         //     for (i = col + 1; i < n; i++) {
//         //         if (jail[row][i] == 3 || jail[row][i] == 1) break;
//         //         jail[row][i] = 2;
//         //     }

//         //     // Left
//         //     for (i = col - 1; i >= 0; i--) {
//         //         if (jail[row][i] == 3 || jail[row][i] == 1) break;
//         //         jail[row][i] = 2;
//         //     }
//         // }
//         // int unguarded=0;
//         // for (i = 0; i < m; i++) {
//         //     for (int j = 0; j < n; j++) {
//         //         if (jail[i][j] == 0) unguarded++;
//         //     }
//         // }
//         // return unguarded;

        
//     }
// };




class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int g[m][n];
        memset(g, 0, sizeof(g));
        for (auto& e : guards) {
            g[e[0]][e[1]] = 2;
        }
        for (auto& e : walls) {
            g[e[0]][e[1]] = 2;
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        for (auto& e : guards) {
            for (int k = 0; k < 4; ++k) {
                int x = e[0], y = e[1];
                int a = dirs[k], b = dirs[k + 1];
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && g[x + a][y + b] < 2) {
                    x += a;
                    y += b;
                    g[x][y] = 1;
                }
            }
        }
        int ans = 0;
        for (auto& row : g) {
            ans += count(row, row + n, 0);
        }
        return ans;
    }
};