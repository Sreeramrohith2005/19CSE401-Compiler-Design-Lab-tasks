#include <stdio.h>
#include <string.h>

char *T[5][6]={{"tb","","","tb","",""},{"","+tb","","","n","n"},{"fc","","","fc","",""},{"","n","*fc","n","n","n"},{"i","","","(e)","",""}};
int R(char x){return x=='e'?0:x=='b'?1:x=='t'?2:x=='c'?3:x=='f'?4:-1;}
int C(char x){return x=='i'?0:x=='+'?1:x=='*'?2:x=='('?3:x==')'?4:x=='$'?5:-1;}

int main(){
  char in[50],st[50];int top=1,pos=0;
  scanf("%s",in);strcat(in,"$");st[0]='$';st[1]='e';
  while(st[top]!='$'||in[pos]!='$'){
    if(st[top]==in[pos]){top--;pos++;}
    else{
      int r=R(st[top]),c=C(in[pos]);if(r<0||c<0||!*T[r][c])return puts("ERROR"),0;
      if(T[r][c][0]=='n')top--;else{top--;for(int i=strlen(T[r][c])-1;i>=0;i--)st[++top]=T[r][c][i];}
    }
  }
  puts("SUCCESS");
}
