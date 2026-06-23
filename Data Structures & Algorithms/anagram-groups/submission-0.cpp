class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for (string x : strs){
            vector<int> a(27, 0);
            for(char z : x){
                a[z-'a']++;                
            }
            string k = to_string(a[0]);
            for (int i=1;i<27;i++){
                k += ',' + to_string(a[i]);
            }
            mp[k].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
