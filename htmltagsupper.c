#include <stdio.h>
#include <stdbool.h>
#define MAX_LINES 300
#define MAX_LEN 1000

int main(int argc,char *argv[])
{
FILE *file;
FILE *copy;
char data[MAX_LINES][MAX_LEN];
int i;
int j;
bool flag=0;
bool flag2=0;
int line=0;
    if(argc!=3)
    {
      printf("Inserire almeno 3 argomenti\nES: ./main.exe index.html copia.html");
      return 1;
    }
    file=fopen(argv[1],"r");
    copy=fopen(argv[2],"a");

    if(file==NULL || copy==NULL)
    {
      printf("Errore apertura file");
      return 1;
    }
  while (!feof(file) && !ferror(file))
    if (fgets(data[line], MAX_LEN, file) != NULL)
      line++;

  fclose(file);

    for(i=0;i<line;i++)
        for(j=0;j<MAX_LEN;j++)
        {
          if(data[i][j]=='<')
            flag=1;
          else if(data[i][j]=='"' && flag2==0)
            flag2=1;
          else if(data[i][j]=='"' && flag2==1)
            flag2=0;

          if(data[i][j]!='\0' && flag==1 && flag2==0)
          { 
            if(data[i][j]>='a' && data[i][j]<='z')
              data[i][j]=data[i][j]-32;
            
            if(data[i][j]=='>')
              flag=0;
          }
          if(data[i][j]>0 && data[i][j]<255)
            putc(data[i][j],copy);
        }

  /*for (i=0;i<line;i++)
    printf("%s",data[i]);*/

  fclose(file);
  fclose(copy);

  return 0;
}