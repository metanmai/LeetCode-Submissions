class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        chainLen = [1] * len(pairs)
        pairs.sort()
        
        for i in range(len(pairs) - 1, -1, -1):
            for j in range(i + 1, len(pairs)):
                if pairs[i][1] < pairs[j][0]:
                    chainLen[i] = max(chainLen[i], 1 + chainLen[j])
        
        return max(chainLen)