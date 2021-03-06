#include <bits/stdc++.h>
#define ll long long
#define str(x) string(to_string(x))
#define ord(x) int(x - '0')
#define chr(x) char(x + '0')
#define len(x) x.size()

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

template <class DataType>
void printVector(vector<DataType> v) {
    if (v.empty()) {
        cout << "<empty vector>" << endl;
    } else {
        for (DataType i : v) {
            cout << i << " ";
        }
    }
    cout << endl;
}

template <class DataType>
void printGrid(vector<vector<DataType> > g) {
    for (vector<DataType> &v : g) {
        printVector(v);
    }
}

template <class DataType1, class DataType2>
void printPair(pair<DataType1, DataType2> p) {
    cout << p.first << " " << p.second << endl;
}

void printBool(bool b) {
    cout << (b ? "true" : "false") << endl;
}

void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void printBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "" << endl;
    }
    queue<TreeNode*> q;
    string result = "";
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        if (node == nullptr) {
            result = result + "null,";
        } else {
            result = result + string(to_string(node->val)) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        q.pop();
    }
    cout << "[" + result.substr(0, result.size() - 1) + "]" << endl;
}

int readNumber() {
    int result;
    cin >> result;
    return result;
}

vector<int> readVector(int size) {
    vector<int> result;
    for (int i = 1; i <= size; ++i) {
        int temp;
        cin >> temp;
        result.push_back(temp);
    }
    return result;
}

vector<string> readStringVector(int size) {
    vector<string> result;
    for (int i = 1; i <= size; ++i) {
        string temps;
        cin >> temps;
        result.push_back(temps);
    }
    return result;
}

vector<vector<int> > readGrid(int m, int n) {
    vector<vector<int> > result;
    for (int i = 1; i <= m; ++i) {
        result.push_back(readVector(n));
    }
    return result;
}

ListNode* readLinkedList(int n) {
    ListNode* head = new ListNode(-1);
    cin >> head->val;
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(-1);
        current = current->next;
        cin >> current->val;
    }
    return head;
}

vector<string> split(string s, string d) {
    vector<string> values;
    if (!s.empty()) {
        int index = 0;
        while (s.find(d, index) != string::npos) {
            values.push_back(s.substr(index, s.find(d, index) - index));
            index = s.find(d, index) + len(d);
        }
        values.push_back(s.substr(index, s.size() - index));
    }
    return values;
}

TreeNode* readBinaryTree() {
    string line = "";
    cin >> line;
    line = line.substr(1, line.size() - 2);
    if (line == "") {
        return nullptr;
    }
    queue<TreeNode*> q;
    vector<string> values = split(line, ",");
    TreeNode* root = new TreeNode(stoi(values[0]));
    q.push(root);
    for (int i = 1; i < values.size(); i++) {
        TreeNode* parent = q.front();
        if (values[i] != "null" && parent != nullptr) {
            parent->left = new TreeNode(stoi(values[i]));
            q.push(parent->left);
        }
        if (i + 1 < values.size()) {
            if (values[++i] != "null" && parent != nullptr) {
                parent->right = new TreeNode(stoi(values[i]));
                q.push(parent->right);
            }
        }
        q.pop();
    }
    return root;
}

vector<vector<int> > readGraph() {
    string s = "";
    vector<vector<int> > graph;
    while (s.empty()) getline(cin, s);
    for (string ss : split(s.substr(2, len(s) - 4), "],[")) {
        vector<int> nv;
        for (string ns : split(ss.substr(0, ss.size()), ",")) {
            nv.push_back(stoi(ns));
        }
        graph.push_back(nv);
    }
    return graph;
}

vector<vector<char>> readCharGraph() {
    string s = "";
    vector<vector<char>> graph;
    while (s.empty()) getline(cin, s);
    for (string ss : split(s.substr(2, len(s) - 4), "],[")) {
        vector<char> cv;
        for (string ns : split(ss.substr(1, ss.size() - 2), "\",\"")) {
            cv.push_back(ns[0]);
        }
        graph.push_back(cv);
    }
    return graph;
}

vector<int> readVector() {
    string line = "";
    vector<int> values;
    while (line.empty()) getline(cin, line);
    line = line.substr(1, line.size() - 2);
    for (string s : split(line, ",")) {
        values.push_back(stoi(s));
    }
    return values;
}

vector<string> readStringVector() {
    string line = "";
    vector<string> values;
    while (line.empty()) getline(cin, line);
    line = line.substr(1, line.size() - 2);
    for (string s : split(line, ",")) {
        values.push_back(s.substr(1, s.size() - 2));
    }
    return values;
}

ListNode* readLinkedList() {
    string line = "";
    while (line.empty()) getline(cin, line);
    line = line.substr(1, line.size() - 2);
    ListNode* head = new ListNode(-1);
    ListNode* current = head;
    for (string s : split(line, ",")) {
        current->next = new ListNode(stoi(s));
        current = current->next;
    }
    return head->next;
}
