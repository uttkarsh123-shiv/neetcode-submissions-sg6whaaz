class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            int com = target-nums[i];
            if(mp.find(com)!=mp.end()){
             int j = mp[target-nums[i]];
             return {min(i,j), max(i,j)};
            }

            mp[nums[i]] = i;
        }
    return {};
    }
};
