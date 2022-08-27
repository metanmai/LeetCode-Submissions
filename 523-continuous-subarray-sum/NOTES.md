Create a dictionary where you keep the remainder as the key and index as the value.
​
In example 1, the first remainder will be 5 (23 % 6). Check if you have already found a remainder 5 before. If yes, that means that some subarray in between added up to k, which led to the remainder being 5 again. If not, then add it to the dictionary and go to the next element.
Since 5 is not already present in the dictionary, we add it to the dictionary and go to the next element in nums. We then check the running_sum, which is 25. 25 % 6 = 1, which is also not present in the dictionary. Next, we have 29 % 6 = 5. Now the remainder 5 is already present in the dictionary, which means that some multiple of 6 has been added to the running_sum of the list which gives you the same remainder.
​
Now, check if the subarray length is >= 2. We do this by checking if the difference of the current index value in the array and the index value stored in the dictionary for the same remainder is >= 2.
​
There is however an edge case, where in if the first element is a multiple of 6, it returns True, which is not the case as the subarray is only of size 1. This is handled by initializing the dictionary with a 0 : -1. We are adding the 0 because there are cases where the running sum itself becomes a multiple if k, i.e, the very subarrays which start at index 0 but satify the condition will not pass the test as 0 won't already be present in the dictionary so we add that beforehand. The -1 is for the case where the very first element in the list is a multiple of k. So if that's the case, then we check the elif condition, where the length is given as 0 - (-1) = 1, so we don't immediately return True.
​
Watch https://youtu.be/OKcrLfR-8mE for further clarity.