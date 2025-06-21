class Solution {
public:
    int converted(char r){
            switch(r){
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default: return 0;
            }
        }
    // the function, converted, uses switch to check each individual character of the string, and assigns its converted roman numeral value 
    // default case unapplicable in our scenario, just needed for the function to work
    int romanToInt(string s) {
        int roman = 0;
        int str = s.size();
        // for later use, declares roman and finds size of string
        for(int i = 0; i<str; i++){
            int cur = converted(s[i]);
            int next = converted(s[i+1]);
            // single for loop, goes left to right
            // cur and next, are the current index of string and the one directly after
            if (cur>=next){
                roman = roman + cur;
            }
            else{
                roman = roman - cur;
            }
            // if else statement checks if the current value is greater than or equal (i.e., II or VI), than its a sum, if not its a difference. the for loop goes thru every single index, and updates the value of roman accordingly
        }
        return roman;
        // returns final value of roman
    }
};