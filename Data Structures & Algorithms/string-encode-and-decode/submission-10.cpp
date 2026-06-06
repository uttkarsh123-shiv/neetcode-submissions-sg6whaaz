class Solution {
public:
    string encode(vector<string>& strs) {
       string encoded_string = "";

       for(int i=0;i<strs.size();i++){
            string length = to_string(strs[i].size());
            encoded_string+=length + "#" + strs[i];
       }

       return encoded_string;
    }

    vector<string> decode(string s) {
    //    135#hello5#world
    vector<string> decoded_strs;

    for(int i=0;i<s.size();){
        int j=i;
        while(s[j] != '#'){
            j++;
        }

        int length = stoi(s.substr(i, j-i));
        string temp = s.substr(j+1, length);

        decoded_strs.push_back(temp);

        i = j+1+length;
    }
    return decoded_strs;
    }
};
