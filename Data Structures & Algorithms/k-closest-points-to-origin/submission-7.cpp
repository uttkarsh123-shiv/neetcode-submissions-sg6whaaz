class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<int, vector<int>>> maxHeap;

        for(auto&p: points){
            int dist = p[0]*p[0]+p[1]*p[1];

            maxHeap.emplace(dist, p);

            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> ans;

        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
