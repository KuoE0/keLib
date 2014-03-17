/*
 * in-order.cpp
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

void recursivePostOrderTraversal(TreeNode* now) {
	if (now) {
		recursivePostOrderTraversal(now->left);
		recursivePostOrderTraversal(now->right);
		cout << now->val << ' ';
	}
}

void morrisPostOrderTraversal(TreeNode* now) {
}

int main() {
	int n, x;
	while (cin >> n) {
		TreeNode *root = NULL;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			root = insertNode(root, x);
		}
#ifdef RECURSIVE_METHOD
		recursivePostOrderTraversal(root);
		cout << endl;
#endif
#ifdef MORRIS_METHOD
		morrisPostOrderTraversal(root);
		cout << endl;
#endif
	}

	return 0;
}


