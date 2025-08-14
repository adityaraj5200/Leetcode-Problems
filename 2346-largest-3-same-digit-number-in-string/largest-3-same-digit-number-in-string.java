class Solution {
    public String largestGoodInteger(String num) {
        Integer ans = -1;
        for(int i=0;i<num.length()-2;i++){
            if(num.charAt(i)==num.charAt(i+1) && num.charAt(i+1)==num.charAt(i+2)){
                int digit = num.charAt(i)-'0';
                if(digit > ans){
                    ans = digit;
                }
            }
        }

        if(ans == -1){
            return "";
        }
        else{
            StringBuilder sbd = new StringBuilder();
            sbd.append(ans.toString());
            sbd.append(ans.toString());
            sbd.append(ans.toString());

            return sbd.toString();
        }
    }
}