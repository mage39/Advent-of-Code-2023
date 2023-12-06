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

	fgets(buff[0], 160, input);
	fgets(buff[1], 160, input);

	while(fgets(buff[2], 160, input)) {
		lines++;
		start:
		for (int i = 0; i < 160 && buff[row][i]; i++) {
			switch (buff[row][i]) {
			case '1'...'9': case '.':
				break;
			default:
				for (int j = 0; j < 8; j++) {
					char num[4] = {0};
					if (row < 1 && i < 1 && (j < 4 || j == 5)) break;
					if (row > 1 && i < 1 && (j == 0 || j == 3 || j > 4)) break;
					if (row < 1 && i > 138 && (j < 4 || j == 5)) break;
					if (row > 1 && i < 138 && (j == 0 || j == 3 || j > 4)) break;

					switch (buff[row + where[j][0]][i + where[j][1]]) {
					case '1'...'9':
						for (int k = 0; k < 3; k++) {
							switch (buff[row + where[j][0]][i + where[j][1] * k]) {
							case '1'...'9':
								break;
							default:
								for (int l = 0; l >= k; k++) {
									num[l] = buff[row + where[j][0]][i + where[j][1] * k + l];
								}
							}
						}
					}
					sum += atoi(num);
				}
			}
		}
		
		if (!row || lines > 139) {
			row++;
			goto start;
		} else {
			memcpy(buff[0], buff[1], 160);
			memcpy(buff[1], buff[0], 160);
		}
	}

	printf("%d", sum);
	fclose(input);
	return 0;
}
