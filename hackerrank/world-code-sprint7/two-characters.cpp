/*

String  always consists of two distinct alternating characters. For example, if string 's two distinct characters are x and y, then t could be xyxyx or yxyxy but not xxyy or xyyx.

You can convert some string  to string  by deleting characters from . When you delete a character from , you must delete all occurrences of it in . For example, if  abaacdabd and you delete the character a, then the string becomes bcdbd.

Given , convert it to the longest possible string . Then print the length of string  on a new line; if no string  can be formed from , print  instead.

Input Format

The first line contains a single integer denoting the length of . 
The second line contains string .

Constraints

 only contains lowercase English alphabetic letters (i.e., a to z).
Output Format

Print a single integer denoting the maximum length of  for the given ; if it is not possible to form string , print instead.

Sample Input

10
beabeefeab
Sample Output

5
Explanation

The characters present in  are a, b, e, and f. This means that  must consist of two of those characters.

If we delete e and f, the resulting string is babab. This is a valid  as there are only two distinct characters (a and b), and they are alternating within the string.

If we delete a and f, the resulting string is bebeeeb. This is not a valid string  because there are three consecutive e's present.

If we delete only e, the resulting string is babfab. This is not a valid string  because it contains three distinct characters.

Thus, we print the length of babab, which is , as our answer.

*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>


//put positions of characters in map
//take two at a time
//if they alternate, proceed
//else chuck that pair and move on..do with two for loops
using namespace std;
int max_length=0;
bool check_validity(map<char,vector<int>> &mp, string s,char first, char second){
    
    auto f_list = mp[first];
    auto s_list = mp[second];
    
    int size1=  mp[first].size();
    int size2=  mp[second].size() ;
    
    if(abs(size1-size2) >1) return false;
    
    
     if(mp[first][0] > mp[second][0]){
         if(mp[first].size() > mp[second].size() ) return false;
     } else if(mp[second][0] > mp[first][0]){
         if(mp[second].size() > mp[first].size() ) return false;
     }
    int size = f_list.size()+ s_list.size();
    int fp, sp;
    bool first_less = false;
    fp = f_list[0];
    sp = s_list[0];
    if(fp < sp) first_less =true;
    for(int i=1;i<min(f_list.size(), s_list.size()); i++) {
        if(first_less && (f_list[i] > s_list[i] ))  return false;
                if(!first_less && (f_list[i] < s_list[i] ))  return false;

        if(f_list[i] < sp) return false;
        if(s_list[i] < fp) return false;
        fp = f_list[i];
        sp = s_list[i];
    }
    if(size1<size2) {
        if(s_list.back() < fp) return false;
    } else if(size1 > size2) {
        if(f_list.back() < sp) return false;
    }
    max_length = max(max_length, size);
    return true;
    
}
int main(){
    int len;
    cin >> len;
    
    
    string s;
    cin >> s;  
    int size = s.size();
    vector<int> cnt(26,0);
    map<char,vector<int>> mp;
    for(int i=0;i<size;i++) {
        char a = s[i];
        mp[a].push_back(i);
        cnt[a-'a']++;
    }
    char first, second;
    for(int i=0;i<26;i++) {
        if(cnt[i]) first = 'a'+i;   
        else continue;
        for(int j=i+1;j<26;j++) {
            if(cnt[j]) second = 'a'+j;   
            else continue;
            check_validity(mp, s, first, second);
            
        }        
    }
    //int cnt[26];
    cout << max_length << endl;
    return 0;
}
