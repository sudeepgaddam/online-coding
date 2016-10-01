/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
Subscribe to see which companies asked this question

*/

class Solution {
    private:
    int n;
    public:

        int rec(int start, int end, vector<vector<int> > &counter) {
            int count = 0;
            if((start<1) || (end>n) ) return 1;
            if(start >= end) {
                return 1;
            }
            if(counter[start][end] != -1) return counter[start][end];
            
            
            for(int i=start;i<=end;i++) {
                auto l_count =  rec(start,i-1,counter);
                auto    r_count = rec(i+1,end,counter);
                count = count+ (l_count*r_count);
                
            }
            
            counter[start][end] = count;
            
            
            return count;
        }
        
    int numTrees(int n) {
        vector<vector<int> > counter(n+1,vector<int> (n+1,-1));
        this->n=n;
        return rec(1,n, counter);

    }
};
