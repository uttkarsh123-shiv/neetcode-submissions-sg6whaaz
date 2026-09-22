class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2*nums.size());


        for(int i=0;i<ans.size();i++){
            if(i >= nums.size()) {
                int index = i%nums.size();
                ans[i]  = nums[index]; 
            }
            else
            ans[i] = nums[i];
        }

        return ans;

    }
};