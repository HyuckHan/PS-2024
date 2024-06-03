#include <stdio.h>


void makeCode(char code[], int dist){
	int i = 0;
	for(i=0; i<26; i++){
		code[i] = 'A' + (char)(i+dist);
		if(code[i] > 'Z')
			code[i] = code[i] - 26;
	}
}

void printCode(char code[]){
	int i = 0;
	for(i=0; i<26; i++)
		printf("%c", 'A' + (char)i);
	printf("\n");
	for(i=0; i<26; i++)
		printf("%c", code[i]);
	printf("\n");
}

/*void encode(char code[], char s[], char e[]){
}*/

int main(void)
{
	char code[26]; // code[0]부터 ‘A’의 암호화문자를 넣음
	int distance;
	char sentence[80], encodedSentence[80];

	printf("Enter a distance for encoding:");
	scanf("%d", &distance);

	makeCode(code, distance);
	printCode(code);
	/*
	fflush(stdin);
	printf("Enter a sentence to encode:");
	gets(sentence);
	printf("original sentence:\t");
	puts(sentence);*/
}
