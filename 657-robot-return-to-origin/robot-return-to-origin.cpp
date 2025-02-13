class Solution {
public:
    bool judgeCircle(string moves) {
        int h=0;
        int v=0;
        for(auto mov:moves){
            switch(mov){
                case 'R':
                 ++h;
                 break;
                case 'L':
                 --h;
                 break;
                case 'U':
                 ++v;
                 break;
                case 'D':
                 --v;
                 break;
                
            }
        }
        return v==0 && h==0;
    }
};