//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        int size = prices.size();
        if(size==0) return 0;
        int currMax = INT_MIN;
       // int buy = prices[0];
        
        
          for (int j = size - 1; j >= 0; j--) {
               if (currMax < prices[j]) {
                      currMax = prices[j];
               } else {
                    profit += (currMax - prices[j]);
                    currMax = prices[j];
               }

         }
        return profit;
    }
};
