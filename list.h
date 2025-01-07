#pragma once

#include<stdbool.h>
#include "data.h"

typedef struct NODE {
	struct NODE* next;
	struct NODE* prev;
	struct DATA* data;
	bool mark;
}NODE;

NODE* gHead;
NODE* gTail;
int gSize;

NODE* mgHead;
NODE* mgTail;
int mgSize;

void initList();
int insertAtTail(DATA* newData);
int printList();
int releaseList();
int deleteNode(DATA* deleteData);
NODE* findByPhoneNode(DATA* findData);
NODE* findByNameNode(DATA* findData);
NODE* findNodeAtMarkList(DATA* findData);
bool isMarkedAtList(DATA* data);
int markNode(DATA* markData);
int unMarkNode(DATA* unMarkData);
int printMarkList();