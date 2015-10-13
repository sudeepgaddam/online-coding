
#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <queue>
#include <limits>       // std::numeric_limits
#include <climits>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;


map<long long,long long> memo;  
long long unsigned dp(long long unsigned n) {
	if(n>=0 && n<12)  
      {  
           if(! memo[n])  
                memo[n] = n;  
           return memo[n];  
      }  
	 if(!memo[n]) memo[n] = max((dp(n/2)+dp(n/3)+dp(n/4)),n);
	 return memo[n];
}
int main() 
{	long long unsigned input;
	while(cin>>input)
		cout<<dp(input)<<endl;
	
}
