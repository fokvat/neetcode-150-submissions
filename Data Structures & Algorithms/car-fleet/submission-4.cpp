class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> final;
        int carFleet = 0;
        double lastTime = -1;

        for(int i =0; i < position.size(); i++){
            double x = (double)(target - position[i]) / speed[i];
            final.push_back({position[i], x});
        }
        sort(final.begin(), final.end(), greater<pair<int, int>>());

        for(auto s : final){
            if(s.second > lastTime){
                carFleet++;
                lastTime = s.second;
            }
        }
        
        return carFleet;
    }
};
