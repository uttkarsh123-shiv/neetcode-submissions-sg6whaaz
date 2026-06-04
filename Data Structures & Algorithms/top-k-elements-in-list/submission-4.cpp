class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;    //O(n)
    
        for(int i=0;i<nums.size();i++){   // O(n)
            mp[nums[i]]++;
        }

        vector<pair<int,int>> v;     // O(n)
        for(auto it: mp){        
            v.push_back({it.first, it.second});
        }

        sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int>&b){
            return a.second > b.second;
        });
        
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(v[i].first);
        }
        return result;
    }
};
