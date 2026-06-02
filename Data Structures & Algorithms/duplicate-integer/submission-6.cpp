class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //brute force
        // [1, 2, 3, 3]
        if(nums.size() == 0) return false;
        
        // sort(nums.begin(), nums.end());   //O(nlogn)

        // for(int i=0;i<nums.size()-1;i++){   //O(n) 
        //     if(nums[i] == nums[i+1]) {
        //         return true;
        //     }
        // }
        // return false;




        //optimized code
       unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

       for(auto it: freq){
        if(it.second>1) return true;
       }
       return false;
    }
};