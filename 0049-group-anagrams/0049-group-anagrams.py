class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        ans = []
        
        def sortString(s):
            string = ""
            l = [i for i in s]
            l.sort()
            for i in l:
                string += i
            
            return string
        
        for i in strs:
            if sortString(i) not in d:
                d[sortString(i)] = []
        
        for i in strs:
            d[sortString(i)].append(i)
        
        for i in d.keys():
            ans.append(d[i])
        
        return ans