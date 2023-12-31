#include "data.h"
#include<assert.h>
#include<iostream>

void playeData(FILE* fp, bool* flag)
{
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
				std::cout << "列数がそろってないよ" << std::endl;
				flag = 0;
			}
			row++;
			count = 0;
		}
	}
	if (fileSize % row != 0) {
		std::cout << "行数がそろってないよ" << std::endl;
		flag = 0;
	}
	if (flag) {
		printData(data, row, col);
		lotatData(data, row, col,fileSize);

	}
	delete[] data;
}

void printData(char* data, int row, int col)
{
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (data[j + i * col] == '1')std::cout<<"＊";
				else if (data[j + i * col] == '0')std::cout<<"　";
			}
			std::cout << ::std::endl;
		}
		std::cout << ::std::endl;

}

void lotatData(char* data, int row, int col,int fileSize)
{
	//90度回転
	char* resultData = new char[row*col];
	int dx = 0;
	for (int i = 0; i < row; i++) {
	int dy = row-1;
		for (int j = 0; j < row; j++) {
			resultData[dy * col+dx] = data[j + i * col];
			dy--;
		}
		dx++;
	}
	printData(resultData, row, col);
	delete[] resultData;
}

