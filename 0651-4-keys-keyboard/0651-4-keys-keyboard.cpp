class Solution {
public:
    int maxA(int N) {
        if (N <= 6) 
            return N;

        if (N == 10) 
            return 20;

        int n = N / 5 + 1, n3 = n * 5 - 1 - N;
        return pow(3, n3) * pow(4, n - n3);
    }
};