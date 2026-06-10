class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int ans = 0;
    //   int len = 1;

      unordered_set<int> st(nums.begin(), nums.end());

      for(auto num: st){
        if(st.count(num-1)) {
            continue;
        }

        int curr = num;
        int len = 1;
        while(st.count(curr+1)){
            curr++;
            len++;
        }

        ans = max(ans, len);
      }
      return ans;
    }
};
