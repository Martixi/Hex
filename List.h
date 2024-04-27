//
// Created by admin on 27.03.2024.
//

#ifndef HEX_LIST_H
#define HEX_LIST_H

struct Node{
	int x;
	int y;
	Node* next;
};

class List {

private:

	Node* head;

public:

	List();

	void pushFront(int x, int y);

	int getFirstX();

	int getFirstY();

	void removeFirst();

	bool findPoint(int x, int y);

	void clear();

	~List();

};



#endif //HEX_LIST_H
