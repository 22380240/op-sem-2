#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Node {
  public:
    int count;
    char symbol;
    Node* left;
    Node* right;
    Node() {}
    Node(char _symbol, int _count) { 
      symbol = _symbol;
      count = _count;
    }

    Node(Node *l, Node *r) {
      symbol = 0;
      left = l;
      right = r;
      count = l->count + r->count;
    }

    void BuildTable(Node *root, vector<bool> &code, map<char, vector<bool>> &table) {
      if (root->left) {
        code.push_back(0);
        BuildTable(root->left, code, table);
      }

      if (root->right) {
        code.push_back(1);
        BuildTable(root->right, code, table);
      }

      if (root->symbol) {
        table[root->symbol] = code;
      }

      if (code.size()) {
        code.pop_back();
      }
    }

    bool SortNode(const Node *a, const Node *b) {
      return a->count < b->count;
    }

    string Decode(string &str, map<vector<bool>, char> &table) {
      string out = "";
      vector<bool> code;

      for (int i = 0; i < str.length(); i++) {
        code.push_back(str[i] == '0' ? false : true);
        if (table[code]) {
          out += table[code];
          code.clear();
        }
      }

      return out;
    }

    static void Print(Node *root, int depth=0) {
      if (!root) return; 
      if (root->symbol) {
        for (int i = 0; i < depth; i++) {
          cout << ".";
        }

        cout << root->symbol << endl;
      } else {
        depth++;
      }

      Print(root->left, depth);
      Print(root->right, depth);
    }
};

int main() {
  int a = 0, c;
  cout << "Enter the text: " << endl;

  string raw;
  getline(cin, raw);
  map<char, int> symbols;
 
  for (int i = 0; i < raw.length(); i++) {
    symbols[raw[i]]++;
  }
  
  list<Node*> trees;
  map<char, int>::iterator itr;

  for (itr = symbols.begin(); itr != symbols.end(); itr++) {
    Node *p = new Node(itr->first, itr->second);
    trees.push_back(p);
  }

  if (trees.size() == 0) {
    cout << "string is empty" << endl;
    return 0;
  }
}
