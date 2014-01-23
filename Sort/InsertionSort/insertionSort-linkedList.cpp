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
void insertionSort(node*&, node*&);
// insert into position
void insertPos(node*, node*, node*, node*);

int main() {

	int n, x;
	while (~scanf("%d", &n)) {

		node *head = NULL, *tail = NULL;

		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			node *ret = push_back(head, tail, x);
			tail = ret;
		}

		insertionSort(head, tail);

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

void insertionSort(node* &head, node* &tail) {

	for (node *cur = head, *prev = NULL; cur != NULL; prev = cur, cur = cur->next) {
		for (node *pos = head, *last = NULL; pos != cur; last = pos, pos = pos->next) {
			if (cur->value <= pos->value) {
				insertPos(cur, prev, pos, last);
				if (pos == head) head = cur;
				if (cur == tail) tail = prev;
				cur = prev;
				break;
			}
		}
	}
}

void insertPos(node* cur, node* pcur, node* pos, node* ppos) {
	if (ppos != NULL) ppos->next = cur;
	pcur->next = cur->next;
	cur->next = pos;
}

