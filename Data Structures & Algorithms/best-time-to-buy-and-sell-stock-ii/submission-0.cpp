class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        int i= 0;

        while(i<n-1){
            int j = i;

            while(j<n-1 && prices[j+1] > prices[j]) j++;

            if(j>i) profit+=prices[j]-prices[i];

            i=j+1;
        }

        return profit;
    }
};