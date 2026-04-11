class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,vector<int>>> distances;

        for(int i=0;i<points.size();i++){
            // auto &[x, y] = points[i];
            int x = points[i][0];
            int y = points[i][1];

            int distance = x*x + y*y;

            distances.push_back({distance, points[i]});
        }
        
        sort(distances.begin(), distances.end());

        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(distances[i].second);
        }

        return ans;

    }
};
