class Solution {
public:
    int romanToInt(string s) {
        // Map each Roman numeral to its integer value
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0;
        
        // Traverse the string
        for (int i = 0; i < s.size(); i++) {
            // If current value is less than the next value, subtract it
            if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]]) {
                result -= roman[s[i]];
            } else {
                // Otherwise, add it
                result += roman[s[i]];
            }
        }
        
        return result;
    }
};
