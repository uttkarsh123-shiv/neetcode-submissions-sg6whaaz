class Solution {
public:

    bool kokocaneatall(vector<int>& piles, int k, int h) {
        long long hour = 0;
        for(int pile: piles) {
            hour+= (pile +k-1)/k;
        }
    return hour<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int minRate = 1;
        // int maXRate;
        int maxRate = *max_element(piles.begin(), piles.end());

        // int k;
        int totalHours = 0;
        int i=0;
        for(int k=minRate; k<=maxRate;k++) {
            if(kokocaneatall(piles, k, h)) {
                return k;
            }
        }
    return maxRate;
    }
};
