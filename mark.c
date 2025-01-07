#include "mark.h"
#include "data.h"
#include "list.h"
#include "tree.h"

int mark(const char* name, const char* phone) {
	DATA* markData = (DATA*)malloc(sizeof(DATA));
	memset(markData, 0, sizeof(DATA));

	strcpy_s(markData->name, sizeof(markData->name), name);
	strcpy_s(markData->phone, sizeof(markData->phone), phone);

	/*if (markNode(markData) == 0) {
		return 0;
	}*/

	if (markNodeAtTree(markData) == 0) {
		return 0;
	}

	return 1;
}