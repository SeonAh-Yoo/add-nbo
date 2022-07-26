#include <stddef.h> // for size_t
#include <stdint.h> // for uint32_t
#include <stdio.h> // for printf

uint32_t my_ntohl(uint32_t n){
    uint32_t n1 = (n & 0x000000ff) << 24;
    uint32_t n2 = (n & 0x0000ff00) << 8;
    uint32_t n3 = (n & 0x00ff0000) >> 8;
    uint32_t n4 = (n & 0xff000000) >> 24;
    return n1 | n2 | n3 | n4;
}

int main(int argc, char**argv) {
	uint32_t var1, var2, sum;
	size_t result;

    if(argc != 3){
        printf("You should give 3 arguments.\n");
        return 100;
    }

	FILE *file1, *file2;
    if(!(file1=fopen(argv[1], "r"))) {
        printf("Can't open the first file.\n");
        return 101;
    }

    if(!(file2=fopen(argv[2], "r"))) {
        printf("Can't open the second file.\n");
        return 101;
    }

	result = fread(&var1, sizeof(var1), 1, file1);
	if(result != 1) {
		printf("Can't read uint32_t integer.\n");
		return 102;
	}

	result = fread(&var2, sizeof(var2), 1, file2);
	if(result != 1) {
		printf("Can't read uint32_t integer.\n");
		return 102;
	}

	var1 = my_ntohl(var1);
	var2 = my_ntohl(var2);
	sum = var1 + var2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", var1, var1, var2, var2, sum, sum);

	return 0;
}

