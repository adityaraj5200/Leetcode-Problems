class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0;
        #define right 0
        #define left 2
        #define down 1
        #define up 3
        
        for(int i=0;i<4;i++){
            for(char &ch: instructions){
                if(ch=='G'){
                    if(dir==right) y++;
                    else if(dir==left) y--;
                    else if(dir==up) x--;
                    else if(dir==down) x++;
                }
                else{
                    dir = ch == 'L' ? dir-1 : dir+1;
                    dir = (dir+4)%4;
                }
            }
        }
        
        return x==0 && y==0;
    }
};