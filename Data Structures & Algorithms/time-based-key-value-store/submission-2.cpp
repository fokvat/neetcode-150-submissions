class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp) {
        const auto& temp = mp[key];
        if(temp.size() <= 0) {
             return "";
        }
        int start = 0;
        int end = temp.size() - 1;
        string res = "";
        while(start <= end){
            int mid = (start + end) / 2;
            if(temp[mid].first > timestamp) end = mid - 1;
            else if(temp[mid].first < timestamp){
                res = temp[mid].second;
                start = mid + 1;
            }else{
                res = temp[mid].second;
                break;
            }
        }
        return res;
    }
};