#include<stdio.h>
#include<assert.h>
int main() {
	bool flag = 1;
	FILE* fp;
	fopen_s(&fp, "data.txt", "r");
	assert(fp != 0);
	fseek(fp, 0, SEEK_END);
	int fileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char* data = new char[fileSize];
	fread(data, sizeof(char), fileSize, fp);
	fclose(fp);
	int row = 0;
	int col = 0;
	int count = 0;
	for (int i = 0; i < fileSize; i++) {
		count++;
		if (data[i] == '\n') {
			if (row == 0) {
				col = count;
			}
			else if (col != count) {
				printf("—ñ”‚ª‚»‚ë‚Á‚Ä‚È‚¢‚æ");
				flag = 0;
			}
			row++;
			count = 0;
		}
	}
	if (fileSize % row != 0) {
		printf("s”‚ª‚»‚ë‚Á‚Ä‚È‚¢‚æ");
		flag = 0;
	}
	if (flag) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (data[j + i * col] == '1')printf("–");
				else if (data[j + i * col] == '0')printf("@");
			}
			printf("\n");
		}
	}
	delete[] data;
	return 0;
}