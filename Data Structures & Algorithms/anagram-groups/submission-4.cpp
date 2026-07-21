class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram;
        for(int i=0;i<strs.size();i++){
            int validCount[26] = {0};

            vector<char> v;
            for(int j=0;j<strs[i].length();j++){
                // validCount[strs[i][j]-'a']++;
                v.push_back(strs[i][j]);
            }

            sort(v.begin(), v.end());
            string countHash = "";
            for(char x : v){
                countHash +=  x;
            }
            anagram[countHash].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto it : anagram){
            result.push_back(it.second);
        }
        return result;
    }
};
