class Solution {
private:
    // Helper function to add two large numbers represented as strings
    string add(string a, string b) {
        string res = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }

    // Helper function to verify if the rest of the string follows the additive rule
    bool isValid(string num1, string num2, string remaining) {
        while (remaining.length() > 0) {
            string next_num = add(num1, num2);
            
            // Check if the remaining string starts with our expected next_num
            if (remaining.substr(0, next_num.length()) != next_num) {
                return false;
            }
            
            // Shift the numbers forward for the next iteration
            num1 = num2;
            num2 = next_num;
            remaining = remaining.substr(next_num.length());
        }
        return true;
    }

public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        
        // i represents the length of the first number
        // It can't be more than half the string, otherwise the 3rd number wouldn't fit
        for (int i = 1; i <= n / 2; ++i) {
            // Numbers cannot have leading zeros unless the number is exactly "0"
            if (num[0] == '0' && i > 1) break;
            
            // j represents the length of the second number
            // The remaining length (n - i - j) must be at least as long as the max of the first two
            for (int j = 1; n - i - j >= max(i, j); ++j) {
                // Second number cannot have leading zeros either
                if (num[i] == '0' && j > 1) break;
                
                string num1 = num.substr(0, i);
                string num2 = num.substr(i, j);
                string remaining = num.substr(i + j);
                
                if (isValid(num1, num2, remaining)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};