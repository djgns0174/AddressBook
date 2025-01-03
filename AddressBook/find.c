#include "find.h"
#include "node.h"
#include "data.h"

int findByName(const char* name) {

	DATA* findData = (DATA*)malloc(sizeof(DATA));
	memset(findData, 0, sizeof(DATA));
	strcpy_s(findData->name, sizeof(findData->name), name);

	findByNameNode(findData);

	return 0;
}