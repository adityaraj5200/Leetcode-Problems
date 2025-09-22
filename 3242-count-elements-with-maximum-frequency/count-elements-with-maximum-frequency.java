class Solution {
    public int maxFrequencyElements(int[] nums) {
        int maxFreq = 0;
        Map<Integer,Integer> hm = new HashMap<>();
        for(int num: nums){
            hm.put(num, hm.getOrDefault(num, 0)+1);
            maxFreq = Math.max(maxFreq, hm.get(num));
        }

        int cnt = 0;
        for(int f: hm.values()){
            if(f == maxFreq){
                cnt += maxFreq;
            }
        }

        return cnt;
    }
}