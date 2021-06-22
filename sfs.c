#include <stdio.h>
#include "stdlib.h"
#include <string.h>

int main(int argc, char **argv) {
	FILE *file;
	char arr[50]; 
	for (int i = 2; i < argc; i++) {
		file = fopen(argv[i], "r");
		while (fgets(arr, 50, file) != NULL) {
			if ((strstr (arr, argv[1])) != NULL) printf("%s: %s", argv[i], arr);
		}
	}
	fclose(file);
	return 0;
}
