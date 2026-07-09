class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> charSet;
        int i=0;
        int j = i+1;
        int maxSubString = 1;
        if (s.length() == 0)
            return 0;
        if (s.length() == 1)
            return 1;

        charSet[s[0]] = true;


        while(i<j and i<s.length() and j<s.length()){
            if(!charSet.contains(s[j])){
                charSet.emplace(s[j], true);
                maxSubString = max(j-i + 1, maxSubString);
                j++;
            }else{
                while (charSet.contains(s[j])){
                    charSet.erase(s[i]);
                    i++;
                }
                charSet.emplace(s[j], true);
                j++;
            }
        }

        return maxSubString;
        
    }
};
