class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size(), m = num2.size(), i = n-1, j = m-1, carry = 0, sum;
        string ans;
        while(i >= 0 && j >= 0) {
            sum = num1[i] - '0' + num2[j] - '0' + carry;
            if(sum > 9) {
                carry = sum / 10;
                sum %= 10;
            }
            else carry = 0;
            char add = '0' + sum;
            ans += add;
            i--;
            j--;
        }
        while(i >= 0) {
            sum = num1[i] - '0' + carry;
            if(sum > 9) {
                carry = sum / 10;
                sum %= 10;
            }
            else carry = 0;
            char add = '0' + sum;
            ans += add;
            i--;
        }
        while(j >= 0) {
            sum = num2[j] - '0' + carry;
            if(sum > 9) {
                carry = sum / 10;
                sum %= 10;
            }
            else carry = 0;
            char add = '0' + sum;
            ans += add;
            j--;
        }
        if(carry) {
            char add = '0' + carry;
            ans += add;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};