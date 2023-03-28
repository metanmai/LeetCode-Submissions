/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        function<string(string)> getHostname = [&](string url) -> string 
        {
            int pos = min(url.size(), url.find('/', 7));
            return url.substr(7, pos - 7);
        };

        string startHostname = getHostname(startUrl);
        set<string> visited;

        function<void(string)> dfs = [&](string url) -> void 
        {
            visited.insert(url);
            for (string nextUrl : htmlParser.getUrls(url)) {
                if (getHostname(nextUrl) == startHostname && !visited.count(nextUrl)) {
                    dfs(nextUrl);
                }
            }
        };

        dfs(startUrl);
        return vector<string>(visited.begin(), visited.end());
    }
};