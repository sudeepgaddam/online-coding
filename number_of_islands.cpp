class Solution {
    
public:
int rows,cols;
  int dfs(vector<vector<char>>& grid, vector<vector<bool>> &visited,int i, int j ) {
    
    if (i>=0 && i < rows && j >=0 && j < cols) {
        if (!visited[i][j] ) {
            visited[i][j] = true;
            if (grid[i][j] == '1') {
                dfs(grid, visited, i+1,j);   
            dfs(grid, visited, i-1,j);   
            dfs(grid, visited, i,j+1);   
            dfs(grid, visited, i,j-1);   
            return 1;
        }
    }
    }
    return -1;
}

  int numIslands(vector<vector<char>>& grid) {
      if (grid.size() == 0) {return 0;}
         rows = grid.size();
         cols = grid[0].size();
      int count = 0;
        vector<vector<bool>> visited(rows, std::vector<bool>(cols, false));
      /* for(auto a : visited) {
          for (auto b : a) {
              cout << b <<",";
          }
      }
*/
  
      for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if (!visited[i][j] && (grid[i][j] == '1')) {
                    dfs(grid,visited,i,j);
                    count++;
                }
                
            }
        }
         return count;
      
      return 0;
  }
    };
