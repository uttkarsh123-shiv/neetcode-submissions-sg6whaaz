class Solution {
public:
   bool searchMatrix(vector<vector<int>>& a, int target) {
    int n = a.size();
    int m = a[0].size();

    for (int i = 0; i < n; i++) {
        if (target < a[i][0])
            return false;

        if (target > a[i][m - 1])
            continue;

        int l = 0, r = m - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (a[i][mid] == target)
                return true;
            else if (a[i][mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return false;
    }

    return false;
}
};
