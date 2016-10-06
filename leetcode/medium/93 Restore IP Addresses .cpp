/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

*/


/*
Todo: Rework on it and make it clean
I did not like this solution but Hey, It works (After lot of edits)
*/
class Solution {
public:

     bool isValidIP(string s, int start, int end) {
        //  cout << s.substr(start, end-start+1) << endl;
         auto ip = stoi(s.substr(start, end-start+1));
        //  cout << "IP " << ip <<endl;
         if( (ip >=0) && (ip<=255)) return true;
        return false;
    }
    
    void rec(string s, int start, int end, vector<string> &res, string curr, int dots) {
        if(dots>4) return;
        if((dots==4 ) && (start==(s.size()))) {
        //if(start >= (end)){
        //  cout << "curr " << curr << endl;
          res.push_back(curr);
        }
        int min_end = min(end, start+3);
        for(int i=start;i<=min_end;i++) {
            auto new_curr = curr;
            if(isValidIP(s, start, i)){ 
                // cout << "Valid IP" << endl;
                new_curr+=(s.substr(start, i-start+1));
               // cout << new_curr << endl;
                if(dots<3) new_curr+=".";
                
                // cout << new_curr << endl;
                rec(s, i+1, end, res, new_curr,dots+1);
            }
            
           if(s[start]=='0') break;
        }
    }

    
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> res ; 
        string curr;
        int dots = 0;
        rec(s, 0, s.size()-1, res, curr, dots);
        return res;  
        
    }
};
