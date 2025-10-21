// Time Complexity: O(1) per get() and put() operation
// Space Complexity: O(capacity)
class LFUCache {
    int capacity, minFreq;
    unordered_map<int,pair<int,int>> keyToValFreq; // key → {value, frequency}
    unordered_map<int,list<int>> freqList;         // frequency → list of keys (LRU order)
    unordered_map<int,list<int>::iterator> pos;    // key → iterator in freqList[frequency]

public:
    LFUCache(int capacity): capacity(capacity), minFreq(0) {}

    int get(int key) {
        if(!capacity || keyToValFreq.find(key) == keyToValFreq.end())
            return -1;

        auto &[value,freq] = keyToValFreq[key];
        // Remove key from old frequency list
        freqList[freq].erase(pos[key]);
        if(freqList[freq].empty() && freq == minFreq)
            minFreq++; // increase minFreq if old list is empty

        // Move key to next frequency list
        freq++;
        freqList[freq].push_back(key);
        pos[key] = --freqList[freq].end();

        return value;
    }

    void put(int key, int value) {
        if(capacity == 0) return;

        // If key already exists → update value and promote frequency
        if(keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value;
            get(key); // reuse get() to handle frequency update
            return;
        }

        // If cache is full → evict least frequent + least recently used
        if(keyToValFreq.size() == capacity) {
            int delKey = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            keyToValFreq.erase(delKey);
            pos.erase(delKey);
        }

        // Insert new key with frequency = 1
        keyToValFreq[key] = {value,1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1; // reset minFreq after adding new key
    }
};