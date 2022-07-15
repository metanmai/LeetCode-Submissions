class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        return __import__("re").search("^" + p + "$", s)!=None