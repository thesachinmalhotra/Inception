class LRUCache {

private: 
       using Node = std::pair<int, int>;

       int capacity;
       std::list<Node> cache;
       std::unordered_map<int, std::list<Node>::iterator> map;

       void makeRecent(int key) {
        auto node = map [key];
        cache.splice(cache.end(), cache, node);
       }    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (!map.count(key))
        return -1;

        makeRecent(key);
        return map[key]->second;
        
    }
    
    void put(int key, int value) {
        if (map.count(key)) {
            map[key]->second = value;
            makeRecent(key);
            return;
        }

        cache.emplace_back(key, value);
        map[key] = std::prev(cache.end());

        if (cache.size() > capacity) {
            int keyToRemove = cache.front().first;
            map.erase(keyToRemove);
            cache.pop_front();
        }
    }
};
