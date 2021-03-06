#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 파일에 들어 있는 단어의 최대 수
#define MAXWORD 1000
#define DELEMETERS " ,.!?\t\n"

// 함수 원형 선언
void initialize();
void read_file();
void print_words();
void deallocate();

// 단어를 저장할 구조체 선언
struct word_count {
	char *str; // 단어를 저장할 문자형 포인터
	int count; // 단어가 나타난 횟수
};

// 단어를 저장할 배열(포인터로 선언)
struct word_count *words;

// 배열에 저장되어 있는 단어 수
int nwords;

int main() {
	initialize();  // 구조체 배열을 할당하고 초기화
	read_file();   // 파일에서 단어를 추출하여 words[]에 저장
	print_words(); // words[]에 저장되어 있는 단어와 횟수를 출력
	deallocate();  // 동적으로 할당 받은 기억장소를 해제
	return 0;
}

void initialize() {
	// 구조체 배열을 동적으로 할당하고 관련 변수 초기화
	words = (struct word_count *) malloc(sizeof(struct word_count) * MAXWORD);
	memset(words, 0, sizeof(struct word_count) * MAXWORD);
	nwords = 0;
}

void read_file() {
	char buffer[256], *token;
	FILE *fp = fopen("programming.txt", "r");
	while (fgets(buffer, 255, fp)) {
		// printf("%s", buffer);
		token = strtok(buffer, DELEMETERS);
		while (token) {
			printf("%s\n", token);
			token = strtok(NULL, DELEMETERS);
		}
	}
	fclose(fp);
}

void print_words() {
	// 구현을 미룸
}

void deallocate() {
	free(words);
}