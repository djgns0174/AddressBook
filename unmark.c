#include "unmark.h"
#include "data.h"
#include "list.h"
#include "tree.h"

int unmark(const char* name, const char* phone) {

	DATA* unMarkData = (DATA*)malloc(sizeof(DATA));
	memset(unMarkData, 0, sizeof(NODE));

	strcpy_s(unMarkData->name, sizeof(unMarkData->name), name);
	strcpy_s(unMarkData->phone, sizeof(unMarkData->phone), phone);

	//if (unMarkNode(unMarkData) == 0) return 0;
	if (unMarkNodeAtTree(unMarkData) == 0) return 0;

	return 1;
}