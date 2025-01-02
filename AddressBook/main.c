#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "add.h"
#include "c.h"
#include "cmark.h"
#include "find.h"
#include "mark.h"
#include "rm.h"

#include "node.h"

int main() {

	char input[64];

	printf("===================================================================================================\n\n");
	printf("명령어 매뉴얼\n저장:add  즐겨찾기:mark  즐겨찾기 목록:cmark  모든목록:c  검색:find  삭제:rm  종료:exit\n");
	printf("===================================================================================================\n\n");

	initList();


	while (1) {
		printf("명령어를 입력해주세요 : ");
		scanf_s("%s", input, sizeof(input));

		if (strcmp(input, "add") == 0) {
			char szData[128];
			char* phone; char* name; char* temp;

			printf("이름과 전화번호를 입력해주세요(홍길동:12345678) :");
			scanf_s("%127s", szData, (unsigned)_countof(szData));  // 버퍼 크기 전달
			
			name = strtok_s(szData, ":", &temp);
			phone = strtok_s(NULL, ":", &temp);

			add(name, phone);	// 저장

			printf("성공적으로 저장되었습니다.\n");
			continue;
		}
		else if (strcmp(input, "mark") == 0) {
			printf("mark\n");
			continue;
		}
		else if (strcmp(input, "cmark") == 0) {
			printf("cmark\n");
			continue;
		}
		else if (strcmp(input, "c") == 0) {
			printList();
			continue;
		}
		else if (strcmp(input, "find") == 0) {
			printf("find\n");
			continue;
		}
		else if (strcmp(input, "rm") == 0) {
			printf("rm\n");
			continue;
		}
		else if (strcmp(input, "exit") == 0) {
			break;
		}
		else {
			printf("명령어를 잘못 입력했습니다.\n");
			continue;
		}
	}
	return 0;
}