class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";

        for(char ch : num)
        {
            while(st.length() and k and ch < st.back())
                st.pop_back(), k--;

            st.push_back(ch);
        }
        
        while(st.length() and k--) 
            st.pop_back();

        reverse(begin(st), end(st));

        while(st.length() and st.back() == '0') 
            st.pop_back();

        reverse(begin(st), end(st));
        
        return st == "" ? "0" : st;
    }
};