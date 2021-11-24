class Solution{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList){
        int i=0,j=0,n=firstList.size(),m=secondList.size();
        vector<vector<int>> result;
        while(i<n && j<m){
            int start1 = firstList[i][0], end1 = firstList[i][1];
            int start2 = secondList[j][0], end2 = secondList[j][1];
            int intersectionWidth = min(end1,end2) - max(start1,start2);
            if(intersectionWidth >= 0)
                result.push_back({max(start1,start2), min(end1,end2)});
            
            if(end1<end2) i++;
            else j++;
        }
        return result;
    }
};