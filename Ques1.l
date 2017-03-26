%{#include<stdio.h>
int vow_count=0;
int const_count =0;
int val=0;
int val2=0;
%}

%%
[aeiouAEIOU] {vow_count++;} 
[a-zA-Z] {const_count++;} 
[0-9] {val++;}
. {val2++;}
%% 
int main() 
{ 
	printf("Enter the string of vowels and consonents: ");
	yylex();
	if(val==0){
		printf("The number of vowels are:  %d\n",vow_count); 
		printf("The number of consonants are:  %d\n",const_count);
	} 
	else{
		/*[aeiouAEIOU] {vow_count++;} 
		[a-zA-Z] {const_count++;} 
		[0-9] {val++;}*/
	}
	printf("%d\n",val2);
	return 0; 
}
int yywrap() { return 1; } 
