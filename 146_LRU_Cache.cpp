/**
 * LRU Cache
 * 
 */
class LRUCache {
private:
    list<pair<int, int>> memory;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    size_t Capacity;
public:
    LRUCache(int capacity): Capacity(capacity) {}
    
    int get(int key) {
        if (map.count(key) == 0) return -1;
        memory.splice(memory.begin(), memory, map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        if (map.count(key)) {
            memory.splice(memory.begin(), memory, map[key]);
            map[key]->second = value;
            return;
        }
        if (memory.size() == Capacity) {
            map.erase(memory.back().first);
            memory.pop_back();
        }
        memory.emplace_front(key, value);
        map[key] = memory.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
