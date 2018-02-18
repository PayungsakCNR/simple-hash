#include <string.h>
#include <ctype.h>
#include <stdio.h>

int c_to_n(char c);
char n_to_c(int num);
int simple_hash(char cc[]);

int main(int argc, char const *argv[])
{
	char str[100];

	printf("Enter String:");
	scanf("%s",str);

	printf("Hash = %c\n",n_to_c(simple_hash(str)));
	return 0;
}
int simple_hash(char cc[]){
	int md=0,i,temp;
	for(i=0; i<(strlen(cc)); i++){
		temp = c_to_n(cc[i]);
		printf("%c -> (%d + %d)mod26",cc[i],temp,md);
		md = (temp+md)%26;
		printf(" = %d\n",md);
	}
	return md;
}
int c_to_n(char c)
{
    int n = -1;
    static const char * const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *p = strchr(alphabet, toupper((unsigned char)c));

    if (p)
    {
        n = p - alphabet;
    }

    return n;
}
char n_to_c(int num){
	int i;
	static const char * const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(i=0; i<26; i++){
		if(i == num){
			return alphabet[i];
		}
	}
	return 0;
}
