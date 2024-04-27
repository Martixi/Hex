//
// Created by admin on 27.03.2024.
//

#ifndef HEX_STACK_H
#define HEX_STACK_H
#include "List.h"


class Stack {

private:
	List stack;
	int size;

public:

	Stack();

	void add(int x, int y);

	int getSize();

	int passX();

	int passY();

	bool findPoint(int x, int y);

	void remove();

};


#endif //HEX_STACK_H
