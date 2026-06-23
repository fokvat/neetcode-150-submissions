class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> frequentElement;
        map<int, vector<int>> buck_sort;
        unordered_map<int, int> count;

        for (int it : nums){
            if (count.find(it) == count.end()){
                count[it] = 1;
            }
            else{
                count[it] += 1;
            }
        }

        for(auto count_pair : count){
            buck_sort[count_pair.second].push_back(count_pair.first);
        }

        int temp = k;
        for(auto it = buck_sort.rbegin(); it != buck_sort.rend(); it++){
            for(auto x : it->second){
                frequentElement.push_back(x);
                temp --;
                if (temp == 0) return frequentElement;
            }
        }

        return frequentElement;
    }
};
