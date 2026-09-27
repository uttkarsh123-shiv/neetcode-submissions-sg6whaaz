class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;

        for(int &num: nums){
            mp[num]++;
        }

        int min = 0;

        int max = 2;

        int k = 0;
        for(int i=0;i<=2;i++){
            while(mp[i]>0){
                nums[k++] = i;
                mp[i]--;
            }
        }
    }
};