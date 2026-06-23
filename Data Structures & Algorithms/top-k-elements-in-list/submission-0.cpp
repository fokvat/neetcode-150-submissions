
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        map<int, vector<int>> buc_sort;

        for(int x : nums){
            if(count.find(x) == count.end()) count[x] = 1;
            else count[x] ++;
        }

        for(auto x : count){
            buc_sort[x.second].push_back(x.first);
        }

        int temp = k;
        vector<int> ans;
        for(auto it = buc_sort.rbegin(); it != buc_sort.rend(); it++){
            for(int x : (*it).second){
                ans.push_back(x);
                temp --;
                if(temp == 0) return ans;
            }
        }

        return {};
    }
};
