class Solution {
public:
    int myAtoi(string s) {
        int number = 0;
        int index = 0, length = s.length();
        bool positive = true;
        while(index < length && s[index] == ' ')   
            index++;
        if(index == length)
            return 0;
        if(s[index] == '-') {       
            positive = false;
            index++;
        }
        else if(s[index] == '+')
            index++;
        while(index < length && s[index] == '0') 
            index++;
        if(index == length)
            return 0;
        while(index < length && s[index] >= 48 && s[index] <= 57) { 
            int digit = s[index++] -'0';
            if(number > (INT_MAX - digit)/10) { 
                if(positive) return INT_MAX;
                else return INT_MIN;
            }
            else 
                number = number *10 + digit;
        }
        if(!positive)
            return -number;
        return number;
        
    }
};