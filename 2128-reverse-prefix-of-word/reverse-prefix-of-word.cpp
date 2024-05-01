class Solution {
public:
    string reversePrefix(string word, char ch) {
        int ind = 0, n = word.size(), ind1 = 0;
        while(ind < n && word[ind] != ch) ind++;
        if(ind == n) return word;
        while(ind1 < ind) {
            char temp = word[ind];
            word[ind] = word[ind1];
            word[ind1] = temp;
            ind1++;
            ind--;
        }
        return word;
    }
};