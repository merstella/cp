#include <stdio.h>
#include <ctype.h>
int main() {
	char str[100] = "Hello world";
	char* p = str;
	printf("%s", p + 6);
}