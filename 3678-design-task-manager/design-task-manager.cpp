// Some 14ms runtime guy
class TaskManager {
public:
    unordered_map<int, pair<int, int>> mpp;
    priority_queue<pair<int, int>> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto& task : tasks){
            mpp[task[1]] = {task[2], task[0]};
            pq.push({task[2], task[1]});
        }    
    }
    
    void add(int userId, int taskId, int priority) {
        mpp[taskId] = {priority, userId};
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        mpp[taskId].first = newPriority;
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        mpp[taskId].first = -1;
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [priority, taskId] = pq.top();

            if(mpp[taskId].first == priority){
                mpp[taskId].first = -1;
                pq.pop();
                return mpp[taskId].second;
            }
            else{
                pq.pop();
            }
        }

        return -1;
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