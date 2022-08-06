class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        trials = minutesToTest // minutesToDie
        return ceil(log(buckets) / log(trials + 1))