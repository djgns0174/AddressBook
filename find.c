#include "find.h"
#include "list.h"
#include "data.h"
#include "tree.h"

int findByName(const char* name) {

	DATA* findData = (DATA*)malloc(sizeof(DATA));
	memset(findData, 0, sizeof(DATA));
	strcpy_s(findData->name, sizeof(findData->name), name);

	//findByNameNode(findData); //list
	findNodeByNameAtTree(gRoot, findData);

	return 0;
}