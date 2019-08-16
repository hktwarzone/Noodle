#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
"2019-05-31T04:09:50 | ERROR | /transfer/123 | 500 | Internal error: foo has no method bar",
    "2019-05-31T04:09:41 | INFO | /static/images/123.png | 403 | Forbidden",
    "2019-05-31T04:09:42 | INFO | /account/abc | 401 | Unauthorized",
    "2019-05-31T04:09:44 | INFO | /account/def | 401 | Unauthorized",
    "2019-05-31T04:09:44 | DEBUG | /account/xyz | 200 | Package abc deprecated",
    "2019-05-31T04:09:45 | INFO | /static/resources/567.js | 301 | Moved Permanently",
    "2019-05-31T04:09:48 | /account/abc | 200 | ",
    "2019-05-31T04:09:49 | INFO | /static/images/123.png | 403 | Forbidden",
    "2019-05-31T04:09:50 | ERROR | /transfer/123 | 500 | Internal error: foo has no method bar",
    "2019-05-31T04:09:51 | FATAL | /pages/fetch/123 | 500 | Out of memory: process shutting down",
    "2019-05-31T04:10:21 | INFO | /static/images/123.png | 403 | Forbidden",
    "2019-05-31T04:10:22 | INFO | /static/images/123.png | 403 | Forbidden",
    "2019-05-31T04:10:22 | INFO | /static/resources/567.js | 301 | Moved Permanently",
    "2019-05-31T04:10:23 | FATAL | /pages/fetch/123 | 500 | Out of memory: process shutting down"
*/    

class Log {
public:
  string timestamp;
  string level;
  string path;
  string code;
  string message;
  Log() {}
};

vector<string> readFile() 
{
    return vector<string>{"2019-05-31T04:09:50 | ERROR | /transfer/123 | 500 | Internal error: foo has no method bar",
    "2019-05-31T04:09:41 | INFO | /static/images/123.png | 403 | Forbidden",
    "2019-05-31T04:09:42 | INFO | /account/abc | 401 | Unauthorized",
    "2019-05-31T04:09:44 | INFO | /account/def | 401 | Unauthorized",
    "2019-05-31T04:09:44 | DEBUG | /account/xyz | 200 | Package abc deprecated",
    "2019-05-31T04:09:45 | INFO | /static/resources/567.js | 301 | Moved Permanently"
    };
}

int main()
{
    vector<string> logs;
    logs = readFile();
    vector<Log> result(logs.size());
    for (int i = 0; i < logs.size(); i++) {
        string s = logs[i];
        int pos = 0;
        string token;
        int j = 0;
        while((pos = s.find("|")) != std::string::npos) {
            token = s.substr(0, pos);
            switch(j) {
                case 0:
                    result[i].timestamp = token;
                    break;
                case 1:
                    result[i].level = token;
                    break;
                case 2:
                    result[i].path = token;
                    break;
                case 3:
                    result[i].code = token;
                    break;
            }
            s.erase(0, pos + 1);
            j++;
        }
        result[i].message = s;
    }
    cout << "Result : " << endl;
    for (Log l : result) {
        cout << l.timestamp << ", " << l.level << ", " << l.path << ", " << l.code << ", " << l.message << endl;
    }
    return 0;
}
