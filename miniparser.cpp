#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
   int _i;
   bool isInt;
   vector<Node*> nested;
   Node() { isInt = false; }
   Node(int i){
      _i = i;
      isInt = true;
   }
   bool isInteger() { return isInt; }
};

class Solution {
public:
   vector<Node*> miniParser(string s) {
      if (s.empty()) return vector<Node*>();
      if (s[0] != '[') {
         vector<Node*> result;
         Node* p = new Node(stoi(s));
         result.push_back(p);
         return result;
      }
      int start = 0;
      return miniParserHelper(s, start);
   }
   void printVec(vector<Node*> v) {
      for (int i = 0; i < v.size(); i++) {
         if (v[i]->isInteger()) {
            cout << v[i]->_i << " ";
         }
         else {
            cout << "( " ;
            printVec(v[i]->nested);
            cout << " ) " ;
         }
         if (i < v.size() - 1) cout << "-> ";
      }
   }
private:
   vector<Node*> miniParserHelper(string s, int& start) {
      vector<Node*> result;
      start++; // pass [
      while(s[start] != ']') {
         if (s[start] != '[') {
            string num = "";
            while(s[start] != ',' && s[start] != ']') {
               num += s[start++];
            }
            result.push_back(new Node(stoi(num)));
         }
         else {
            result.push_back(new Node());
            result.back()->nested = miniParserHelper(s, start);
         }
         if (s[start] == ',') start++; // pass ,
      }
      start++; // pass ]
      return result;
  }
};

int main() {
   string input1 = "[123,456,[788,799,833],[[]],10,[]]";
   string input2 = "456";
   Solution s;
   s.printVec(s.miniParser(input1));
   cout << endl;
   s.printVec(s.miniParser(input2));
   cout << endl;
   return 0;
}
