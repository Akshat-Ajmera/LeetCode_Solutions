class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx > tx || sy > ty) return false;
        while(tx > sx && ty > sy) {
            if(tx >= ty) tx %= ty;
            else ty %= tx;
        }
        if(tx == sx && ty >= sy) return !((ty - sy) % tx);
        else if(ty == sy && tx >= sx) return !((tx - sx) % ty);
        else return false;
    }
};