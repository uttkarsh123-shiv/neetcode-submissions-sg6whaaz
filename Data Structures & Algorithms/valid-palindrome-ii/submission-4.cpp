class Solution {
public:
    bool isPalindrome(string s){
        int l = 0;
        int r = s.size()-1;

        while(l<r){
            if(s[l]!=s[r]) return false;

            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();

        if(isPalindrome(s)) return true;

        for(int i=0;i<=n-1;i++) {
            string temp = s.substr(0, i) + s.substr(i+1);
            if(isPalindrome(temp)) return true;
        }
        return false;
    }
};