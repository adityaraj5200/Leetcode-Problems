class Solution {
    public int numSubmat(int[][] mat) {
        int m=mat.length,n=mat[0].length;
        int[] height=new int[n];
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1) height[j]+=1;
                else height[j]=0;
            }
            ans+=countRow(height);
        }
        return ans;
    }

    private int countRow(int[] h){
        int n=h.length;
        int[] sum=new int[n];
        Stack<Integer> stk=new Stack<>();
        int res=0;

        for(int j=0;j<n;j++){
            while(!stk.isEmpty() && h[stk.peek()]>=h[j]){
                stk.pop();
            }
            if(!stk.isEmpty()){
                int prev=stk.peek();
                sum[j]=sum[prev]+h[j]*(j-prev);
            }else{
                sum[j]=h[j]*(j+1);
            }
            stk.push(j);
            res+=sum[j];
        }
        return res;
    }
}
