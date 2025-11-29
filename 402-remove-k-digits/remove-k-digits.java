class Solution {
    public String removeKdigits(String num, int k) {
        StringBuilder sbd = new StringBuilder();
        for(char ch: num.toCharArray()){
            while(k>0 && sbd.length()>0 && sbd.charAt(sbd.length()-1)>ch){
                sbd.deleteCharAt(sbd.length()-1);
                k--;
            }
            sbd.append(ch);
        }

        while(k>0 && sbd.length()>0){
            sbd.deleteCharAt(sbd.length()-1);
            k--;
        }

        int firstNonZeroIndex = 0;
        while(firstNonZeroIndex<sbd.length() && sbd.charAt(firstNonZeroIndex)=='0'){
            firstNonZeroIndex++;
        }

        sbd.delete(0,firstNonZeroIndex);

        if(sbd.length()==0){
            sbd = new StringBuilder("0");
        }

        return sbd.toString();
    }
}