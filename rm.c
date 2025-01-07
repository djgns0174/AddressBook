#include "rm.h"
#include "list.h"
#include "data.h"
#include "tree.h"

int rm(const char* name, const char* phone) {
	DATA* deleteData = (DATA*)malloc(sizeof(DATA));
	memset(deleteData, 0, sizeof(DATA));
	strcpy_s(deleteData->name, sizeof(deleteData->name), name);
	strcpy_s(deleteData->phone, sizeof(deleteData->phone), phone);


	//if (deleteNode(deleteData) == 1) return 1;
	//if (unMarkNode(deleteData) == 1) return 1;
	if (deleteNodeAtTree(deleteData) == 1) return 1;
	if (unMarkNodeAtTree(deleteData) == 1) return 1;

	return 0;
}