class Solution {
public:

    string encode(vector<string>& strs) {
        string e;
         for (string x : strs){
            int len = x.length();
            e += '#' + to_string(len) + '#' + x;
         }
        return e;
    }

    vector<string> decode(string s) {
        string ans;
        vector<string> res;

        int i =0;
        while(i < s.length()){
            if(s[i] == '#'){
                i++;
                string x;
                while(s[i] != '#' && i < s.length()){
                    x += s[i];
                    i++;
                }
                i++;
                ans = s.substr(i, stoi(x));
                i += stoi(x);
                res.push_back(ans);
            }
        }
        return res;
    }
};
