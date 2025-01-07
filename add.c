#include "add.h"

int add(const char* name, const char* phone)
{
	DATA* newData = (DATA*)malloc(sizeof(DATA));
	memset(newData, 0, sizeof(DATA));
	strcpy_s(newData->name, sizeof(newData->name), name);
	strcpy_s(newData->phone, sizeof(newData->phone), phone);

	//insertAtTail(newData);
	insertNodeAtTree(newData);

	return 0;
}