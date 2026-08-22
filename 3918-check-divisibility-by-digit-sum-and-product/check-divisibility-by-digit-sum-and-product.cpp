class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int digitSum = 0, digitProduct = 1;

        while (temp > 0) {
        int d = temp % 10;   // extract digit
        digitSum += d;       // add to sum
        digitProduct *= d;   // multiply to product
        temp /= 10;          // move to next digit
        }

        int total = digitSum + digitProduct;
        return (n % total == 0);
        
        
    }
};