class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProfit = INT_MIN;

        for(int i=0;i<n;i++){
            int boughtPrice = prices[i];
            int profit = 0;
            for(int j=i+1;j<n;j++){
                int soldPrice = prices[j];
                if(soldPrice > boughtPrice)
                profit = soldPrice - boughtPrice;
                maxProfit = max(maxProfit, profit);
            }

        }

        return maxProfit == INT_MIN ? 0 : maxProfit;
    }
};
