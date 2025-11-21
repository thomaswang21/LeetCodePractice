#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> stringStack; // 存上一级字符串
        stack<int> countStack;     // 存对应的重复次数
        string cur = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0'); // 解析数字
            } else if (c == '[') {
                stringStack.push(cur);  // 保存当前字符串
                countStack.push(k);    // 保存重复次数
                cur = "";               // 开始新的子串
                k = 0;
            } else if (c == ']') {
                string temp = cur;      // 当前要重复的子串
                cur = stringStack.top(); stringStack.pop();
                int count = countStack.top(); countStack.pop();
                for (int i = 0; i < count; i++) {
                    cur += temp;
                }
            } else {
                cur += c;               // 普通字符加入当前字符串
            }
        }

        return cur;
    }
};
