// class Solution {
// public:
//     string reverseVowels(string s) {
//         // Convert the input string to a character array.
//         string word = s;
//         int start = 0;
//         int end = s.length() - 1;
//         string vowels = "aeiouAEIOU";
        
//         // Loop until the start pointer is no longer less than the end pointer.
//         while (start < end) {
//             // Move the start pointer towards the end until it points to a vowel.
//             while (start < end && vowels.find(word[start]) == string::npos) {
//                 start++;
//             }
            
//             // Move the end pointer towards the start until it points to a vowel.
//             while (start < end && vowels.find(word[end]) == string::npos) {
//                 end--;
//             }
            
//             // Swap the vowels found at the start and end positions.
//             swap(word[start], word[end]);
            
//             // Move the pointers towards each other for the next iteration.
//             start++;
//             end--;
//         }
        
//         // Return the modified string.
//         return word;
//     }
// };

class Solution {
public:
    bool isVowels(char c){
        //If agar c Upper case A,E,I,O,U then convert it in to lower 
        //If lower then it is  lower
            c = tolower(c);
            return c == 'a' || c=='e'|| c == 'i' || c == 'o' || c == 'u';
        }
    string reverseVowels(string s) {
    
        int start = 0;
        int end = s.length() - 1;
        while(start <= end){
            if(isVowels(s[start]) && isVowels(s[end])){
                swap(s[start],s[end]);
                start++;
                end--;
            }
            else if(!isVowels(s[start])){
                start++;
            }
            else{
                end--;
            }
        }
        return s;
    }
};