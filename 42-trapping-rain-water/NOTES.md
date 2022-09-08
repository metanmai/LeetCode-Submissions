class Solution {
public:
int trap(vector<int>& height) {
vector<int> dp(height.size() , 0);
int water = 0;
int maxval = 0;
for (int i = 0 ; i < dp.size() ; i++)
{
if(height[i]<maxval)
{
water = water - (height[i]-maxval);
}
else
{
maxval = height[i];
}
cout<<height[i]<<" "<<maxval<<" "<<water<<endl;
}
return water;
}
};