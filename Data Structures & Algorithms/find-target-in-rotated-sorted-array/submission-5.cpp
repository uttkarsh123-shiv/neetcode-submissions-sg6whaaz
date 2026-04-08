class Solution {
public:
    int dobinarySearch(int i,int j,vector<int>& nums, int target)
    {
        int low = i;
        int high = j;
        int mid;
        while(low<=high) {
            mid = low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(target<nums[mid]) {
                high=mid-1;
            }
            else low = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<high) {
            int mid = low+(high-low)/2;

            if(nums[mid]>nums[high]) low = mid+1;
            else high = mid;
        }
        int pivot = low;
    int left = dobinarySearch(0, pivot-1, nums, target);
    if(left!=-1) return left;

    return dobinarySearch(pivot, n-1, nums, target);
    }
};
