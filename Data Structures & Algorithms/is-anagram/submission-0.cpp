class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        unordered_map<char, int> s1;

        for(int i=0;i<s.length();i++){
            s1[s[i]]++;
            s1[t[i]]--;
        }

        for(auto a : s1){
            if(a.second != 0) return false;
        }
        return true;
    }
};
