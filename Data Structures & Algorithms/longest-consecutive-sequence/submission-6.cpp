class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> count;
        int maxCount = 0;

        for(int num : nums){
            count[num] = 1;
        }

        for(auto val : count){
            int start = 1;
            int currentVal = val.first;
            if(!count.contains(currentVal + 1)){
                while(count.contains(currentVal - 1)){
                    start ++;
                    currentVal --;
                }
            }

            maxCount = max(start, maxCount);
        }

        return maxCount;
    }
};
