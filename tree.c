#include "tree.h"
#include "data.h"

//초기화
void initTree() {
	gRoot = (tNODE*)malloc(sizeof(tNODE));
	memset(gRoot, 0, sizeof(tNODE));
	gRoot->data = NULL;
	//gRoot->data = (DATA*)malloc(sizeof(DATA));
	//memset(gRoot->data, 0, sizeof(DATA));

	mgRoot = (tNODE*)malloc(sizeof(tNODE));
	memset(mgRoot, 0, sizeof(tNODE));
	mgRoot->data = NULL;
	//mgRoot->data = (DATA*)malloc(sizeof(DATA));
	//memset(mgRoot->data, 0, sizeof(DATA));
}

//삽입
int insertNodeAtTree(DATA* newData) {
	if (gRoot->data == NULL) {
		gRoot->data = newData;
		return 0;
	}

	tNODE* newNode = (tNODE*)malloc(sizeof(tNODE));
	memset(newNode, 0, sizeof(tNODE));
	newNode->data = newData;

	tNODE* temp = gRoot;

	while (1) {
		if (strcmp(temp->data->name, newData->name) > 0) {
			if (temp->left == NULL) {
				temp->left = newNode;
				return 0;
			}
			temp = temp->left;
			continue;
		}
		else if (strcmp(temp->data->name, newData->name) < 0) {
			if (temp->right == NULL) {
				temp->right = newNode;
				return 0;
			}
			temp = temp->right;
			continue;
		}
		else {
			if (strcmp(temp->data->phone, newData->phone) > 0) {
				if (temp->left == NULL) {
					temp->left = newNode;
					return 0;
				}
				temp = temp->left;
				continue;
			}
			else if (strcmp(temp->data->phone, newData->phone) < 0) {
				if (temp->right == NULL) {
					temp->right = newNode;
					return 0;
				}
				temp = temp->right;
				continue;
			}
			else {
				printf("이미 등록된 연락처입니다.\n");
				return 1;
			}
		}
	}

	return 1;
}

//하나삭제
int deleteNodeAtTree(DATA* deleteData) {
	tNODE* findNodeParent = NULL;
	tNODE* findNode = findNodeByPhoneAtTree(deleteData, &findNodeParent);

	if (findNode == NULL) {
		return 1;
	}

	if (findNode == gRoot) {
		if (findNode->left != NULL) {
			gRoot = findNode->left;
			tNODE* temp = findNode;
			while (1) {
				if (temp->right == NULL) {
					break;
				}
				temp = temp->right;
			}
			temp->right = findNode->right;
		}
		else {
			gRoot = findNode->right;
		}
		return 0;
	}

	if (findNodeParent->left == findNode) {
		if (findNode->left != NULL) {
			findNodeParent->left = findNode->left;
			tNODE* temp = findNode;
			while (1) {
				if (temp->right == NULL) {
					break;
				}
				temp = temp->right;
			}
			temp->right = findNode->right;
		}
		else {
			findNodeParent->left= findNode->right;
		}
	}
	else {
		if (findNode->left != NULL) {
			findNodeParent->right = findNode->left;
			tNODE* temp = findNode;
			while (1) {
				if (temp->right == NULL) {
					break;
				}
				temp = temp->right;
			}
			temp->right = findNode->right;
		}
		else {
			findNodeParent->right = findNode->right;
		}
	}

	return 0;
}

tNODE* findNodeByPhoneAtTree(DATA* findData, tNODE** findNodeParent) {
	tNODE* temp = gRoot;

	while (1) {
		if (temp == NULL) break;

		if (temp->data == NULL) {
			printf("연락처(%s:%s)가 존재하지 않습니다.\n", findData->name, findData->phone);
			return NULL;
		}

		if (strcmp(temp->data->phone, findData->phone) > 0) {
			*findNodeParent = temp;
			temp = temp->left;
			continue;
		}
		else if (strcmp(temp->data->phone, findData->phone) < 0) {
			*findNodeParent = temp;
			temp = temp->right;
			continue;
		}
		else {
			printf("%s:%s 검색 완료\n", temp->data->name, temp->data->phone);
			return temp;
		}
	}
	
	return NULL;
}

void findNodeByNameAtTree(tNODE* parent, DATA* findData) {

	if (parent == NULL)
		return;

	if (strcmp(parent->data->name, findData->name) > 0) {
		findNodeByNameAtTree(parent->left, findData);
	}
	else if (strcmp(parent->data->name, findData->name) < 0) {
		findNodeByNameAtTree(parent->right, findData);
	}
	else {
		printf("%s:%s\n", parent->data->name, parent->data->phone);
		findNodeByNameAtTree(parent->left, findData);
		findNodeByNameAtTree(parent->right, findData);
	}
}

tNODE* findNodeAtMarkTree(DATA* findData, tNODE** findNodeParent) {
	tNODE* temp = mgRoot;
	while (1) {
		if (temp == NULL) return NULL;
		if (temp->data == NULL) return NULL;

		if (strcmp(temp->data->phone, findData->phone) > 0) {
			*findNodeParent = temp;
			temp = temp->left;
			continue;
		}
		else if (strcmp(temp->data->phone, findData->phone) < 0) {
			*findNodeParent = temp;
			temp = temp->right;
			continue;
		}
		else {
			printf("연락처(%s:%s)가 즐겨찾기에서 검색 완료\n", temp->data->name, temp->data->phone);
			return temp;
		}
	}

	printf("연락처(%s:%s)가 즐겨찾기목록에 존재하지 않습니다.\n", findData->name, findData->phone);
	return NULL;
}

bool isMarkedAtTree(DATA* data) {
	tNODE* findNodeParent = NULL;
	tNODE* findNode = findNodeAtMarkTree(data, &findNodeParent);
	if (findNode != NULL) {
		return true;
	}
	return false;
}

int markNodeAtTree(DATA* markData) {	//tree mark 기능 테스트 필요
	if (isMarkedAtTree(markData)) {
		printf("이미 즐찾등록 됐습니다.\n");
		return 1;
	}

	tNODE* findNodeParent = NULL;
	tNODE* findNode = findNodeByPhoneAtTree(markData, &findNodeParent);
	if (findNode == NULL) return 1;

	if (mgRoot->data == NULL) {
		mgRoot->data = markData;
		return 0;
	}

	tNODE* markNode = (tNODE*)malloc(sizeof(tNODE));
	memset(markNode, 0, sizeof(tNODE));
	markNode->data = (DATA*)malloc(sizeof(DATA));
	memset(markNode->data, 0, sizeof(DATA));
	strcpy_s(markNode->data->name, sizeof(markNode->data->name), markData->name);
	strcpy_s(markNode->data->phone, sizeof(markNode->data->phone), markData->phone);

	tNODE* temp = mgRoot;

	while (temp->data != NULL) {
		if (strcmp(temp->data->name, markData->name) > 0) {
			if (temp->left == NULL) {
				temp->left = markNode;
				return 0;
			}
			temp = temp->left;
			continue;
		}
		else if (strcmp(temp->data->name, markData->name) < 0) {
			if (temp->right == NULL) {
				temp->right = markNode;
				return 0;
			}
			temp = temp->right;
			continue;
		}
		else {
			if (strcmp(temp->data->phone, markData->phone) > 0) {
				if (temp->left == NULL) {
					temp->left = markNode;
					return 0;
				}
				temp = temp->left;
				continue;
			}
			else {
				if (temp->right == NULL) {
					temp->right = markNode;
					return 0;
				}
				temp = temp->right;
				continue;
			}
		}
	}
	return 1;
}

int unMarkNodeAtTree(DATA* unMarkData) {
	if (!isMarkedAtTree(unMarkData)) {
		printf("이미 즐찾목록에 존재하지 않습니다.\n");
		return 1;
	}

	tNODE* findNodeParent = NULL;
	tNODE* findNode = findNodeAtMarkTree(unMarkData, &findNodeParent);

	if (findNode == mgRoot) {
		if (findNode->left != NULL) {
			mgRoot = findNode->left;

			if (findNode->right != NULL) {
				tNODE* temp = findNode;
				while (1) {
					if (temp->right == NULL) break;
					temp = temp->right;
				}
				temp->right = findNode->right;
			}
		}
		else {
			mgRoot = findNode->right;
		}
		return 0;
	}

	//부모노드에서 왼쪽노드를 지울때
	if (findNodeParent->left == findNode) {
		if (findNode->left != NULL) {
			findNodeParent->left = findNode->left;

			if (findNode->right != NULL) {
				tNODE* temp = findNode;
				while (1) {
					if (temp->right == NULL) break;
					temp = temp->right;
				}
				temp->right = findNode->right;
			}
		}
		else {
			findNodeParent->left = findNode->right;
		}
	}
	//부모노드에서 오른쪽노드를 지울때
	else {
		if (findNode->left != NULL) {
			findNodeParent->right = findNode->left;

			if (findNode->right != NULL) {
				tNODE* temp = findNode;
				while (1) {
					if (temp->right == NULL) break;
					temp = temp->right;
				}
				temp->right = findNode->right;
			}
		}
		else {
			findNodeParent->right = findNode->right;
		}
	}

	return 0;
}

//출력
void printTree(tNODE* node) {
	if (node == NULL) return;
	if (node->data == NULL) return;

	printTree(node->left);
	printf("%s:%s\n", node->data->name, node->data->phone);
	printTree(node->right);
}

void printMarkTree(tNODE* node) {
	if (node == NULL) return;
	if (node->data == NULL) return;
	
	printMarkTree(node->left);
	printf("즐찾 %s:%s\n", node->data->name, node->data->phone);
	printMarkTree(node->right);
}