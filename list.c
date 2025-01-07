#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "list.h"
#include "data.h"

//초기화
void initList() {
	gHead = (NODE*)malloc(sizeof(NODE));
	gTail = (NODE*)malloc(sizeof(NODE));
	memset(gHead, 0, sizeof(NODE));
	memset(gTail, 0, sizeof(NODE));

	gHead->next = gTail;
	gTail->prev = gHead;
	gSize = 0;

	mgHead = (NODE*)malloc(sizeof(NODE));
	mgTail = (NODE*)malloc(sizeof(NODE));
	memset(mgHead, 0, sizeof(NODE));
	memset(mgTail, 0, sizeof(NODE));

	mgHead->next = mgTail;
	mgTail->prev = mgHead;
	mgSize = 0;
}

//저장
int insertAtTail(DATA* newData) {

	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	memset(newNode, 0, sizeof(NODE));
	newNode->data = newData;

	//데이터가 없을때
	if (gHead->next == gTail) {
		gHead->next = newNode;
		gTail->prev = newNode;

		newNode->next = gTail;
		newNode->prev = gHead;

		return ++(gSize);
	}

	//데이터가 존재할때
	NODE* temp = gTail->prev;

	temp->next = newNode;
	newNode->next = gTail;

	gTail->prev = newNode;
	newNode->prev = temp;

	return ++(gSize);
}

//전체 출력
int printList() {
	NODE* temp = gHead->next;

	while (temp != gTail) {
		printf("%s:%s\n", temp->data->name, temp->data->phone);
		temp = temp->next;
	}

	printf("총 데이터 개수 : %d\n", gSize);

	return gSize;
}

//전체 삭제
int releaseList() {
	NODE* temp = gHead->next;

	while (temp != gTail) {
		NODE* deleteNode = temp;
		printf("%s:%s 연락처 삭제 완료\n", deleteNode->data->name, deleteNode->data->phone);
		free(deleteNode);

		temp = temp->next;
		gSize--;
	}

	gHead->next = gTail;
	gTail->prev = gHead;

	return gSize;
}

//하나 삭제
int deleteNode(DATA* deleteData) {
	NODE* temp = findByPhoneNode(deleteData);

	if (temp == NULL) {
		//printf("연락처(%s:%s)가 존재하지 않습니다. 다시 확인해주세요\n", deleteData->name, deleteData->phone);
		return gSize;
	}

	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	printf("%s:%s 연락처 삭제 완료\n", temp->data->name, temp->data->phone);
	free(temp);

	return --gSize;
}

// 데이터 검색
NODE* findByPhoneNode(DATA* findData) {
	NODE* temp = gHead->next;

	while (temp != gTail) {
		if (strcmp(temp->data->phone, findData->phone) == 0) {
			printf("%s:%s 연락처 검색 완료\n", temp->data->name, temp->data->phone);
			return temp;
		}

		temp = temp->next;
	}

	printf("연락처(%s:%s)가 존재하지 않습니다. 다시 확인해주세요\n", findData->name, findData->phone);
	return NULL;
}

NODE* findByNameNode(DATA* findData) {
	NODE* temp = gHead->next;

	while (temp != gTail) {
		if (strcmp(temp->data->name, findData->name) == 0) {
			printf("%s:%s 연락처 검색 완료\n", temp->data->name, temp->data->phone);
		}
		temp = temp->next;
	}

	return;
}

NODE* findNodeAtMarkList(DATA* findData) {
	NODE* temp = mgHead->next;

	while (temp != mgTail) {
		if (strcmp(temp->data->phone, findData->phone) == 0) {
			printf("연락처(%s:%s) 즐겨찾기에서 검색 완료\n", temp->data->name, temp->data->phone);
			return temp;
		}
		temp = temp->next;
	}

	printf("연락처(%s:%s)가 즐겨찾기목록에 존재하지 않습니다.\n", findData->name, findData->phone);
	return NULL;
}

bool isMarkedAtList(DATA* data) {
	NODE* findNode = findNodeAtMarkList(data);
	if (findNode != NULL)
		return true;
	return false;
}

//즐찾 등록
int markNode(DATA* markData) {

	if (isMarkedAtList(markData)) {
		printf("이미 즐찾등록 됐습니다.\n");
		return 1;
	}

	NODE* findNode = findByPhoneNode(markData);	

	if (findNode == NULL) {
		return 1;
	}

	NODE* temp = (NODE*)malloc(sizeof(NODE)); //찾은 노드를 복사할 노드
	memset(temp, 0, sizeof(NODE));

	temp->data = (DATA*)malloc(sizeof(DATA));
	memset(temp->data, 0, sizeof(DATA));

	strcpy_s(temp->data->name, sizeof(temp->data->name), findNode->data->name);
	strcpy_s(temp->data->phone, sizeof(temp->data->phone), findNode->data->phone);

	if (findNode != NULL) {
		findNode->mark = true;
		temp->mark = true;

		if (mgHead->next == mgTail) {
			mgHead->next = temp;
			temp->next = mgTail;

			mgTail->prev = temp;
			temp->prev = mgHead;

			++mgSize;

			return 0;
		}

		mgTail->prev->next = temp;
		temp->next = mgTail;

		mgTail->prev = temp;
		temp->prev = mgTail->prev;
		++mgSize;

		return 0;
	}

	return 1;
}

int unMarkNode(DATA* unMarkData) {

	NODE* mfindNode = findNodeAtMarkList(unMarkData);

	if (mfindNode == NULL) {
		return 1;
	}

	mfindNode->prev->next = mfindNode->next;
	mfindNode->next->prev = mfindNode->prev;

	printf("즐겨찾기 해제 -> %s:%s\n", mfindNode->data->name, mfindNode->data->phone);
	mfindNode->mark = false;
	free(mfindNode);

	mgSize--;
	return 0;
}

int printMarkList() {
	NODE* temp = mgHead->next;

	printf("===========즐겨찾기===========\n");
	while (temp != mgTail) {
		printf("%s:%s\n", temp->data->name, temp->data->phone);
		temp = temp->next;
	}
	printf("==============================\n");

	return mgSize;
}