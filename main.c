#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

#include "add.h"
#include "c.h"
#include "cmark.h"
#include "find.h"
#include "mark.h"
#include "unmark.h"
#include "rm.h"
#include "list.h"
#include "tree.h"

#define MAX_NAME 64
#define MAX_PHONE 9
#define TEST_DATA_SIZE 1000000

int inputTestData() {
	for (int i = 0; i < TEST_DATA_SIZE; i++) {
		char name[64]; char phone[10];
		snprintf(name, sizeof(name), "test%d", i);
		snprintf(phone, sizeof(phone), "%d", i);
		add(name, phone);
	}
	return 0;
}

void parseInputData(char* name, char* phone) {
	char szData[128]; char* temp;
	scanf_s("%127s", szData, (unsigned)_countof(szData));  // 버퍼 크기 전달

	char* token = strtok_s(szData, ":", &temp);
	strcpy_s(name, MAX_NAME, token); //이름 길이 64로 고정

	token = strtok_s(NULL, ":", &temp);
	strcpy_s(phone, MAX_PHONE, token);
}

int main() {
	LARGE_INTEGER frequency, start, end;	// 시간 변수

	char input[64];

	printf("==============================================================================================================\n\n");
	printf("명령어 매뉴얼\n저장:add  즐겨찾기:mark  즐겨찾기 목록:cmark  즐겨찾기 해제:unmark  모든목록:c  검색:find  삭제:rm  종료:exit\n\n");
	printf("==============================================================================================================\n\n");

	initList();
	initTree();

	while (1) {
		printf("명령어를 입력해주세요 : ");
 		scanf_s("%s", input, sizeof(input));

		if (strcmp(input, "add") == 0) {
			char name[64];
			char phone[64];

			printf("이름과 전화번호를 입력해주세요(홍길동:12345678) : ");
			parseInputData(name, phone);
			add(name, phone);	// 저장

			printf("성공적으로 저장되었습니다.\n");
			continue;
		}
		else if (strcmp(input, "mark") == 0) {
			double elapsed;
			QueryPerformanceFrequency(&frequency);

			char name[64];
			char phone[64];

			printf("이름과 전화번호를 입력해주세요(홍길동:12345678) : ");
			parseInputData(name, phone);

			QueryPerformanceCounter(&start);
			if (mark(name, phone) == 0)
				printf("성공적으로 즐겨찾기되었습니다.\n");
			QueryPerformanceCounter(&end);
			elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
			printf("Execution time: %.6f seconds\n", elapsed);

			continue;
		}
		else if (strcmp(input, "cmark") == 0) {
			double elapsed;
			QueryPerformanceFrequency(&frequency);
			QueryPerformanceCounter(&start);

			cmark();

			QueryPerformanceCounter(&end);
			elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
			printf("Execution time: %.6f seconds\n", elapsed);
			continue;
		}
		else if (strcmp(input, "unmark") == 0) {
			double elapsed;
			QueryPerformanceFrequency(&frequency);

			char name[64];
			char phone[64];

			printf("이름과 전화번호를 입력해주세요(홍길동:12345678) : ");
			parseInputData(name, phone);

			QueryPerformanceCounter(&start);
			if (unmark(name, phone) == 0) printf("즐찾 해제 성공\n");
			QueryPerformanceCounter(&end);
			elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
			printf("Execution time: %.6f seconds\n", elapsed);

			continue;
		}
		else if (strcmp(input, "c") == 0) {
			double elapsed;
			QueryPerformanceFrequency(&frequency);
			QueryPerformanceCounter(&start);

			c();

			QueryPerformanceCounter(&end);
			elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
			printf("Execution time: %.6f seconds\n", elapsed);
			continue;
		}
		else if (strcmp(input, "find") == 0) {
			double elapsed;
			QueryPerformanceFrequency(&frequency);

			char name[64];

			printf("이름을 입력해주세요:");
			scanf_s("%s", name, sizeof(name));

			// 시작 시간
			QueryPerformanceCounter(&start);

			findByName(name);

			QueryPerformanceCounter(&end);
			elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
			printf("Execution time: %.6f seconds\n", elapsed);

			continue;
		}
		else if (strcmp(input, "rm") == 0) {
			double elapsed;
			QueryPerformanceFrequency(&frequency);

			char name[64];
			char phone[64];

			printf("이름과 전화번호를 입력해주세요(홍길동:12345678) : ");
			parseInputData(name, phone);

			QueryPerformanceCounter(&start);

			if (rm(name, phone) == 0)
				printf("성공적으로 삭제되었습니다.\n");

			QueryPerformanceCounter(&end);
			elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
			printf("Execution time: %.6f seconds\n", elapsed);

			continue;
		}
		else if (strcmp(input, "testinput") == 0) {
			if (inputTestData() == 0) {
				printf("테스트 데이터가 생성되었습니다.\n");
			}
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