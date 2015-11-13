#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char line[256];
	char placeholdertoken[256];
	char *placeholderline;
	char *token1, *token2, *token3;
	char *chdup;
	char *tab, *newline, *semicolom, *empty;
	FILE *fp;
	FILE *fs;
	fp = fopen("idmapping.dat", "r");
	fs = fopen("parsedidmapping.dat", "w");

	if( fp == NULL )
		{
			perror("Error while opening the file.\n");
			exit(EXIT_FAILURE);
		}

	while (fgets(line, sizeof(line), fp) != NULL)
	{
        tab = "\t";
        newline = "\n";
        semicolom = ";";
        empty = "";
		token1 = strtok(line, "\t");
		token2 = strtok(NULL, "\t");
		token3 = strtok(NULL, "\n");
		//printf("%s\t%s\t%s", token1, token2, token3);
		if (strcmp(token1, placeholdertoken) == 0) {
            strcat(placeholderline, token2);
			strcat(placeholderline, semicolom);
			strcat(placeholderline, token3);
			strcat(placeholderline, tab);
			//printf("Token equal\n");
		}
		else {
            strcat(placeholderline, newline);
            //printf("Placeholdertoken != token\n%s\n", token1); //placeholdertoken);
            //printf("%s\n", placeholderline);
			strcpy(placeholdertoken,token1);
			//printf("%s", placeholderline);
			fputs(placeholderline, fs);
			*placeholderline = *empty;
			strcat(placeholderline, token1);
			strcat(placeholderline, tab);
			strcat(placeholderline, token2);
			strcat(placeholderline, semicolom);
			strcat(placeholderline, token3);
			strcat(placeholderline, tab);
		}
	}
	fclose(fs);
	fclose(fp);
	return 0;
}
