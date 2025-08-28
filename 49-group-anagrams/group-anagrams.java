class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> hm = new HashMap<>();
        for(String str: strs){
            char[] arr = str.toCharArray();
            Arrays.sort(arr);
            String key = new String(arr); // sorted string as key
            hm.computeIfAbsent(key, k -> new ArrayList<>()).add(str);
        }
        return new ArrayList<>(hm.values());
    }
}