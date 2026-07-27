class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<pair<int, int>> st;

        for(int i = 0; i < n; i++){
            if(st.empty() || st.top().second < heights[i]) {
                st.push({i, heights[i]});
                continue;
            }

            pair<int, int> top = st.top();
            int extendLeft = i;
            // top heights is greater than heights[i]
            while(!st.empty() && top.second > heights[i]){
                st.pop();
                //Calculate Area
                maxArea = max(maxArea, (top.second * (i - top.first)));
                extendLeft = top.first;
                top = st.top();
            }

            st.push({extendLeft, heights[i]});
        }

        while(!st.empty()){
            pair<int, int> top = st.top();
            st.pop();
            //Calculate Area
            maxArea = max(maxArea, (top.second * (n - top.first)));
        }

        return maxArea;

    }
};
