#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 1000

int main()
{
FILE *file;
FILE *copy;
char data[MAX_LEN];
int i;
int j;
bool flag=0;
bool flag2=0;
char name[100];
char copyy[100];
      printf("Nome file da copiare: ");
      scanf("%100s",name);
      fflush(stdin);
      printf("Nome file copia: ");
      scanf("%100s",copyy);
      fflush(stdin);
      file=fopen(name,"r");
      copy=fopen(copyy,"a");     

    puts(name);
    puts(copyy);

    if(file==NULL)
    {
      printf("Errore apertura file %s\n",name);
      return 1;
    }
    else if(copy==NULL)
    {
      printf("Errore apertura file %s\n",name);
      return 1;
    }
  while (!feof(file) && !ferror(file))
    if (fgets(data, MAX_LEN, file) != NULL)
    {
      for(i=0;data[i]!='\0';i++)
        {
          if(data[i]=='<')
            flag=1;
          else if(data[i]=='"' && flag2==0)
            flag2=1;
          else if(data[i]=='"' && flag2==1)
            flag2=0;

          if(data[i]!='\0' && flag==1 && flag2==0)
          { 
            if(data[i]>='a' && data[i]<='z')
              data[i]=data[i]-32;
            
            if(data[i]=='>')
              flag=0;
          }
          
          if(data[i]>0 && data[i]<255)
            putc(data[i],copy);
        }
    }
  fclose(file);
  fclose(copy);

  return 0;
}
