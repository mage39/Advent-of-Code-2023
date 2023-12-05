#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *input = fopen("aoc1input.txt", "r");
	char buff[64] = {0};
	int sum = 0;

	if (!input) {
		fprintf(stderr, "wtf just occurred in front of my eyeballs\n");
		return -1;
	}

	while (fgets(buff, 63, input)) {
		char addnum[4] = {0};
		for (int i = 0; i < 64 && buff[i]; i++) {
			switch (buff[i]) {
				case '0'...'9':
					if (!addnum[0]) addnum[0] = buff[i];
					addnum[1] = buff[i];
					break;
				case 'o':
					if (!strncmp((buff + i), "one", 3)) {
						if (!addnum[0]) addnum[0] = '1';
						addnum[1] = '1';
					}
					break;
				case 't':
					if (!strncmp((buff + i), "two", 3)) {
						if (!addnum[0]) addnum[0] = '2';
						addnum[1] = '2';
					}
					else if (!strncmp((buff + i), "three", 5)) {
						if (!addnum[0]) addnum[0] = '3';
						addnum[1] = '3';
					}
					break;
				case 'f':
					if (!strncmp((buff + i), "four", 4)) {
						if (!addnum[0]) addnum[0] = '4';
						addnum[1] = '4';
					}
					else if (!strncmp((buff + i), "five", 4)) {
						if (!addnum[0]) addnum[0] = '5';
						addnum[1] = '5';
					}
					break;
				case 's':
					if (!strncmp((buff + i), "six", 3)) {
						if (!addnum[0]) addnum[0] = '6';
						addnum[1] = '6';
					}
					else if (!strncmp((buff + i), "seven", 5)) {
						if (!addnum[0]) addnum[0] = '7';
						addnum[1] = '7';
					}
					break;
				case 'e':
					if (!strncmp((buff + i), "eight", 5)) {
						if (!addnum[0]) addnum[0] = '8';
						addnum[1] = '8';
					}
					break;
				case 'n':
					if (!strncmp((buff + i), "nine", 4)) {
						if (!addnum[0]) addnum[0] = '9';
						addnum[1] = '9';
					}
					break;
			}
		}
		sum += atoi(addnum);
	}
	printf("%d\n", sum);

	fclose(input);
	return 0;
}
