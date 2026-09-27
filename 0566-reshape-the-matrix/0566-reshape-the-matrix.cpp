class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int cols = mat[0].size();
        if((row*cols) != (r*c)) return mat;

        vector<vector<int>> output(r, vector<int>(c));
        int newcols =0;
        int newrow = 0;
        for(int i =0; i<row; i++) {
            for(int j = 0; j<cols; j++) {
                output[newrow][newcols] = mat[i][j];
                newcols++;
                if(newcols == c) {
                    newcols = 0;
                    newrow++;
                }
            }
        }
        return output;
        
    }
};