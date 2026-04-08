class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        double answer =0.0;
        int left=0; int right=0;
        vector<int> commonVector;

        while(left<n && right<m) {
            if(nums1[left] <= nums2[right]) {
                commonVector.push_back(nums1[left]);
                left++;
            }
            else{
                commonVector.push_back(nums2[right]);
                right++;
            }
        }

    while (left < n) {
        commonVector.push_back(nums1[left]);
        left++;
    }

    while (right < m) {
        commonVector.push_back(nums2[right]);
        right++;
    }

    int length = commonVector.size();

    int mid = length/2;
    if(length%2 !=0) {
        answer = commonVector[mid];
    }
    else {
         answer = (commonVector[mid-1]+commonVector[mid])/2.0;
    }
    return answer;
    }
};
