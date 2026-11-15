
#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node
{
    char ch;
    int freq;

    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Compare function for minimum frequency
struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

// Print Huffman Codes
void printCodes(Node* root, string code)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Huffman Encoding Function
void huffmanEncoding(char ch[], int freq[], int n)
{
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters into priority queue
    for (int i = 0; i < n; i++)
    {
        pq.push(new Node(ch[i], freq[i]));
    }

    // Build Huffman Tree
    while (pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('$',
                                 left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Print Huffman Codes
    cout << "\nHuffman Codes:\n";
    printCodes(pq.top(), "");
}

int main()
{
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input";
        return 0;
    }

    char ch[n];
    int freq[n];

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> ch[i];
    }

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> freq[i];

        if (freq[i] <= 0)
        {
            cout << "Frequency must be positive.";
            return 0;
        }
    }

    huffmanEncoding(ch, freq, n);

    return 0;
}
