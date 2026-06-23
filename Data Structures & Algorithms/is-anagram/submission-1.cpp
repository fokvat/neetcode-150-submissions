class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        int isAna[256] = {0};
        for(int i=0;i<s.length();i++){
            isAna[int(s[i])]++;
            isAna[int(t[i])]--;
        }

        for(int i=0;i<256;i++){
            if(isAna[i] != 0) return false;
        }
        return true;
    }
};
