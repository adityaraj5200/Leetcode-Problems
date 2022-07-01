class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int> &a, vector<int> &b){
            return a[1]!=b[1] ? a[1]>b[1] : a[0]>b[0];
        });
        int ans = 0;
        for(vector<int> &box: boxTypes){
            int numOfBox = box[0], numOfUnitsPerBox = box[1];
            
            if(numOfBox <= truckSize){
                ans += numOfBox*numOfUnitsPerBox;
                truckSize -= numOfBox;
            }
            else{
                ans += truckSize*numOfUnitsPerBox; 
                // After this truckSize will be emptied, so no need to go furthur.
                break;
            }
        }
        
        return ans;
    }
};