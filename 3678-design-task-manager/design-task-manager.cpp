// Time Complexity:
//   TaskManager(constructor): O(m log m), where m = initial number of tasks
//   add, edit, rmv, execTop: O(log n) each in average, where n = current number of tasks in system
// Space Complexity: O(n + m), for storing all tasks in maps/sets/heap
struct Task {
    int userId;
    int taskId;
    int priority;
    Task() {}
    Task(int u, int t, int p): userId(u), taskId(t), priority(p) {}
    // We want highest priority first; if tie, highest taskId first
    bool operator<(const Task& o) const {
        if (priority != o.priority)
            return priority > o.priority; // higher priority first
        return taskId > o.taskId;         // if tie, higher taskId first
    }

};

class TaskManager {
private:
    // Map from taskId -> (userId, priority) for quick lookups/updates/removals
    unordered_map<int, pair<int,int>> taskMap;
    // Balanced structure to get top task in O(log n) and to delete arbitrary tasks
    // Use set with comparator (or priority_queue + lazy deletion)
    set<Task> taskSet;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &task: tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        // insert into map and set
        Task t(userId, taskId, priority);
        taskMap[taskId] = {userId, priority};
        taskSet.insert(t);
    }
    
    void edit(int taskId, int newPriority) {
        auto it = taskMap.find(taskId);
        if (it == taskMap.end()) return;  // or throw, but given problem guarantees existence
        
        int oldUser = it->second.first;
        int oldPriority = it->second.second;
        Task oldTask(oldUser, taskId, oldPriority);
        
        // remove old
        taskSet.erase(oldTask);
        // add updated
        Task newTask(oldUser, taskId, newPriority);
        taskSet.insert(newTask);
        
        // update map
        it->second.second = newPriority;
    }
    
    void rmv(int taskId) {
        auto it = taskMap.find(taskId);
        if (it == taskMap.end()) return;
        int userId = it->second.first;
        int priority = it->second.second;
        Task t(userId, taskId, priority);
        taskSet.erase(t);
        taskMap.erase(it);
    }
    
    int execTop() {
        if (taskSet.empty()) return -1;
        // The begin of set is the “largest” task per comparator
        auto it = taskSet.begin();
        Task t = *it;
        taskSet.erase(it);
        taskMap.erase(t.taskId);
        return t.userId;
    }
};
