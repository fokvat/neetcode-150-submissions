class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWaterStore = -1;

        int i = 0;
        int j = heights.size()-1;

        while(i<j){
            int waterStore = min(heights[i], heights[j]) * (j-i);
            maxWaterStore = max(maxWaterStore, waterStore);
            if(heights[i] < heights[j]) i++;
            else j--;
        }

        return maxWaterStore;
    }
};
 