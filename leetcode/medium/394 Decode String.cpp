/*

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

*/


class Solution {
public:
    string rec(string sub) {
        
        stack<char> st;
        int i=0;
        string num;
        //Get the num first
        bool outer = true;
        string res;
        // cout<<"Rec called " <<sub<< endl;
        while((i<sub.size())) {
            
            if(outer && isdigit(sub[i])) {
                num ="";
                while(i<sub.size() && isdigit(sub[i])){
                    num+=sub[i];
                    i++;  
                }
                // cout<<num << endl;
                outer = false;
            } else if(sub[i]=='[') {
                st.push(i);
            } else if(sub[i]==']') {
                if(st.size()==1) {
                    auto closing =i;
                    auto opening = st.top();
                   auto ret = rec(sub.substr(opening+1, closing-opening-1));
                    int rep = stoi(num);

                    for(int i=0;i<rep;i++) {
                        res+=ret;
                    }
                    
                   outer = true; 
                    
                }
                st.pop();
            }

            if(outer && isalpha(sub[i]))
                res+=sub[i];
             
           i++;  
             
        }
        return res;
 
    }
    string decodeString(string s) {
        return rec(s);
    }
};
