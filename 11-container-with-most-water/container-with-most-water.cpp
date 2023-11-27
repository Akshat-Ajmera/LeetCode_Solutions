class Solution {
public:
    int maxArea(vector<int> &h) {
        int n = h.size(), i = 0, j = n-1, area = ((j-i)*min(h[i],h[j]));
        while(i<j) {
            if(h[i] < h[j]) {
                i++;
            }
            else {
                j--;
            }
            area = max(area,((j-i)*min(h[i],h[j])));
        }
        return area;
    }
};


/*
            if(h[i] < h[j]) {
                i++;
            }
            else {
                j--;
            }

    we move the ptr with the min height because we know we cant get a better ans than this
    if we move the ptr with the longer height, than we have 3 cases
    the next height is longer, shorter or equal to the other unmoved height
    in which case we will take the unmoved in the 1st case, shorter in the second and both in the third, in all three cases our answers dont improve 
*/