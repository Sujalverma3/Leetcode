// PrintulVostru
class Solution {
public:
    string decodeString(string s) {
        return decodeString(s, 0, s.size());
    }

private:
    string decodeString(const string& s, int start, int end) {
        string decoded = "";
        int idx = start;
        while (idx < end) {
            // write characters until digits found
            while (idx < end && !isdigit(s[idx]))
                decoded = decoded + s[idx++];
            
            // we found digits
            if (idx < end) {
                int repeated = 0;
                // extract digits in 'repeated'
                while (isdigit(s[idx])) {
                    repeated = repeated * 10 + (s[idx] - '0');           
                    idx++;
                }

                // we reached here
                // s[idx] == '['
                int depthLevel = 1;
                int startInside = idx + 1;
                int endInside = startInside;
                while (depthLevel > 0) {
                    if (s[endInside] == '[') depthLevel++;
                    else if (s[endInside] == ']') depthLevel--;
                    endInside++;
                }

                string stringInside = decodeString(s, startInside, endInside - 1);
                for (int i = 0; i < repeated; i++)
                    decoded = decoded + stringInside;
                idx = endInside;
            }
        }

        return decoded;
    }
};