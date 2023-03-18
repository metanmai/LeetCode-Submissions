class Codec {
public:
    string findLength(string s, int &pos)
    {
        string tempLen = "";
        
        while(s[pos] != ',')
        {
            tempLen.push_back(s[pos]);
            pos++;
        }
        
        pos++;
        return tempLen;
    }
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encodedString = "";
        
        encodedString += to_string(strs.size()) + ",";
        for(auto str : strs)
            encodedString += to_string(str.size()) + ",";
        
        for(auto str : strs)
            encodedString += str + ",";
        
        return encodedString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decodedStrings;
        vector<int> stringLens;
        int pos = 0;
        string temp = findLength(s, pos);
        int len = stoi(temp);
        
        for(int i = 0; i < len; i++)
        {
            string tempStr = findLength(s, pos);
            stringLens.push_back(stoi(tempStr));
        }
        
        for(int currLen : stringLens)
        {
            decodedStrings.push_back(s.substr(pos, currLen));
            pos += currLen + 1;
        }
        
        return decodedStrings;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));