class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;

        int maxFreq = 0;
        int maxLen = 0;
        vector<int> freq(26, 0);
        for(int r=0;r<n;r++)
        {
            freq[s[r]-'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            int window_size = r-l+1;
            
            int replacements = window_size - maxFreq;
            if(replacements > k){
                freq[s[l]-'A']--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
