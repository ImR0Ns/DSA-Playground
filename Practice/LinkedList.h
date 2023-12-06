#pragma once
#include <iostream>

//deleting and inserting starts from index 1
struct LinkedList {
	int data;
	LinkedList* next;

	explicit LinkedList(int data) : data(data), next(nullptr) {}

	void append(LinkedList* next);
	void prepend(LinkedList* replaceNode);
	void insertingNode(LinkedList* nodeToInsert, int position);
	void deleteNode(int position); //you can't delete the head;
	LinkedList* searchForNode(int value);
	void printList();
};