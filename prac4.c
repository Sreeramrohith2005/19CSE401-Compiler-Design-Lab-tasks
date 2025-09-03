#include <stdio.h>
#include <string.h>

int main(void){
char input[50], left[20], right1[20], right2[20];
printf("Enter the Production Value: ");
fgets(input, sizeof(input), stdin);
input[strcspn(input,"\n")] = "\0";

sscanf(input,"%[^-] -> %[^|]|%s",left,right1,right2);

if(right1[0] == left[0]){
printf("After removing left recursion");
printf("%s -> %s%s'\n",left,right2,left);
printf("%s'-> %s%s | e\n",left,right1+1,left);
}
else{
int i=0;
while(right1[i] && right2[1]&&right1[i] == right2[i]) i++;
if(i>0){

}
}
}
