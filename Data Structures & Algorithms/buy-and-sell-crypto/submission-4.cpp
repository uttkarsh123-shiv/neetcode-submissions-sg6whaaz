class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProfit = INT_MIN;
        int minPrice = prices[0];

        for(int i=1;i<n;i++){
            if(minPrice < prices[i]) {
                maxProfit = max(maxProfit, (prices[i]-minPrice));
            }

            else if(prices[i] < minPrice) minPrice = prices[i];
        }

        return maxProfit == INT_MIN ? 0 : maxProfit;
    }
};
