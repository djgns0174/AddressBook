#include "rm.h"
#include "node.h"
#include "data.h"

int rm(const char* name, const char* phone) {
	DATA* deleteData = (DATA*)malloc(sizeof(DATA));
	memset(deleteData, 0, sizeof(DATA));
	strcpy_s(deleteData->name, sizeof(deleteData->name), name);
	strcpy_s(deleteData->phone, sizeof(deleteData->phone), phone);

	deleteNode(deleteData);

	return 0;
}