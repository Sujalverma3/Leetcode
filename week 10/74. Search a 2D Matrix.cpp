class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int r=matrix.size(),c=matrix[0].size();
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         if(target == matrix[i][j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        int n = matrix[0].size(), m = matrix.size();
        int strtrw = 0, endrow = m - 1;
        
        while (strtrw <= endrow) {
            int mid = strtrw + (endrow - strtrw) / 2;
            
            // Check if target is within the range of the current row
            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                int st = 0, end = n - 1;
                
                // Binary search in the current row
                while (st <= end) {
                    int midr = st + (end - st) / 2;
                    if (matrix[mid][midr] > target) {
                        end = midr - 1;
                    } else if (matrix[mid][midr] < target) {
                        st = midr + 1;
                    } else {
                        return true;
                    }
                }
                return false; // Target not found in the row
            }
            // Adjust the row range based on the target
            else if (target > matrix[mid][n - 1]) {
                strtrw = mid + 1;
            } else {
                endrow = mid - 1;
            }
        }
        return false; // Target not found in the matrix

    }
};
