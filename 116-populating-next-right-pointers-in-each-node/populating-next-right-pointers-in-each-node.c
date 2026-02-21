/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
	if (root==NULL || root->left==NULL)
    return root;
    root->left->next=root->right;
    if(root->next!=NULL)
    root->right->next=root->next->left;
    connect(root->left);
    connect(root->right);
    return root;
}