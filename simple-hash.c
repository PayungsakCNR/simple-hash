/* Simple-Hash program 
	by PaOv6,CoE-PSU
	for Computer Security course.
	activity: HASH function.
*/
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int c_to_n(char c);
char n_to_c(int num);
int simple_hash(char cc[]);
void upper_string(char s[]);

int main(int argc, char const *argv[]) {
	char str_first_name[100], str_last_name[100];

	printf("Enter First name:");
	scanf("%s",str_first_name);

	printf("Enter Last name:");
	scanf("%s",str_last_name);

	printf("FIRST NAME\n");
	upper_string(str_first_name);
	printf("Hash = %c\n\n",n_to_c(simple_hash(str_first_name)));

	printf("LAST NAME\n");
	upper_string(str_last_name);
	printf("Hash = %c\n\n",n_to_c(simple_hash(str_last_name)));
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
/* alphabet to number */
int c_to_n(char c) {
    int n = -1;
    static const char * const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *p = strchr(alphabet, toupper((unsigned char)c));

    if (p){
        n = p - alphabet;
    }

    return n;
}
/* number to alphabet  */
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
/* chang input to upper string if lower */
void upper_string(char s[]) {
   int c = 0;
 
   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
}
