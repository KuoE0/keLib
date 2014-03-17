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

	TreeNode *dummy = new TreeNode(0), *cur, *tmp;
	function<TreeNode* (TreeNode*, TreeNode*)> rightmost_self = [&] (TreeNode* now, TreeNode* target) { 
		// right child is target or empty
		if (now->right == target || !now->right) return now;
		// find rightmost recursively
		return rightmost_self(now->right, target);
	};
	function<void (TreeNode*)> output_path = [&] (TreeNode* now) {
		if (now->right) output_path(now->right);
		// output in reversed order
		cout << now->val << ' ';
	};

	// dummy node, make the root has no right child
	dummy->left = now;
	cur = dummy;

	while (cur) {

		// reach the leftmost node
		if (!cur->left) {
			cur = cur->right;
			continue;
		}

		// find the rightmost node at left child and that node is not self
		tmp = rightmost_self(cur->left, cur);

		if (tmp->right == cur) {
			// unlink the thread
			tmp->right = NULL;
			// output the value in reverse order
			output_path(cur->left);
			cur = cur->right;
		}
		else {
			// link to self
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


