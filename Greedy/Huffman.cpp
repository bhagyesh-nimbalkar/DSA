#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char symbol = '$';
    int count = 0;
    Node *left, *right;
    Node(char s, int t)
    {
        symbol = s;
        count = t;
        left = right = nullptr;
    }
};

struct myCmp
{
    bool operator()(Node *a, Node *b)
    {
        return a->count > b->count;
    }
};

Node *huffman(vector<pair<char, int>> &v)
{
    sort(v.begin(), v.end(), [](pair<char, int> &a, pair<char, int> &b)
         {
             return a.second < b.second;
         });
    priority_queue<Node *, vector<Node *>, myCmp> pq;
    pq.push(new Node(v[0].first, v[0].second));
    pq.push(new Node(v[1].first, v[1].second));
    int i=2;
    while(pq.size()>1 && i<=v.size())
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *parent = new Node('$', left->count + right->count);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
     if(i<v.size())
     {
        pq.push(new Node(v[i].first, v[i].second));
     }
        i++;
    }
    return pq.top();
}

void Traversal(Node *root, string code)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
    {
        cout << "Character: " << root->symbol << ", Huffman Code: " << code << endl;
    }
    Traversal(root->left, code + "0");
    Traversal(root->right, code + "1");
}

int main()
{
    vector<pair<char, int>> v{{'a', 10}, {'d', 50}, {'b', 20}, {'e', 40}, {'f', 80}};
    Node *res = huffman(v);
    Traversal(res, "");
    return 0;
}
