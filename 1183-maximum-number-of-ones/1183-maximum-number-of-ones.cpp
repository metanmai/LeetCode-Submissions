class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
		vector<int> sides(sideLength * sideLength);
        
		for(int i = 0; i < width; i++)
			for(int j = 0; j < height; j++)
				sides[(i % sideLength) * sideLength + (j % sideLength)]++;
        
		sort(sides.begin(), sides.end(), greater<> ());
		return accumulate(sides.begin(), sides.begin() + maxOnes, 0);
    }
};