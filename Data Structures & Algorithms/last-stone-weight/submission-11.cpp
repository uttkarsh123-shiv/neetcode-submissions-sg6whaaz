class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq(stones.begin(), stones.end());

    while(pq.size()>1){
        int last = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        if(last!=second){
            pq.push(last-second);
        }
    }

    return pq.empty()? 0: pq.top();
    }
      
};
