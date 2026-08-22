class Solution {
public:
    bool isValid(int mid,vector<int>& weights, int d){
        int days = 1;
        int load = 0;

        for(int w: weights){
            if(load + w <= mid) load += w;
            else{
                days++;
                load = w;
            }
        }

        return days <= d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(isValid(mid, weights, days)){
                ans = mid;
                high = mid-1; 
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};