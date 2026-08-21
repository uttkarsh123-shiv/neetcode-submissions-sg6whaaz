class Solution {
public:
    bool isSatisfied(int k, vector<int>&piles, int h){
        long long hour = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i] <= k) hour++;
            else{
              int x = piles[i]/k;
              if(piles[i]%k!=0) x++;

              hour+=x;
            }
        }
        return hour<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
    
        int k=high;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(isSatisfied(mid, piles, h)) {
                k = mid;
                high = mid-1;
            }else low=mid+1;
        }
    return k;
    }
};
