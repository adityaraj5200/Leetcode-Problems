class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 0, n = A.size();
        if(n<3 || A[0]>=A[1])
            return false;
        
        while(i<n-1){
            if(A[i]==A[i+1])
                return false;
            if(A[i]>A[i+1]) 
                break;
            i++;
        }
        
        if(i == n-1)
            return false;
        
        while(i<n-1){
            if(A[i]<=A[i+1])
                return false;
            i++;
        }
        
        return true;
    }
};