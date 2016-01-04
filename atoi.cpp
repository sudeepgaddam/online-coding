/*
  *1047 / 1047 test cases passed.
	*Status: Accepted
  *Runtime: 8 ms
 */

class Solution {
public:
    int myAtoi(string str) {
        //vector<int> abc;
        int neg = 0;
        int start = 0;
        bool num_started = false;
        int mult = 10;
        long int num=0;
        int count = 0;

        for(int i=start;i<str.size();i++) {
            if(str[i]>='0' && str[i]<='9') {
                //abc.push_back();
                if(count++>10) return (neg==2)?INT_MIN:INT_MAX;
                num=(num*mult)+(str[i]-'0');
            if(num>INT_MAX) break;
                num_started = true;
            } else {
                    if(num_started) break;
                    else {
                        
                        if(str[i]==' ') {}
                        else if (str[i] == '+') {
                            if(neg) return 0;
                            neg = 1;
                            num_started = true;
    
                        }
                else if (str[i] == '-') {
                    if(neg) return 0;
                    neg = 2;
                    num_started = true;
                } else return 0;
                    
                }
            }
        }
        
        
        return (neg==2)? (num>INT_MAX)?INT_MIN:-1*num : (num>INT_MAX)?INT_MAX:num;
        
    }
};
