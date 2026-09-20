class TimeMap {

private:
     std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> values;   
public:
    TimeMap() {
        
    }
    
    void set(std::string key, std::string value, int timestamp) {
        values[key].push_back({timestamp, value});
    }
    
    std::string get(std::string key, int timestamp) {
        if (!values.count(key))
        return "";

        const auto& entries = values[key];

        int left = 0;
        int right = entries.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (entries[mid].first <= timestamp) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (result == -1) 
        return "";

        return entries[result].second;
    }
};
