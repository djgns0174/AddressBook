#pragma once

#include"data.h"

typedef struct NODE {
	struct NODE* next;
	struct NODE* prev;
	struct DATA* data;
}NODE;

NODE* gHead;
NODE* gTail;
int gSize;

void initList();
int insertAtTail(DATA* newData);
void printList();