#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

int strok(char *arr, char *str);

int main(int argc, char **argv) {
	FILE *file;
       	char *str = argv[1];
	char arr[N];
	for(int i = 2; i < argc; i++) {
		file = fopen(argv[i], "r");
		while (fgets(arr, N, file) != NULL) {
			if ((strok (arr, str)) == 1) printf("%s: %s", argv[i], arr);
		}
	}
	fclose(file);

	return 0;
}

int strok(char *arr, char *str) {
	int i, j = 0;

	for(i = 0; arr[j] != '\0'; i++) {
		if (str[i] == '\0') return 1;
		if (str[i] == arr[j+i]) continue;
		else i = 0;
		
		for(; arr[j] != '\0'; j++) {
			if (str[i] == arr[j+1]) {
				j++;
				break;
			}
		}
	}
	return -1;
}
