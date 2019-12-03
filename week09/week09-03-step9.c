#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���Ͽ� ��� �ִ� �ܾ��� �ִ� ��
#define MAXWORD 1000
#define DELEMETERS " ,.!?\t\n"

// �Լ� ���� ����
void initialize();
void read_file();
void move_downward(int);
void insert_data(int, const char *);
void print_words();
void deallocate();
void convert_lower(char *);
int linear_search(const char *, int *);

// �ܾ ������ ����ü ����
struct word_count {
	char *str; // �ܾ ������ ������ ������
	int count; // �ܾ ��Ÿ�� Ƚ��
};

// �ܾ ������ �迭(�����ͷ� ����)
struct word_count *words;

// �迭�� ����Ǿ� �ִ� �ܾ� ��
int nwords;

int main() {
	initialize();  // ����ü �迭�� �Ҵ��ϰ� �ʱ�ȭ
	read_file();   // ���Ͽ��� �ܾ �����Ͽ� words[]�� ����
	print_words(); // words[]�� ����Ǿ� �ִ� �ܾ�� Ƚ���� ���
	deallocate();  // �������� �Ҵ� ���� �����Ҹ� ����
	return 0;
}

void initialize() {
	// ����ü �迭�� �������� �Ҵ��ϰ� ���� ���� �ʱ�ȭ
	words = (struct word_count *) malloc(sizeof(struct word_count) * MAXWORD);
	memset(words, 0, sizeof(struct word_count) * MAXWORD);
	nwords = 0;
}

void read_file() {
	char buffer[256], *token;
	int found, index;
	FILE *fp = fopen("programming.txt", "r");
	while (fgets(buffer, 255, fp)) {
		token = strtok(buffer, DELEMETERS);
		while (token) {
			convert_lower(token);
			index = linear_search(token, &found);

			if (found) {
				// �ܾ �̹� �ִٸ� �ش� �ܾ��� ī��Ʈ�� ����
				words[index].count++;
			}
			else {
				move_downward(index); // �ܾ ��ĭ�� �ڷ� �ű��
				insert_data(index, token); // �ܾ �ش� ��ġ�� �߰�.
			}
			token = strtok(NULL, DELEMETERS);
		}
	}
	fclose(fp);
}

void move_downward(int index) {
	// index���� �� ������ �ܾ���� �ڷ� �� ĭ�� �ű�
	int n;
	if (nwords < MAXWORD - 1) {
		// �ܾ� ���� �迭�� �ִ� ���� �ʰ����� ������
		for (n = nwords; n >= index; n--) {
			// words[n + 1].str = words[n].str;
			// words[n + 1].count = words[n].count;
			words[n + 1] = words[n];
		}
	}
}

void insert_data(int index, const char *word) {
	// index�� �ش��ϴ� ��ġ�� word �߰�
	int size;
	if (nwords < MAXWORD - 1) {
		// �ܾ� ���� �迭�� �ִ� ���� �ʰ����� ������
		size = strlen(word) + 1;
		words[index].str = (char *)malloc(size);
		strcpy(words[index].str, word);
		words[index].count = 1;
		nwords++;
	}

}

void convert_lower(char *str) {
	while (*str) {
		*str = tolower(*str);
		str++;
	}
}

int linear_search(const char *key, int *found) {
	int n, compare;

	*found = 0; // ã�� ���������� ����

	for (n = 0; n < nwords; n++) {
		compare = strcmp(key, words[n].str);
		if (compare <= 0) {
			*found = compare == 0; // compare�� 0�̸� ã��
			break;
		}
	}

	// �迭�� �ε����� ����
	return n;
}

void print_words() {
	// ������ �̷�
}

void deallocate() {
	int n;
	for (n = 0; n < nwords; n++) {
		// words �迭 ���� �������� �Ҵ�� str ���ڿ� �迭 ����
		if (words[n].str) free(words[n].str);
	}
	free(words);
}