class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            int len = 0;

            // Read digits until delimiter '#'
            while (i < s.size() && s[i] != '#') {
                len = len * 10 + (s[i] - '0');
                i++;
            }
            // Skip delimiter '#'
            i++;

            // Read exactly 'len' characters
            result.push_back(s.substr(i, len));
            i += len;
        }

        return result;
    }
};