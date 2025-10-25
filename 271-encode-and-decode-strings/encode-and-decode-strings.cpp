class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto &s : strs) {
            string len_str = to_string(s.size());
            // 补齐 4 位，不够前面补 0
            while (len_str.size() < 4) len_str = '0' + len_str;
            res += len_str + s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            // 取 4 位长度字段
            int length = stoi(s.substr(i, 4));
            i += 4;
            // 取对应长度的字符串
            ans.emplace_back(s.begin() + i, s.begin() + i + length);
            i += length;
        }
        return ans;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));