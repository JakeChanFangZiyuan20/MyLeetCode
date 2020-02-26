class Solution {
public:
    string intToRoman(int num) {
        string result, symbol;
        for(int i = 0; i < 4; i++){
            if(i == 0) symbol = "IVX";
            else if(i == 1) symbol = "XLC";
            else if(i == 2) symbol = "CDM";

            int cur = num % 10;
            string curPos;

            if(i == 3){
                result = string(cur, 'M') + result;
                break;
            }

            if(cur == 0){
                num /= 10;
                if(num == 0) break;
                continue;
            } else if(cur == 4){
                curPos = string({symbol[0], symbol[1]});
            } else if(cur == 9){
                curPos = string({symbol[0], symbol[2]});
            } else if(cur == 5){
                curPos = string(1, symbol[1]);
            } else if(cur < 4){
                curPos = string(cur, symbol[0]);
            } else if(cur > 5 && cur < 9){
                curPos = string(1, symbol[1]) + string(cur - 5, symbol[0]);
            }

            result = curPos + result;
            num /= 10;
        }
        return result;
    }
};