class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long mul = 1;
        int zerocount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zerocount++;
            else mul*= nums[i];
        }
        vector<int> result(nums.size(),1);

        for(int i=0;i<nums.size();i++){
            if(zerocount > 1) result[i] = 0;
            else if(zerocount == 1){
                if(nums[i] == 0) {
                    result[i]=mul;
                }
                else{
                    result[i]=0;
                }
            }
            else {
            result[i] = mul / nums[i];
            }
        }
        return result;
    }
};
