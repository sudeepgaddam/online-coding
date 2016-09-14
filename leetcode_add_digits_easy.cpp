/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Show Hint 
*/
class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num){
            sum=sum+(num%10);
            if(sum>=10){
                auto temp = sum;
                auto new_sum = 0;
                while(temp) {
                    new_sum+=temp%10;
                    temp/=10;
                    //cout<<"temp"<<temp<<endl;
            }
            sum = new_sum;
            //cout<<sum<<endl;
            }
            num=num/10;
        }
        
        return sum;
        
    }
};
/*
Solution based on digital root.
Its num%9  if result is not equal to 0
or 1 + (num-1)%9
*/
class Solution {
public:
    int addDigits(int num) {
        if(!num) return 0; 
      return (num%9)?num%9:9;
        
    }
};
