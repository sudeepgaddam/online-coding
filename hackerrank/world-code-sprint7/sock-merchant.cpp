/*
John's clothing store has a pile of  loose socks where each sock  is labeled with an integer, , denoting its color. He wants to sell as many socks as possible, but his customers will only buy them in matching pairs. Two socks,  and , are a single matching pair if .

Given  and the color of each sock, how many pairs of socks can John sell?

Input Format

The first line contains an integer, , denoting the number of socks. 
The second line contains  space-separated integers describing the respective values of .

Constraints

Output Format

Print the total number of matching pairs of socks that John can sell.

Sample Input

9
10 20 20 10 10 30 50 10 20
Sample Output

3

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    unordered_map<int, int> mp;
    int count =0;
    int tmp;
    for(int i=0;i<N;i++) {
        cin>>tmp;
        if(mp[tmp]){count++;
                   mp[tmp]--;}
        else {
            mp[tmp]++;
        }
        
    }
    cout<< count<< endl;
    return count;
}
