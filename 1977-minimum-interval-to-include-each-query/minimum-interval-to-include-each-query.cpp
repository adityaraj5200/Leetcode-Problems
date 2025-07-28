class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<vector<int>> pq;// {small interval first, greater right first}
        unordered_map<int, int> queryAnsMap;
        vector<int> Q = queries, ans;
        sort(intervals.begin(), intervals.end());
        sort(Q.begin(), Q.end());
        int i = 0, n = intervals.size();
        for (int q : Q) {
            // Pushing all intervals until interval's lefts don't start crossing q
            // l       q
            //    l    q
            //        lq
            //         q  l (don't push)
            while (i < n && intervals[i][0] <= q) {
                int l = intervals[i][0], r = intervals[i][1];
                int intervalSize = (r-l+1);
                if(r>=q){
                    // {l-----r}-----q This won't contribute
                    pq.push({-intervalSize, r});
                }
                i++;
            }

            // Getting rid of non-contributing windows, those ones whose rights are behind q
            // l--------r     q
            while (pq.size() && pq.top()[1] < q)
                pq.pop();
            queryAnsMap[q] = pq.size() ? -pq.top()[0] : -1;
        }
        for (int q : queries)
            ans.push_back(queryAnsMap[q]);
        return ans;
    }
};