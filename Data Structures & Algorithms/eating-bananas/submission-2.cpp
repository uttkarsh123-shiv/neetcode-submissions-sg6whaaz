class Solution {
public:
    bool canEatAllBanana(vector<int>& piles, int mid, int h) {
        int hour=0;

        for(int pile: piles) {
            hour+= pile/mid;

            if(pile%mid!=0) hour++;
        }

        return hour<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
      int n=piles.size();
      int low =1;
      int high = *max_element(piles.begin(), piles.end());
    int ans;

      while(low<=high) {
        int mid = low +(high-low)/2;

        if(canEatAllBanana(piles, mid, h)) {
            ans = mid;
            high = mid-1;
        }
        else {
            low=mid+1;
        }
      }
      return ans;
    }
};
