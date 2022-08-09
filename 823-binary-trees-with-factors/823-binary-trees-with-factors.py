class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        MOD = pow(10, 9) + 7
        arr.sort()

        def factors(n):
            return [arr[i] for i in range(n) if arr[n] % arr[i] == 0 and arr[n] // arr[i] in arr]
        
        count = {}
        for i in arr:
            # Every element can be a tree itself. That's why we start with value 1.
            count[i] = 1
        
        total = 0
        for i in range(len(arr)):
            facts = factors(i)
            
            for j in facts:
                count[arr[i]] += count[j] * count[arr[i] // j]
                
            total += count[arr[i]]
        
        return total % MOD