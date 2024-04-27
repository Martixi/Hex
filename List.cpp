//
// Created by admin on 27.03.2024.
//

#include "List.h"


List::List() {
	head = nullptr;
}

void List::pushFront(int x, int y){
	Node* point = new Node;
	point->x = x;
	point->y = y;

	if (head == nullptr){
		head = point;
		point->next = nullptr;
	} else{
		Node* tmp = head;
		head = point;
		point->next = tmp;
	}
}

int List::getFirstX(){
	return head->x;
}

int List::getFirstY(){
	return head->y;
}

void List::removeFirst(){
	if (head == nullptr) return;
	else if (head->next == nullptr) clear();
	else{
		Node* tmp = head->next;
		delete head;
		head = tmp;
	}
}

bool List::findPoint(int x, int y) {
	Node* tmp = head;
	if (tmp->x == x and tmp->y == y) return true;
	while (tmp->next != nullptr){
		if (tmp->x == x and tmp->y == y) return true;
		tmp = tmp->next;
	}
	if (tmp->x == x and tmp->y == y) return true;
	return false;
}

void List::clear() {
	Node* tmp = head;
	if (tmp == nullptr) return;
	Node* helper;
	while (tmp->next != nullptr){
		helper = tmp->next;
		delete tmp;
		tmp = helper;
	}
	delete tmp;
	head = nullptr;
}

List::~List() {
	clear();
}
