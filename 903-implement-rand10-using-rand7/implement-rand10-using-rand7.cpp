// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while(true) {
            int x = (7 * (rand7() - 1)) + rand7();
            if(x >= 41) continue;
            return ((x % 10) + 1);
        }
    }
};