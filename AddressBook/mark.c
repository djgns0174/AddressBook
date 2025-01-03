#include "mark.h"
#include "data.h"
#include "node.h"

int mark(const char* name, const char* phone) {
	DATA* markData = (DATA*)malloc(sizeof(DATA));
	memset(markData, 0, sizeof(DATA));

	strcpy_s(markData->name, sizeof(markData->name), name);
	strcpy_s(markData->phone, sizeof(markData->phone), phone);

	markNode(markData);

	return 0;
}