#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char line[256];
	char *token1, *token2, *token3;
	char *chdup;	
	FILE *fp;
	fp = fopen("idmapping.dat", "r");
	
	if( fp == NULL )
		{
			perror("Error while opening the file.\n");
			exit(EXIT_FAILURE);
		}
	
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		token1 = strtok(line, "\t");
		token2 = strtok(NULL, "\t");
		token3 = strtok(NULL, "\t");
		printf("%s\t%s\t%s", token1, token2, token3);
	}

	fclose(fp);
	return 0;
}
