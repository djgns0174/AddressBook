#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#include "data.h"

typedef struct tNODE {
	struct tNODE* left;
	struct tNODE* right;
	struct DATA* data;
	bool mark;
}tNODE;

tNODE* gRoot;
int t_gSize;

tNODE* mgRoot;
int t_mgSize;

void initTree();
int insertNodeAtTree(DATA* newData);
void printTree(tNODE* node);
int deleteNodeAtTree(DATA* data);
tNODE* findNodeByPhoneAtTree(DATA* findData, tNODE** findNodeParent);
void findNodeByNameAtTree(tNODE* parent, DATA* findData);
tNODE* findNodeAtMarkTree(DATA* findData, tNODE** findNodeParent);
bool isMarkedAtTree(DATA* data);
int markNodeAtTree(DATA* markData);
int markNodeAtTree(DATA* markData);
void printMarkTree(tNODE* node);