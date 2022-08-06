**Total Number of trials = (minutesToTest / minutesToDie)**
So for example 1 the total number of trials is 4.
​
Consider the case with only 1 pig and 1 trial. Then in trial number 1, the pig drinks from bucket 1. If the pig dies then that's the bucket with the poison, otherwise it's bucket 2.
Therefore, for 2 buckets, you'll need only 1 pig.
​
So basically each of the buckets is in a state of *drank* or *not drank* by the pig. Here, bucket 1 is *drank* and bucket 2 is *not drank*. So this is kinda like a logic gate.
​
For 2 pigs, how many possible buckets can be checked? The answer is 2 ^ 2, which is 4. 4 is the number of combos of 0's and 1's in a logic gate right? That's why we can check 4 seperate buckets.
​
So for n pigs, we can check a total of 2 ^ n buckets, which is the number of permutations.
In this question, they have asked the opposite, So we have to reverse engineer it.
**For x number of buckets, you'll need ceil(log x{base 2}) number of pigs.**
(Remember that thing we had done in DDCO?).
​
However, we don't need that may pigs to check for x buckets, as we have multiple trials.
​
**The number of pigs is then given by : ceil(log x{base trials + 1})**
​
Convertion of base is done by dividing.
​
Watch this video for clarity. Make sure to listen carefully because it might seem confusing at first.
​
https://youtu.be/lHU8Z-KS7U4
​
​