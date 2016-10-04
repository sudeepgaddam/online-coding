/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    
    
    bool checkValid(int x,int y,const int &rows, const int &cols) {
        return ((x>=0 && x<rows) && 
                (y>=0 && y<cols));
        
    }
    bool dfs(int x, 
        int y,
        const vector<vector<char>>& board,
        const string &word,
        int curr,
        const int &rows, 
        const int &cols,
        vector<int> &x_delta,
        vector<int> &y_delta,
        vector<vector<int>> &visited) {
        // cout<< "curr " << curr << ",x=" << x << " y=" << y << endl;
        if(curr==(word.size()-1)){
          
        //   cout<< "Reached end of word" << endl;
          return true;  
        } 
        for(int i=0;i<x_delta.size();i++) {
            // cout<< "Hi there" << endl;
            if(checkValid(x+x_delta[i], y+y_delta[i], rows, cols)){
                // cout<< "Valid " <<x+x_delta[i]<< ", " << y+y_delta[i] <<  endl;
                
                if(!visited[x+x_delta[i]][y+y_delta[i]]) {
                    if(board[x+x_delta[i]][y+y_delta[i]] == word[curr+1]){
                        // cout << "Match for character " << word[curr+1] << endl;
                        
                        //Set visited true
                        visited[x+x_delta[i]][y+y_delta[i]] = 1;
                        
                        if(dfs(x+x_delta[i], y+y_delta[i], board, word,  curr+1, rows, cols,x_delta,y_delta, visited)) {
                            return true;
                        }
                        
                        //Unset visited true
                        visited[x+x_delta[i]][y+y_delta[i]] = 0;
                        
                    }
                }
            }
        }
        
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> x_delta ={-1,1,0,0};
        vector<int> y_delta = {0,0,-1,1};
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        
        
        //Try to start at each and every charater of board. Do dfs, If found anywhere, return, Mission success
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(board[i][j] == word[0]) {
                    visited[i][j] =1;
                    //If found, just return completely, No need of anymore search
                     if(dfs(i,j,board, word, 0, board.size(), board[0].size(), x_delta, y_delta, visited)) {
                        return true;
                    }
                    
                    visited[i][j] =0;
                }
                    
            }
        }
         
        //We can do this either by DFS or BFS
        
        return false;
        
    }
};
