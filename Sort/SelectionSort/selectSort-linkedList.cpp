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
void selectionSort(node*&, node*&);
// insert into position
void swap(node*, node*, node*, node*);

int main() {

	int n, x;
	while (~scanf("%d", &n)) {

		node *head = NULL, *tail = NULL;

		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			node *ret = push_back(head, tail, x);
			tail = ret;
		}

		selectionSort(head, tail);

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

void selectionSort(node* &head, node* &tail) {

	for (node *cur = head, *pcur = NULL; cur != NULL; pcur = cur, cur = cur->next) {
		int MIN = cur->value;
		node *target = cur, *ptarget = pcur;
		// find the minimum value
		for (node *iter = cur->next, *piter = cur; iter != NULL; piter = iter, iter = iter->next) {
			if (iter->value < MIN) {
				MIN = iter->value;
				target = iter, ptarget = piter;
			}
		}
		swap(cur, pcur, target, ptarget);
		// change the head address
		if (cur == head) head = target;
		// change the tail address
		if (target == tail) tail = cur;
		cur = target;
	}
}

void swap(node* cur, node* pcur, node* target, node* ptarget) {
	node *bakcur = cur->next, *baktarget = target->next;
	// prevent neighbor swap to link to self
	target->next = target == bakcur ? cur : bakcur;
	cur->next = cur == baktarget ? target : baktarget;
	if (pcur != NULL && pcur != target) pcur->next = target;
	if (ptarget != NULL && ptarget != cur) ptarget->next = cur;
}

