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

void recursivePreOrderTraversal(TreeNode* now) {
	if (now) {
		cout << now->val << ' ';
		recursivePreOrderTraversal(now->left);
		recursivePreOrderTraversal(now->right);
	}
}

void morrisPreOrderTraversal(TreeNode* now) {

	TreeNode *cur = now, *tmp;
	function<TreeNode* (TreeNode*, TreeNode*)> rightmost_self = [&] (TreeNode* now, TreeNode* target) { 
		// right child is target or empty
		if (now->right == target || !now->right) return now;
		// find rightmost recursively
		return rightmost_self(now->right, target);
	};

	while (cur) {

		// go to leftmost node
		if (!cur->left) {
			cout << cur->val << ' ';
			cur = cur->right;
			continue;
		}

		// find the rightmost node at left child and that node is not self
		tmp = rightmost_self(cur->left, cur);
		
		// remove the temporal link at right child
		if (tmp->right == cur) {
			tmp->right = NULL;
			cur = cur->right;
		}
		else {
			cout << cur->val << ' ';
			tmp->right = cur;
			cur = cur->left;
		}
	}
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
		recursivePreOrderTraversal(root);
		cout << endl;
#endif
#ifdef MORRIS_METHOD
		morrisPreOrderTraversal(root);
		cout << endl;
#endif
	}

	return 0;
}


