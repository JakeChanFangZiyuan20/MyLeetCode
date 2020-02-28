class Solution {
private:
    string ipAddress;
    string newIPAddr;
    vector<string>result;
    vector<string>ip;
public:
    vector<string> restoreIpAddresses(string s) {
        int ipLength = s.size();
        if (ipLength < 4 || ipLength > 12) return vector<string>();

        ipAddress = s;
        ip = vector<string>(4, "");

        DFS(0, 0);

        return result;
    }

    void DFS(int part, int startPos) {
        if (startPos >= ipAddress.size()) return ; 
        if (ipAddress.size() - startPos > (4 - part) * 3) return ;
        if (part == 3) {
            string part4 = string(ipAddress.begin() + startPos, ipAddress.end());
            if (part4[0] == '0' && part4.size() > 1) return ;
            int part4Int = stoi(part4);
            if (0 <= part4Int && part4Int <= 255) {
                newIPAddr = "";
                for (int i = 0; i < 3; i++) {
                    newIPAddr += ip[i];
                    newIPAddr += ".";
                }
                newIPAddr += part4;
                result.push_back(newIPAddr);
            }
            return ;
        }

        for (int i = startPos; i < startPos + 3; i++) {
            ip[part].push_back(ipAddress[i]);
            int curPart = stoi(ip[part]);
            if (0 <= curPart && curPart <= 255) {
                DFS(part + 1, i + 1);
                ip[part + 1] = "";
            }
            if (i == startPos && ipAddress[i] == '0') return ;
        }
    }
};
