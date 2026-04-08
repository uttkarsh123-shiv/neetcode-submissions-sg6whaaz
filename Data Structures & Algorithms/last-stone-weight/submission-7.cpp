class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1) {
            sort(stones.begin(), stones.end());

            int last = stones.back();
            stones.pop_back();

            int secondlast = stones.back();
            stones.pop_back();

            if(last!=secondlast) {
                stones.push_back(last-secondlast);
            }
        }

        return stones.empty() ? 0: stones[0];
    }
};
