#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char buff[3][150] = {0};
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
				int dedupe = 0;
				for (int j = 0; j < 8; j++) {
					char num[6] = {0};
					if (row < 1 && j < 3) break; // top face
					if (row > 1 && j > 4) break; // bottom face
					if (i < 1 && (j == 0 || j == 3 || j == 5)) break; // left face
					if (i > 139 && (j == 2 || j == 4 || j == 7)) break; // right face

					switch (buff[row + where[j][0]][i + where[j][1]]) {
					case '0'...'9':
						for (int k = 1; k < 4; k++) { // invert for. l for possibly redundant?
							int offset = i + where[j][1] - k;

							switch (buff[row + where[j][0]][offset]) {
							case '0'...'9':
								break;
							default:
								for (int l = 1; l < 4; l++) {
									num[l - 1] = buff[row + where[j][0]][offset + l];
								}
								goto break3;
							}
						}
					}
					break3:
					int temp = atoi(num);
					if (temp != dedupe) sum += temp;
					dedupe = temp;
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
