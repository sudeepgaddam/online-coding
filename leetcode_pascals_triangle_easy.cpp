/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows,(vector<int>(1,1)));
        for(int i=1;i<numRows;i++) {
            for(int j=0;j<pascal[i-1].size()-1;j++) {
                pascal[i].push_back(pascal[i-1][j] + pascal[i-1][j+1]);
            }
            pascal[i].push_back(1);
        }
        return pascal;
    }
};
