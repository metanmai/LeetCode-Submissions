class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        compare = strs[0]
        
        for i in range(1, len(strs)):
            k = 0
            temp = ""
            while (k < min(len(compare), len(strs[i])) and 
                   compare[k] == strs[i][k]):
                temp += compare[k]
                k += 1
            
            compare = temp
        
        return compare
            