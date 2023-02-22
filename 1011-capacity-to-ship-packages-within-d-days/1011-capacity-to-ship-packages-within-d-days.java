class Solution {
    private boolean checkDays(int[] weights, int currWeight, int days)
    {
        int currSum = 0, currDays = 0;
        
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
        if(currSum > 0)  currDays++;
        
        return days < currDays;
    }
    
    public int shipWithinDays(int[] weights, int days) {
        int low = Arrays.stream(weights).max().getAsInt();
        int high = Arrays.stream(weights).sum();
        
        System.out.println(low + " " + high);
        while(low <= high)
        {
            int mid = (high + low) / 2;
            
            if(checkDays(weights, mid, days))
                low = mid + 1;
            
            else
                high = mid - 1;
        }
        
        return low;
    }
}