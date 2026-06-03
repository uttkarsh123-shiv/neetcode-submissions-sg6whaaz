class Solution {
public:
    bool isAnagram(string s, string t) {
        //brute force O(2*n*logn)
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // return s == t;

        //optimized approach
        unordered_map<int,int> mp;

        for(char ch: s){
            mp[ch]++;
        }
        for(char ch: t){
            mp[ch]--;
        }

        for(auto it: mp){
            if(it.second != 0) return false;
        }
        return true;
    }
};
