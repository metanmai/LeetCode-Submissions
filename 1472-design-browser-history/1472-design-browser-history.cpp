class BrowserHistory {
private:
    vector<string> browser;
    int pos;
    
public:
    BrowserHistory(string homepage) {
        browser = {homepage};
        pos = 0;
    }
    
    void visit(string url) {
        browser.erase(browser.begin() + pos + 1, browser.end());
        browser.push_back(url);
        pos++;
    }
    
    string back(int steps) {
        while(pos >= 0 and steps--)
            pos--;
        
        return browser[pos = pos < 0 ? 0 : pos];
    }
    
    string forward(int steps) {
        while(pos < browser.size() and steps--)
            pos++;
            
        return browser[pos = pos >= browser.size() ? browser.size() - 1 : pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */