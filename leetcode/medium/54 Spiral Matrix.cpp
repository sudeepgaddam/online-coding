/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]


*/

class Solution {
public:

   void rec(int start, int rows, int cols, vector<vector<int>> &mat, int step,vector<int> &res ) {
        
        int i= start+step;
        int j;
        
        
        //left to right
        for(j=start+step;j<cols-step;j++) {
            res.push_back(mat[i][j]);
            if(res.size()==(rows*cols)) return;
        }
        
        
        //top to bottom
        j = cols-step-1;
        for(i=start+step+1;i<rows-step;i++) {
            res.push_back(mat[i][j]);
            if(res.size()==(rows*cols)) return;
        }
        
        
        //right to left
        i=rows-step-1;
        for(j=cols-step-2;j>=start+step+1;j--) {
            res.push_back(mat[i][j]);
            if(res.size()==(rows*cols)) return;
        }
        
        
        //bottom to top
        j=start+step;
        for(i=rows-step-1;i>=start+step+1;i--) { 
            res.push_back(mat[i][j]);
            if(res.size()==(rows*cols)) return;

        }
        
        //Call recursively for the next spiral
        rec(start,rows, cols, mat, step+1,res);
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        if(m==0) return res;
        int n=matrix[0].size();
        rec(0, m, n, matrix,0,res);
        return res;

    }
};
