class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        // If the needle is longer than the haystack, it's impossible to find.
        if (m > n) return -1;

        // Iterate through the haystack
        // We stop at n - m to ensure we have enough characters left for the needle
        for (int i = 0; i <= n - m; i++) {
            // Check if the substring starting at i matches the needle
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }

        return -1;
    }
};