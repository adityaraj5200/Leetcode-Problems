class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int> &a,vector<int> &b){return a[1] < b[1];});
        
        priority_queue<int> maxheap;
        int totalDuration = 0;
            
        for(auto course: courses){
            int &duration = course[0], &lastDay = course[1];
            totalDuration += duration;
            maxheap.push(duration);
            while(totalDuration > lastDay){
                totalDuration -= maxheap.top();
                maxheap.pop();
            }
        }
        
        return maxheap.size();
    }
};