class Solution {
private:    
    double r, x, y;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius, x = x_center, y = y_center;
    }
    vector<double> randPoint() {
        double x_rand, y_rand;
        while(true) {
            x_rand = (2 * r * (((double) rand()) / RAND_MAX)) - r;
            y_rand = (2 * r * (((double) rand()) / RAND_MAX)) - r;
            if((x_rand * x_rand) + (y_rand * y_rand) > r * r) continue;
            return {x + x_rand, y + y_rand};
        }
        return {0, 0};
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */