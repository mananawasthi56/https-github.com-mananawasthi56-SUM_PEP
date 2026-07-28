class Solution {
public:
    string smallestPalindrome(string s) {
               int freq[26] = {0};

        // frequency count
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string left = "";
        char middle = '\0';

        // a to z -> lexicographically smallest
        for (int i = 0; i < 26; i++) {

            // half characters left side me
            left += string(freq[i] / 2, 'a' + i);

            // odd frequency character middle me
            if (freq[i] % 2 == 1) {
                middle = 'a' + i;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (middle != '\0') {
            return left + middle + right;
        }

        return left + right;
    }
        
    
};