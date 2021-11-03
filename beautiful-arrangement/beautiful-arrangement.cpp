class Solution {
public:
    
    // int helper(int pos,int n,vector<bool>& vis){
    //     if(pos==n+1) return 1;
    //     int sum = 0;
    //     for(int i=1;i<=n;i++){
    //         if((i%pos==0 || pos%i==0) && !vis[i]){
    //             vis[i] = true;
    //             sum += helper(pos+1,n,vis);
    //             vis[i] = false;
    //         }
    //     }
    //     return sum;
    // }
    // void printmask(int n,int mask){
    //     stack<int> stk;
    //     cout<<n<<"->";
    //     while(n--){
    //         stk.push(mask&1);
    //         mask /= 2;
    //     }
    //     while(!stk.empty()){
    //         cout<<stk.top();
    //         stk.pop();
    //     }
    //     cout<<endl;
    // }
    int helper(int pos,int n,int mask){
        if(pos == n+1) return 1;
        int sum = 0;
        for(int i=1;i<=n;i++)
            if((i%pos==0 || pos%i==0) && !(mask & (1<<i)))
                sum += helper(pos+1,n,mask|(1<<i));
        return sum;
    }
    int countArrangement(int n) {
        return helper(1,n,0);
    }
};