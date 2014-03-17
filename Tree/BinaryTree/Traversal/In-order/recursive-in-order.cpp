/*
 * recursive-in-order.cpp
 * Copyright (C) 2014 KuoE0 <kuoe0.tw@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertNode(TreeNode* now, const int val) {
	if (!now) now = new TreeNode(val);
	else if (val < now->val) now->left = insertNode(now->left, val);
	else now->right = insertNode(now->right, val);
	return now;
}

void inOrderTraversal(TreeNode* now) {
	cout << "(";
	// travel left child first
	if (now && now->left) inOrderTraversal(now->left);
	if (now) cout << now->val;
	// travel left child last
	if (now && now->right) inOrderTraversal(now->right);
	cout << ")";
}

int main() {
	int n, x;
	while (cin >> n) {
		TreeNode *root = NULL;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			root = insertNode(root, x);
		}
		inOrderTraversal(root);
		cout << endl;
	}

	return 0;
}


