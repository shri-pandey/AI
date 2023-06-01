#include <iostream>
#include <stack>

using namespace std;

// Binary Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Depth Limited Search using Stack
bool depthLimitedSearch(Node *root, int key, int depth)
{
    stack<pair<Node *, int>> s;
    s.push({root, 0});

    while (!s.empty())
    {
        Node *current = s.top().first;
        int currentDepth = s.top().second;
        s.pop();

        if (current == NULL)
            continue;

        if (current->data == key)
            return true;

        if (currentDepth == depth)
            continue;

        s.push({current->right, currentDepth + 1});
        s.push({current->left, currentDepth + 1});
    }

    return false;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int key = 6;
    int depthLimit = 2;

    if (depthLimitedSearch(root, key, depthLimit))
        cout << "Node " << key << " is present within the depth limit of " << depthLimit << endl;
    else
        cout << "Node " << key << " is not present within the depth limit of " << depthLimit << endl;

    return 0;
}
