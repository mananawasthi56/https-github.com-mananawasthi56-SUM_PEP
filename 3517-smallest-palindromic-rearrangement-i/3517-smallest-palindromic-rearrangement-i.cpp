class Solution {
public:
    string smallestPalindrome(string s) {
               int fre[26] = {};
               for(char ch : s){
                fre[ch - 'a']++;
               }
    string left = "";
    char midd = '\0';
    for( int i = 0 ;i<26 ; i++){
        left += string(fre[i] / 2 , 'a' + i);
        if(fre[i] % 2 == 1){
            midd = 'a' + i;
        }
    }
        string right = left;
        reverse(right.begin() , right.end());
        if(midd != '\0'){
            return left + midd + right;
        }
        return left + right;

    }


     
    
};