class TaskManager {
private:
    map<int,int> taskIdToUserId;
    map<int,int> taskIdToPriority;
    map<int,set<int>> priorityToTaskIds;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(vector<int>& task: tasks){
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];

            add(userId,taskId,priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskIdToUserId[taskId] = userId;
        taskIdToPriority[taskId] = priority;
        priorityToTaskIds[priority].insert(taskId);
    }
    
    void edit(int taskId, int newPriority) {
        rmv(taskId);
        priorityToTaskIds[newPriority].insert(taskId);
        taskIdToPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int priority = taskIdToPriority[taskId];
        taskIdToPriority.erase(taskId);
        priorityToTaskIds[priority].erase(taskId);
        if(priorityToTaskIds[priority].size() == 0){
            priorityToTaskIds.erase(priority);
        }
    }
    
    int execTop() {
        if(priorityToTaskIds.size()==0) return -1;

        int highestPriority = priorityToTaskIds.rbegin()->first;
        int highestTaskId = *(priorityToTaskIds[highestPriority].rbegin());
        int userId = taskIdToUserId[highestTaskId];
        rmv(highestTaskId);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */