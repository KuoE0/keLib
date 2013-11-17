/*
 * bubbleSort-linkedList.cpp
 * Copyright (C) 2013 KuoE0 <kuoe0.tw@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;

// structure for linked list
struct node {
	int value;
	node *next;
	node(int val, node *link=NULL)
		: value(val), next(link) {}
};

// add element at back
node* push_back(node*&, node*&, int);
// free all memory
void free_list(node*);
// bubble sort for linked list
void bubbleSort(node*&, node*&, int);
// swap neighbor node of list
node* swap_neighbor(node*, node*, node*);

int main() {

	int n, x;
	while (~scanf("%d", &n)) {

		node *head = NULL, *tail = NULL;

		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			node *ret = push_back(head, tail, x);
			tail = ret;
		}

		bubbleSort(head, tail, n);

		for (node *cur = head; cur != NULL; cur = cur->next) {
			printf("%d ", cur->value);
		}
		puts("");
		free_list(head);
	}

	return 0;
}

node* push_back(node* &head, node* &tail, int val) {
	node *ret = new node(val);
	if (head == NULL)
		head = ret;
	else
		tail->next = ret;
	return ret;
}

void free_list(node* link) {
	if (link->next != NULL)
		free_list(link->next);
	delete link;
}

void bubbleSort(node* &head, node* &tail, int n) {

	for (int i = 0; i < n - 1; ++i) {
		
		for (node *cur = head, *prev = NULL; cur != NULL; prev = cur, cur = cur->next) {
			node *next = cur->next;
			if (next != NULL && cur->value > next->value) {
				if (cur == head) head = next;
				if (next == tail) tail = cur;
				cur = swap_neighbor(cur, prev, next);
			}
		}
	}
}

node* swap_neighbor(node* cur, node* prev, node* next) {
	if (prev != NULL)
		prev->next = next;
	cur->next = next->next;
	next->next = cur;
	return next;
}

