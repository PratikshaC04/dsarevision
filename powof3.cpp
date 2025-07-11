class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n>1){
            if(n%3==0){
                n=n/3;
            }
            else{
                break;
            }
            }
            if(n==1){
                return true;
            }
            else{
                return false;
            }

        }
        
    };

        
    