public class LRUCache {
    private class Node {
        int key;
        int value;
        Node prev;
        Node next;
        public Node(int k, int v) {
            key = k;
            value = v;
        }
    }

    private final int capacity;
    private Map<Integer, Node> map;
    private Node head;   // dummy head
    private Node tail;   // dummy tail

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        Node node = map.get(key);
        if (node == null) {
            return -1;
        }
        // move the accessed node to head (most recently used)
        moveToHead(node);
        return node.value;
    }

    public void put(int key, int value) {
        Node node = map.get(key);
        if (node != null) {
            // Key already exists — update value and move to head
            node.value = value;
            moveToHead(node);
        } else {
            // New key — create node
            Node newNode = new Node(key, value);
            map.put(key, newNode);
            addToHead(newNode);

            if (map.size() > capacity) {
                // remove LRU item
                Node lru = tail.prev;
                removeNode(lru);
                map.remove(lru.key);
            }
        }
    }

    // remove node from its current position
    private void removeNode(Node node) {
        Node prev = node.prev;
        Node next = node.next;
        prev.next = next;
        next.prev = prev;
    }

    // add node right after head
    private void addToHead(Node node) {
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;
    }

    // move an existing node to the head
    private void moveToHead(Node node) {
        removeNode(node);
        addToHead(node);
    }
}
