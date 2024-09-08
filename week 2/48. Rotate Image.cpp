class Solution {
public:
    void rev(vector<int> s)
    {
        int i=0,j=s.size();
        while(i!=j)
        {
            
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int i, j;
        for (i = 0; i < matrix.size(); i++) {
            for (j = 0; j <= i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<(matrix.size())/2;j++){
                swap(matrix[i][j],matrix[i][(matrix.size())-1-j]);
            }
        }
    }
};