#include <iostream>
#include <vector>

using namespace std;

vector<string> decodeCSV(string s) {
    bool inQuote = false;
    string buffer;
    vector<string> results;
    for (int i = 0; i < s.size(); i++) {
        if (inQuote) {
            if (s[i] == '"') {
                if (i == s.size() - 1) {
                    results.push_back(buffer);
                    buffer = "";
                }
                else if (s[i + 1] == '"') {
                    buffer += s[i];
                    i++;
                }
                else inQuote = false;
            }
            else buffer += s[i];
        }
        else {
            if (s[i] == '"') inQuote = true;
            else if (s[i] == ',') {
                results.push_back(buffer);
                buffer = "";
            }
            else buffer += s[i];
        }
    }
    if (!buffer.empty()) results.push_back(buffer);
    return results;
}

string encodeCSV(vector<string> v) {
    string s;
    for (int i = 0; i < v.size() - 1; i++) {
        s += v[i] + '|';
    }
    s += v.back();
    return s;
}

int main() {
    // your code goes here
    string csv1 = "John,Smith,john.smith@gmail.com,Los Angeles,1";
    string csv2 = "Jane,Roberts,janer@msn.com,\"San Francisco, CA\",0";
    string csv3 = "\"Alexandra \"\"Alex\"\"\",Menendez,alex.menendez@gmail.com,Miami,1";
    string csv4 = "\"\"\"Alexandra Alex\"\"\"";
    string csv5 = "a,b,c,d";
    string csv6 = "\"abc\",a,b";
    string csv7 = "\"abc \"\"d\"\"\",a,b";
    cout << encodeCSV(decodeCSV(csv1)) << endl;
    cout << encodeCSV(decodeCSV(csv2)) << endl;
    cout << encodeCSV(decodeCSV(csv3)) << endl;
    cout << encodeCSV(decodeCSV(csv4)) << endl;
    cout << encodeCSV(decodeCSV(csv5)) << endl;
    cout << encodeCSV(decodeCSV(csv6)) << endl;
    cout << encodeCSV(decodeCSV(csv7)) << endl;
    return 0;
}
