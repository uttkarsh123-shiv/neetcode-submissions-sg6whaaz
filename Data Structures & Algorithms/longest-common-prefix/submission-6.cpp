class Solution {
public:
    int compareStrings(string a, string b){
        int i=0;
        while(i<a.size() && i<b.size()){
            if(a[i]!=b[i]){
                // int length = first+1;
                return i;
            }

            i++;
        }
        return i;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int n = strs.size();


        //curr_prefix
        string curr_prefix = strs[0];
        int prefix_length = curr_prefix.size();

        for(int i=1;i<n;i++){
            int len = compareStrings(curr_prefix, strs[i]);

            curr_prefix = curr_prefix.substr(0, len);

            if(curr_prefix == "") return "";
        }
        return curr_prefix;
    }
};