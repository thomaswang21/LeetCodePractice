class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for(auto &s:strs){
            res+=to_string(s.size())+"#"+s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#')j++;
            int length=stoi(s.substr(i, j-i));
            i=j+1;
            res.push_back(s.substr(i, length));
            i+=length;

            
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));