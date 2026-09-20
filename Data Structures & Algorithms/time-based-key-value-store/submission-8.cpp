class TimeMap {

private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> keystore;    
public:
    TimeMap() {}
    void set(std::string key, std::string value, int timestamp) {
        keystore[key].emplace_back(timestamp, value);
    }
    
    std::string get(std::string key, int timestamp) {
        auto& values = keystore[key];

        int left = 0;
        int right = values.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) /2;

            if (values[mid].first <= timestamp) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result == -1 ? "" : values[result].second;
    }
};
