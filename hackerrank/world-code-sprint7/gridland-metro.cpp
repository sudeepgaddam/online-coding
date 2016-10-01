/*
The city of Gridland is represented as an  matrix where the rows are numbered from  to  and the columns are numbered from  to .

Gridland has a network of train tracks that always run in straight horizontal lines along a row. In other words, the start and end points of a train track are  and , where  represents the row number,  represents the starting column, and  represents the ending column of the train track.

The mayor of Gridland is surveying the city to determine the number of locations where lampposts can be placed. A lamppost can be placed in any cell that is not occupied by a train track.

Given a map of Gridland and its  train tracks, find and print the number of cells where the mayor can place lampposts.

Note: A train track may (or may not) overlap other train tracks within the same row.

Input Format

The first line contains three space-separated integers describing the respective values of  (the number of rows), (the number of columns), and  (the number of train tracks). 
Each line  of the  subsequent lines contains three space-separated integers describing the respective values of , , and  that define a train track.

Constraints

Output Format

Print a single integer denoting the number of cells where the mayor can install lampposts.

Sample Input

4 4 3
2 2 3
3 1 4
4 4 4
Sample Output

9
Explanation

maze.png

In the diagram above, the yellow cells denote the first train track, green denotes the second, and blue denotes the third. Lampposts can be placed in any of the nine red cells, so we print  as our answer.


*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef struct interval {
    
    int beg;  
    int end;
     interval(int s, int e) : beg(s), end(e) {}

}inter;

void merge(vector<inter>& ins,vector<inter>& res) {
    if (ins.empty()) return;
    sort(ins.begin(), ins.end(), [](inter a, inter b){return a.beg < b.beg;});
    res.push_back(ins[0]);
    for (int i = 1; i < ins.size(); i++) {
        if (res.back().end < ins[i].beg) res.push_back(ins[i]);
        else
            res.back().end = max(res.back().end, ins[i].end);
    }
    return ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    long row, col , tracks;
    long r, c1,c2;
    cin>>row>> col>> tracks;
    map<long,vector<inter> > abc;
    for(int i=0;i<tracks;i++) {
        cin>>r>>c1>>c2;
        abc[r].push_back( interval(c1,c2)); 
    }
    map<int,vector<inter>> res;
    for(auto a: abc) merge(a.second, res[a.first]);
    long total = row * col;
     for(auto b: res) {
            for(auto a : b.second)
            total = total - (a.end-a.beg+1);
        }
    cout << total << endl;
    return 0;
}

