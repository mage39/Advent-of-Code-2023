#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char buff[3][160] = {0};
	char where[8][2] = {
		{-1, -1}, {-1, 0}, {-1, 1},
		{0,  -1}, 		   {0,  1},
		{1,  -1}, {1,  0}, {1,  1}
	};
	FILE *input = fopen("aoc3input.txt", "r");
	int sum = 0, row = 0, lines = 2;

	if (!input) {
		printf("WTF");
		return -1;
	}

	fgets(buff[0], 150, input);
	fgets(buff[1], 150, input);

	while(fgets(buff[2], 150, input)) {
		start:
		lines++;
		for (int i = 0; i < 150 && buff[row][i]; i++) {
			switch (buff[row][i]) {
			case '0'...'9': case '.':
				break;
			default:
				for (int j = 0; j < 8; j++) {
					char num[4] = {0};
					if (row < 1 && i < 1 && (j < 4 || j == 5)) break;
					if (row > 1 && i < 1 && (j == 0 || j == 3 || j > 4)) break;
					if (row < 1 && i > 138 && (j < 4 || j == 5)) break;
					if (row > 1 && i < 138 && (j == 0 || j == 3 || j > 4)) break;

					switch (buff[row + where[j][0]][i + where[j][1]]) {
					case '0'...'9':
						for (int k = 0; k < 3; k++) {
							int offset = i + where[j][1] - k;

							switch (buff[row + where[j][0]][offset]) {
							case '0'...'9':
								break;
							default:
								for (int l = 0; l <= k; l++) {
									num[l] = buff[row + where[j][0]][offset + l];
								}
								goto break3;
							}
						}
					}
					break3:
					sum += atoi(num);
				}
			}
		}
		
		if (!row || lines == 139) {
			row++;
			goto start;
		} else {
			memcpy(buff[0], buff[1], 150);
			memcpy(buff[1], buff[0], 150);
		}
	}

	printf("%d\n", sum);
	fclose(input);
	return 0;
}
