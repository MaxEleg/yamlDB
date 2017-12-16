#include "../string.h";

char * readFile(char *dest) {
	FILE *fp;
	char *buff = (char*)malloc(sizeof(char) * 600);
	int i;

	i = 0;
	fp = fopen(dest, "r");


	while ((buff[i] = fgetc(fp)) != EOF) {
		i++;
	}
	buff[i + 1] = '\0';

	return buff;
}

char	**split(char *str, char separator)
{
	int	i;
	int	j;
	int	k;
	char **word;
	int length = my_strlen(str) +1;

	i = 0;
	j = 0;
	k = 0;
	word = (char**)malloc(sizeof(char*)*length);
	word[j] = (char*)malloc(sizeof(char)*length);
	initTab(word[j],length);
	while (str[i] != '\0')
	{
		if (str[i] != separator)
		{
			word[j][k] = str[i];
			k++;
		}
		else
		{
			word[j][k + 1] = '\0';
			j++;
			word[j] = (char*)malloc(sizeof(char)*length);
			initTab(word[j],length);
			k = 0;
		}
		i++;
	}
	word[j + 1] = '\0';
	return  word;
}

int my_strlen(char*s) {
	int i = 0;

	for (i = 0; s[i] != '\0'; i++) {
	}

	return i;
}


void initTab(char * tab,int count) {
	int i = 0;

	for (i = 0; i < count; i++) {
		tab[i] = '\0';
	}
}
