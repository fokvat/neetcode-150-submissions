class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> charSet;
        int i=0;
        int j = 0;
        int maxSubString = 0;
        // if (s.length() == 0)
        //     return 0;
        // if (s.length() == 1)
        //     return 1;

        // charSet[s[0]] = true;


        while(j<s.length()){
            if(!charSet.contains(s[j])){
                charSet.emplace(s[j], true);
                j++;
            }else{
                while (charSet.contains(s[j])){
                    charSet.erase(s[i]);
                    i++;
                }
                // charSet.emplace(s[j], true);
                // j++;
            }
            maxSubString = max(j-i, maxSubString);

        }

        return maxSubString;
        
    }
};
