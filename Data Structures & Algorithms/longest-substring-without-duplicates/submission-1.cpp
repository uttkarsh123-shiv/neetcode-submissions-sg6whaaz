class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        unordered_set<char> seen;

        int l = 0;
        for(int r=0;r<n;r++){
            while(seen.count(s[r])){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            maxLen = max(maxLen, r-l+1);
        }
        
        return maxLen;
    }
};
