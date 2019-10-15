/*
6주차 예제: 빙고 게임 - 구조 구현
*/
#include <stdio.h>

void initialize();
void erase_bingo(int[][5], int);
void print_bingo(int[][5]);
void print_winner(int winner);
int get_number(int);
int check_bingo(int [][5]);

// 빙고판
int ubingo[5][5];
int cbingo[5][5];

void main() {
	// 지역변수 선언
	int number, uwin, cwin;

	// 빙고판 초기화
	initialize();

	do {
		// 사용자의 빙고판 출력
		printf("사용자\n");
		print_bingo(ubingo);

		// 사용자가 번호를 선택
		number = get_number(0);
		// 사용자가 선택한 번호를 각각의 빙고판에서 지움
		erase_bingo(ubingo, number);
		erase_bingo(cbingo, number);

		// 컴퓨터가 번호를 선택
		number = get_number(1);
		// 컴퓨터가 선택한 번호를 각각의 빙고판에서 지움
		erase_bingo(ubingo, number);
		erase_bingo(cbingo, number);

		// 사용자가 빙고를 완성했는지 체크
		uwin = check_bingo(ubingo);

		// 컴퓨터가 빙고를 완성했는지 체크
		cwin = check_bingo(cbingo);
	} while (uwin + cwin == 0); // 둘다 완성하지 않은 동안 반복

	// 사용자와 컴퓨터의 빙고판을 출력
	printf("사용자\n");
	print_bingo(ubingo);
	printf("컴퓨터\n");
	print_bingo(cbingo);

	print_winner(cwin * 2 + uwin); // 승자를 표시: 1이면 사용자가 승리, 2이면 컴퓨터가 승리, 3이면 무승부

	return 0;
}

void initialize() {
}

void erase_bingo(int bingo[][5], int number) {
}

void print_bingo(int bingo[][5]) {
}

void print_winner(int winner) {
}

int get_number(int from) {
	return 1;
}

int check_bingo(int bingo[][5]) {
	return 1;
}
