class Solution {
public:
    string reformatDate(string date) {
        int n = date.size();
        string d = "xx", m, y;
        
        map<string, string> months = 
        {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"},{"Apr", "04"}, 
         {"May", "05"}, {"Jun", "06"},{"Jul", "07"}, {"Aug", "08"}, 
         {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        
        if(n == 13)
            d[0] = date[0], d[1] = date[1];
        
        else
            d[0] = '0', d[1] = date[0];
        
        m = months[date.substr(n - 8, 3)];
        y = date.substr(n - 4, 4);
        
        return y + '-' + m + '-' + d;
    }
};