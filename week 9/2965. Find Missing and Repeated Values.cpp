class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        vector<int>ans(2);
        int row = grid.size();
        int col = grid[0].size();
        vector<int>temp(row*col);

        int originalSum = 0;
        int currSum = 0;
        int s = 0;

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                int original = abs(grid[i][j]);
                int index = original-1;

                if(temp[index] < 0)
                {
                    ans[0] = abs(temp[index]);
                }
                temp[index] = -grid[i][j];
                originalSum += s+1;
                s++;
                currSum += original;
            }
        }

        int missing = originalSum - (currSum - ans[0]);
        ans[1] = missing;
        return ans;
    }
};