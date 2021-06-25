#include <stdio.h>
#include <string.h>


void swap(char *s1,char *s2)
{
	char tmp[23];
	strcpy(tmp,s1);
	strcpy(s1,s2);
	strcpy(s2,tmp);
}
int main()
{
	char s1[23] = "String1";
	char s2[23] = "string2";
	
	swap(s1,s2);
	printf("%s %s\n",s1,s2);
	
}