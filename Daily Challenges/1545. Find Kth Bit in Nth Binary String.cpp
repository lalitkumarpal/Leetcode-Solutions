// brute force

class Solution {
public:
    void reverse_invert(string &temp){
        for(auto &i:temp){
            if(i=='0'){
                i = '1';
            }else{
                i='0';
            }
        }
        reverse(temp.begin(),temp.end());
    }
    char findKthBit(int n, int k) {
        string s = "0";
        string temp;
        while(n--){
            temp = s;
            reverse_invert(temp);
            s =s + '1' + temp;
        }
        return s[k-1];
    }
};

// optimized

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';

        int len = pow(2,n);  

        if (k < len / 2) {
            return findKthBit(n - 1, k);
        }
        else if (k == len / 2) {
            return '1';
        }
        else {
            char invert_bit = findKthBit(n - 1, len - k);
            return (invert_bit == '0') ? '1' : '0';
        }
    }
};