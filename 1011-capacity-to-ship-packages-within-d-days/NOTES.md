class Solution {
private int checkDays(int[] weights, int currWeight)
{
int currSum = 0, currDays = 1;
for(int i = 0; i < weights.length; i++)
{
if(currSum + weights[i] > currWeight)
{
currSum = weights[i];
currDays++;
}
else
currSum += weights[i];
}
return currDays;
}
public int shipWithinDays(int[] weights, int days) {
int low = Arrays.stream(weights).max().getAsInt();
int high = Arrays.stream(weights).sum();
System.out.println(low + " " + high);
while(low < high)
{
int mid = (high + low) / 2;
if(checkDays(weights, mid) == days && checkDays(weights, mid - 1) > days)
return mid;
else if(checkDays(weights, mid) > days)
low = mid + 1;
else
high = mid - 1;
}
return low;
}
}