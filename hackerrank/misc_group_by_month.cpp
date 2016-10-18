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

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     string line;
    string range;
    std::getline(cin, range);

    auto start_str = range.substr(0,range.find(","));
    auto end_str = range.substr(range.find(",")+1);
    auto pos = end_str.find_first_not_of(" ");
    if(pos!=string::npos) end_str = end_str.substr(pos);
    int start_date = stoi(start_str.substr(0,start_str.find("-")))*12 + (stoi(start_str.substr(start_str.find("-")+1)));
    int end_date = stoi(end_str.substr(0,end_str.find("-")))*12 + (stoi(end_str.substr(end_str.find("-")+1)));

    string tmp;
    
   std::getline(cin, line);
    map< string, map<string,int> > mp;
    while (std::getline(cin, line)) {
       std::istringstream iss(line);
        vector<string> tokens;
        string item;
        stringstream ss(line);

        while (getline(ss, item,  ',')) {
            tokens.push_back(item);
        }
        auto date_time = tokens[0];
        auto activity = tokens[1].substr(tokens[1].find_first_not_of(" "));
        auto count = tokens[2].substr(tokens[2].find_first_not_of(" "));
        auto pos = date_time.find_last_of("-");
        if(pos!=string::npos) date_time = date_time.substr(0,pos);
        int date_months = stoi(date_time.substr(0,date_time.find("-")))*12 + (stoi(date_time.substr(date_time.find("-")+1)));
        
        if(date_months>=start_date && (date_months<=end_date)) {
            if(stoi(count)) mp[date_time][activity] +=stoi(count);      
        }
    
    }
    for (auto as = mp.rbegin(); as != mp.rend(); ++as) {
        if(!as->second.empty()) {
            cout<<as->first;
            for(auto sec: as->second) {
                cout<<", "<< sec.first << ", " << sec.second;
            }
            cout<<endl;
            
        }
        
    }
    
    return 0;
}
