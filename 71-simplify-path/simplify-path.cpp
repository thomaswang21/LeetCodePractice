#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;
        
        // Split the path using '/' as a delimiter
        while (getline(ss, token, '/')) {
            // Ignore empty strings (from multiple slashes) and single periods
            if (token == "" || token == ".") {
                continue;
            } 
            // Double periods mean we go up one directory (pop the stack if not empty)
            else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } 
            // Otherwise, it's a valid directory or file name, push it to the stack
            else {
                stack.push_back(token);
            }
        }
        
        // Reconstruct the simplified canonical path
        if (stack.empty()) {
            return "/";
        }
        
        string res = "";
        for (const string& dir : stack) {
            res += "/" + dir;
        }
        
        return res;
    }
};