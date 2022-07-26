#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf

int main(int argc, char**argv) {
	uint32_t var1, var2;
	size_t result;
	char buf[4];

    if(argc != 3){
        printf("You should give 3 arguments.\n");
        exit(100);
    }

	FILE *file1, *file2;
    if(!(file1=fopen(argv[1], "r"))) {
        printf("Can't open the first file.\n");
        exit(101);
    }

    if(!(file2=fopen(argv[2], "r"))) {
        printf("Can't open the second file.\n");
        exit(101);
    }

	// result = fread(&var1, sizeof(var1), 1, file1);
	result = fread(buf, sizeof(buf), 1, file1);
	printf("%d\n", result);
	printf("%s\n", buf);
	if(result != sizeof(var1)) {
		printf("Can't read uint32_t integer.\n");
		exit(102);
	}

	result = fread(&var2, sizeof(var2), 1, file2);
	if(result != sizeof(var2)) {
		printf("Can't read uint32_t integer.\n");
		exit(102);
	}

	printf("%d %d\n", var1, var2);

    
}
