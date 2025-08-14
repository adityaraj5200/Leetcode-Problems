class Solution {
    public String largestGoodInteger(String num) {
        String ans = "";

        for (int i = 2; i < num.length(); ++i) {
            char a = num.charAt(i - 2);
            char b = num.charAt(i - 1);
            char c = num.charAt(i);
            if (a == b && b == c) {
                String good = num.substring(i - 2, i + 1);
                if (good.compareTo(ans) > 0) {
                    ans = good;
                }
            }
        }

        return ans;
    }
}
