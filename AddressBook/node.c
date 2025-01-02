#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "node.h"
#include "data.h"

void initList() {
	gHead = (NODE*)malloc(sizeof(NODE));
	gTail = (NODE*)malloc(sizeof(NODE));
	memset(gHead, 0, sizeof(NODE));
	memset(gTail, 0, sizeof(NODE));

	gHead->next = gTail;
	gTail->prev = gHead;
	gSize = 0;
}

int insertAtTail (DATA* newData) {

	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	memset(newNode, 0, sizeof(NODE));
	newNode->data = newData;

	//데이터가 없을때
	if (gHead->next == gTail) {
		gHead->next = newNode;
		gTail->prev = newNode;

		newNode->next = gTail;
		newNode->prev = gHead;

		return ++(gSize);
	}

	//데이터가 존재할때
	NODE* temp = gTail->prev;

	temp->next = newNode;
	newNode->next = gTail;

	gTail->prev = newNode;
	newNode->prev = temp;

	return ++(gSize);
}

void printList() {
	NODE* temp = gHead->next;

	while (temp != gTail) {
		printf("%s:%s\n", temp->data->name, temp->data->phone);
		temp = temp->next;
	}

	printf("총 데이터 개수 : %d\n", gSize);
}