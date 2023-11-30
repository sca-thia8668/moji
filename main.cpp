#include<stdio.h>
#include"data.h"
int main() {
	bool flag = 1;
	FILE* fp = nullptr;
	loadData(fp, &flag);
	return 0;
}