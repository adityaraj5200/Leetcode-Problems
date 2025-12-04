public class LFUCache {
    private final int capacity;
    private int minFreq;
    private Map<Integer, Node> keyToNode;            // key → Node (holds key, value, freq)
    private Map<Integer, LinkedHashSet<Integer>> freqToKeys;  
    // freq → keys with that freq (as a LinkedHashSet to preserve insertion order for LRU among same freq)

    private static class Node {
        int key;
        int value;
        int freq;
        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    }

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.minFreq = 0;
        this.keyToNode = new HashMap<>();
        this.freqToKeys = new HashMap<>();
    }

    public int get(int key) {
        if (!keyToNode.containsKey(key)) {
            return -1;
        }
        Node node = keyToNode.get(key);
        int oldFreq = node.freq;
        // remove from current freq list
        freqToKeys.get(oldFreq).remove(key);
        // if this list was the list of minFreq and is now empty → we may need to bump minFreq
        if (oldFreq == minFreq && freqToKeys.get(oldFreq).isEmpty()) {
            minFreq++;
        }

        // increase freq
        node.freq++;
        int newFreq = node.freq;
        freqToKeys.computeIfAbsent(newFreq, k -> new LinkedHashSet<>());
        freqToKeys.get(newFreq).add(key);

        return node.value;
    }

    public void put(int key, int value) {
        if (capacity <= 0) return;

        if (keyToNode.containsKey(key)) {
            // update existing key's value — and treat as access: increases its frequency
            keyToNode.get(key).value = value;
            get(key);  // reuse get logic to bump freq
            return;
        }

        // if capacity full → evict least frequently used key
        if (keyToNode.size() >= capacity) {
            // find the LFU key with minFreq, and among them the least recently used → first in LinkedHashSet
            LinkedHashSet<Integer> lfuKeys = freqToKeys.get(minFreq);
            int evictKey = lfuKeys.iterator().next();
            lfuKeys.remove(evictKey);
            keyToNode.remove(evictKey);
        }

        // insert new key
        Node newNode = new Node(key, value);
        keyToNode.put(key, newNode);
        minFreq = 1;
        freqToKeys.computeIfAbsent(1, k -> new LinkedHashSet<>());
        freqToKeys.get(1).add(key);
    }
}
