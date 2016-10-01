/*
  Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

  For example,
  Given n = 3,

  You should return the following matrix:
  [
   [ 1, 2, 3 ],
   [ 8, 9, 4 ],
   [ 7, 6, 5 ]
  ]


*/

class Solution {
public:


    void rec(int start, int end, vector<vector<int>> &mat, int step,int counter ) {
        if(counter >mat.size()*mat.size()) return;
        
        
        int i= start+step;
        int j;
        
        
        //left to right
        for(j=start+step;j<end-step;j++) {
            mat[i][j] = counter++;
            if(counter > mat.size()*mat.size()) return;
        }
        
        
        //top to bottom
        j = end-step-1;
        for(i=start+step+1;i<end-step;i++) {
            mat[i][j] = counter++;
                if(counter > mat.size()*mat.size()) return;
    
        }
        
        
        //right to left
        i=end-step-1;
        for(j=end-step-2;j>=start+step+1;j--) {
            mat[i][j] = counter++;
            if(counter > mat.size()*mat.size()) return;

        }
        
        
        //bottom to top
        j=start+step;
        for(i=end-step-1;i>=start+step+1;i--) { 
            mat[i][j] = counter++;
            if(counter > mat.size()*mat.size()) return;

        }
        
        rec(start,end, mat, step+1,counter);
        
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n));
        rec(0, n, mat,0,1);
        return mat;
        
        
    }
};
