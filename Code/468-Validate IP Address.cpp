class Solution {
public:
    string validIPAddress(string IP) {
        string Neither("Neither");

        int strLen = IP.size();
        if (strLen == 0) return Neither;
        else if (strLen < 7 || strLen > 39) {
            return Neither;
        }

        bool isIPv4 = false, isIPv6 = false;
        vector<string>ipParts;
        string ipPart;
        for (int i = 0; i < strLen; i++) {
            if (i == 0 && (IP[i] == '.' || IP[i] == ':') ||
                i == strLen - 1 && (IP[i] == '.' || IP[i] == ':')) {
                return Neither;
            }

            if (IP[i] == '.') {
                if (isIPv4 == false)isIPv4 = true;
            } else if (IP[i] == ':') {
                if (i > 0 && IP[i - 1] == ':') return Neither;
                if (isIPv6 == false)isIPv6 = true;
            } else {
                ipPart = "";
                while (i < strLen && IP[i] != '.' && IP[i] != ':') {
                    ipPart.push_back(IP[i]);
                    i++;
                }
                i--;

                ipParts.push_back(ipPart);
            }
        }

        if (isIPv4 && ipParts.size() != 4 ||
            isIPv6 && ipParts.size() != 8) {
            return Neither;
        }

        for (int i = 0; i < ipParts.size(); i++) {
            if (isIPv4) {
                if (ipParts[i][0] == '0' && ipParts[i].size() > 1) return Neither;

                if (ipParts[i].size() > 3) return Neither;

                for (int j = 0; j < ipParts[i].size(); j++) {
                    if (ipParts[i][j] < '0' || ipParts[i][j] > '9') {
                        return Neither;
                    }
                }

                if (stoi(ipPart) > 255) return Neither;

            }
            else {
                if (ipParts[i].size() > 4) return Neither;

                for (int j = 0; j < ipParts[i].size(); j++) {
                    if ((ipParts[i][j] < '0' || ipParts[i][j] > '9') &&
                            (ipParts[i][j] < 'A' || ipParts[i][j] > 'F') &&
                                (ipParts[i][j] < 'a' || ipParts[i][j] > 'f')) {
                        return Neither;
                    }
                }
            }
        }

        if (isIPv4) return "IPv4";
        return "IPv6";
    }
};
