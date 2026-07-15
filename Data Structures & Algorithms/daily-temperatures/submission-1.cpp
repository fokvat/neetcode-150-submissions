class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> ans(temperatures.size(), 0);

        for(int i = 0; i<temperatures.size();i++){
            while(!st.empty() && st.top().second < temperatures[i]){
                pair<int, int> temp = st.top();

                cout<<temp.first<<" "<<temp.second<<" "<<i<<endl;
                st.pop();
                ans[temp.first] = i - temp.first;
            }

            st.push({i, temperatures[i]});

        }
        
        return ans;
    }
};
