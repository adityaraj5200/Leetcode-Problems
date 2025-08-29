class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] freq = new int[256];
        int i=0,j=0,n=s.length(),maxLen=0;
        while(i<n && j<n){
            while(freq[s.charAt(j)]==1){
                freq[s.charAt(i)]--;
                i++;
            }

            while(j<n && freq[s.charAt(j)]==0){
                freq[s.charAt(j)]++;
                j++;
            }

            maxLen = Math.max(maxLen, j-i);
        }

        return maxLen;
    }
}