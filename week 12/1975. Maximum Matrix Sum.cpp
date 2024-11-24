class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long matsum = 0;
        int n = matrix[0].size();
        int neg = 0, min = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) {
                    neg++;
                    matsum += (-1 * matrix[i][j]);
                } else {
                    matsum += matrix[i][j];
                }
                if (min > abs(matrix[i][j]))
                    min = abs(matrix[i][j]);
            }
        }
        if (neg % 2 == 0)
            return matsum;
        else
            return matsum-(2*min);
    }
};