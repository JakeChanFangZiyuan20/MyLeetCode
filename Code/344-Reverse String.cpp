class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        if(len == 0 || len == 1) return ;

        int head = 0, tail = len - 1;
        while(head < tail){
            char temp_c = s[head];
            s[head] = s[tail];
            s[tail] = temp_c;

            head++;
            tail--;
        }

    }
};