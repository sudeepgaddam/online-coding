
/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.


*/
class Solution {
public:

    void rowZeroes(vector<vector<int>>& matrix, int row) {
        for(int j=0;j<matrix[0].size();j++)
        matrix[row][j] =0;
        
    }

    void colsZeroes(vector<vector<int>>& matrix, int col) {
        for(int j=0;j<matrix.size();j++)
        matrix[j][col] =0;
        
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> rows(matrix.size(),false);
        vector<bool> cols(matrix[0].size(),false);
        
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
               if(matrix[i][j]==0){
                   rows[i] = true;
                   cols[j] = true;
               } 
                
            }
        }
        
        for(int i=0;i<rows.size();i++) if(rows[i]) rowZeroes(matrix,i);
        for(int i=0;i<cols.size();i++) if(cols[i]) colsZeroes(matrix,i);
    }
};
