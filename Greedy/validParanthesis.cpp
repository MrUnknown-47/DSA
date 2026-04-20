class Solution {
public:
    bool checkValidString(string s) {
        int minF =0 , maxF = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                maxF++;
                minF++;
            } else if(s[i]==')'){
                minF--;
                maxF--;
            } else{
                minF--;
                maxF++;
            }
            minF= max(minF,0);
            if(maxF<0) return false;
        }
        return minF==0;
    }
};