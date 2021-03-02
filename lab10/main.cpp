#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "struct_count.h"

int main () {
	FILE* f;
	char str[256];
	char* arr;
    int rem = 0, s_len = 0, f_len = 0;

    OPERATIONS op;

	f = fopen("C:/Users/USER/source/repos/lab5_realloc/lab5_realloc/main.c", "r");

	if (f == 0) {
		printf("Allocation error\n");
        return 1;
	}

	while (1) {
		arr = fgets(str, sizeof(str), f);
        s_len = strlen(str);
        f_len += s_len;

        if (arr == NULL) {
            if (feof(f) != 0) {
                break;
            }
            else {
                printf("Error\n");
                break;
            }
        }
        count(&op, str, &rem);
	}

    print_struct(&op, &f_len);

    fclose(f);

    return 0;
}
