class Solution {
    public int minDeletionSize(String[] strs) {
        int deleteCount = 0, n = strs.length, m = strs[0].length();
        for(int j=0;j<m;j++){
            boolean isSorted = true;
            for(int i=1;i<n;i++){
                if(strs[i].charAt(j) < strs[i-1].charAt(j)){
                    isSorted = false;
                    break;
                }
            }
            if(isSorted == false){
                deleteCount++;
            }
        }

        return deleteCount;
    }
}