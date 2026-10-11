class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;

        for (char ch : word) {
            if (isupper(ch))
                cap++;
        }

        int n = word.size();

        return cap == n ||           // all uppercase
               cap == 0 ||           // all lowercase
               (cap == 1 && isupper(word[0])); // only first letter uppercase
    }
};