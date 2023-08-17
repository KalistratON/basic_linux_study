#include <unistd.h>
#include <stdio.h>
#include <string.h>

unsigned int countChildren(FILE* file, char* ppid, unsigned int *count)
{	
	printf("count : %d\n", *count);
	printf("current ppid : %s\n", ppid);

	char path [50];
	
	if(sprintf(path, "/proc/%s/task/%s/children", ppid, ppid) < 0) {
		printf("Error : sprintf");
		return -1;
        }

	if (file = fopen(path, "r"), !file) {
		printf("Error : file");
		return *count;
	}

	while(fscanf(file, "%s", ppid) != EOF) {
		printf("while : ppid : %s", ppid);
		countChildren(file, ppid, ++(*count));
	}

}

int main(int argc, char* argv[]) {
	
	unsigned int count = 0;
	char ppid[50];
	FILE* file;

	sscanf(argv[1], "%s", ppid);

	
	printf("%i", countChildren(file, ppid, &count));	
	return 0;
}
