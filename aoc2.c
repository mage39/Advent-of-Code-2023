#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int red, green, blue;
} GAME;

int main() {
	FILE *input = fopen("aoc2input.txt", "r");
	char buff[192];
	int id = 1, sum = 0;

	if (!input) {
		printf("WTF");
		return -1;
	}

	while(fgets(buff, 192, input)) {
		GAME round = {0};
		char num[4] = {0};

		for (int i = 0; i < 192 && buff[i]; i++) {
			switch (buff[i]) {
				case ';': case '\n': case EOF:
				case ':':
					round.red = 0;
					round.green = 0;
					round.blue = 0;
				case ',': 
					num[0] = 0;
					num[1] = 0;
					break;
				case '0'...'9':
					if (!num[0]) num[0] = buff[i];
					else num[1] = buff[i];
					break;
				case 'r':
					if (!strncmp(buff + i, "red", strlen("red")))
						round.red += atoi(num);
					}
					break;
				case 'g':
					if (!strncmp(buff + i, "green", strlen("green"))) {
						round.green += atoi(num);
					}
					break;
				case 'b':
					if (!strncmp(buff + i, "blue", strlen("blue"))) {
						round.blue += atoi(num);
					}
					break;
			}
		}
		sum += id;
		RIP:
		id++;
	}

	printf("%d\n", sum);
	fclose(input);
	return 0;
}
