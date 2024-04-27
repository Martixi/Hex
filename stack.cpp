//
// Created by admin on 27.03.2024.
//

#include "stack.h"

Stack::Stack() {
	size = 0;
}


void Stack::add(int x, int y) {
	stack.pushFront(x, y);
	size++;
}

int Stack::getSize(){
	return size;
}

int Stack::passX(){
	if (size == 0) return 0;
	else{
		return stack.getFirstX();
	}
}

int Stack::passY(){
	if (size == 0) return 0;
	else{
		return stack.getFirstY();
	}
}

bool Stack::findPoint(int x, int y) {
	if (!size) return false;
	else if(stack.findPoint(x, y)) return true;
	else return false;
}

void Stack::remove() {
	if (size != 0) {
		stack.removeFirst();
		size--;
		return;
	} else{
		return;
	}
}
