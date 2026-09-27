class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
      int n = nums.size();

      unordered_map<int,int> mp;

      for(int &n: nums){
        mp[n]++;
      }  

      int maxE = *max_element(nums.begin(), nums.end());
      int minE = *min_element(nums.begin(), nums.end());


        int k  = 0;
      for(int i=minE;i<=maxE;i++){
        while(mp[i]>0){
            nums[k] = i;
            k++;
            mp[i]--;
        }
      }

      return nums;
    }
};