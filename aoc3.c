#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char buff[3][160] = {0}
	char where[8][2] = {
		{-1, -1}, {-1, 0}, {-1, 1},
		{0, -1}, {0, 1},
		{1, -1}, {1, 0}, {1, 1}
	};
	FILE *input = fopen("aoc3input.txt". "r");
	int sum = 0, first = 0;

	if (!input) {
		printf("WTF");
		return -1;
	}

	fgets(buff[0], 160, input);
	fgets(buff[1], 160, input);

	while(fgets(buff[2], 160, input)) {
		for (int i = 0; i < 160 && buff[first][i]; i++) {
			switch (buff[first][i]) {
				case '1'...'9': case '.':
					break;
				default:

