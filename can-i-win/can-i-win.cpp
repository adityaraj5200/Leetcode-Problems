class Solution {
public:
    // int mem[1<<20] = {};
    vector<int> mem = vector<int>(1<<20,0);
    bool canIWin(int maxChoosableInteger, int desiredTotal){
        int M = maxChoosableInteger,T = desiredTotal, sum = M*(M+1)/2;
        if (T < 2) return true;
        if (sum < T) return false;
        if (sum == T) return maxChoosableInteger&1;

        return dfs(M, T, 0);
    }
    
     bool dfs(int M, int T, int k) 
     {
       if (mem[k] != 0) return mem[k]==1;
       // total is already reached by opponent, so I lose
       if (T <= 0) return false;
       // try all currently available numbers
       for (int i = 0; i < M; ++i)
         // if (i+1) is available to pick and my opponent can't win after I picked, I win!
         if (!(k&(1<<i)) && !dfs(M, T-i-1, k|(1<<i))) {
           mem[k] = 1;
           return true;
         }
       // Otherwise, I will lose
       mem[k] = -1;
       return false;      
     }
};