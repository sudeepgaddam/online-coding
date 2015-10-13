#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <queue>
#include <limits>       // std::numeric_limits
#include <climits>
using namespace std;
int N;
int solve(std::vector<std::vector<int>> &res,int index, int rem_value,vector<int> &W,vector<int> &V) {
	
	if(index < N && rem_value>0) {
		if(res[index][rem_value] == -1 ) {
			//cout<<"index "<<index<< "rem_value "<<rem_value<<endl;
			if(W[index] > rem_value) {
				res[index][rem_value] = solve(res,index+1, rem_value, W, V);
			} else {
			res[index][rem_value] = max(solve(res,index+1, rem_value, W, V),
									solve(res,index+1, rem_value - W[index], W, V) + V[index]);
			}
		}
	} else {
		return 0;
	}
	return res[index][rem_value];
}

int main() 
{	

	int S;
    cin>>S>>N;
    int a,b;
    vector<int> W(N,0),V(N,0);
    std::vector<std::vector<int>> results(N,std::vector<int>(S+1,-1)); // Defaults to -1 initial value
    for(int i=0;i<N;i++) {
		cin>>a>>b;
		W[i] = a;
		V[i] = b;
	}
	solve(results,0,S,W,V);
	
	cout<<results[0][S]<<endl;

}
