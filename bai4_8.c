#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	char* str;
	str = (char*) malloc(sizeof(char) * 100000000);

	scanf("%s", str);
	int n = strlen(str);
	for (int i = 0; i < n; ++i) {
		int ok = 0;
		while (str[i] == '#') {
			ok = 1;
			++i;
		}
		if (ok) i--;
		if (ok) printf("%c", '\n');
		else printf("%c", str[i]);
	}
	free(str);
	// printf("Hello World!");
	return 0;
}