#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char lookahead;  
int state=0;
char prehead;


char nexttoken() {
  char c;
  while (1) {
  c = getchar();
  if (c == ' ' || c == '\t' || c == '\n' || c == '\0') continue;
  return(c);
  }
}
/*
void recursion(char lookahead, int state)
{
  if(isdigit(lookahead)||isalpha(lookahead)>0) 
           {
            break;
           }
  
}
*/

void secede()
{
  lookahead=nexttoken();
   if(lookahead=='$')
           {
             printf("9");        
           }
  else if(isdigit(lookahead)||isalpha(lookahead)>0)
  {
      secede();
  }
  else 
  {
   invalid();
  }

}


void invalid()
{
  prehead=lookahead;
  lookahead=nexttoken();
   if(lookahead=='$')
           {
             printf(" invalid char %c ", prehead);        
           }
  else
  {
     if(isdigit(lookahead)||isalpha(lookahead)>0)
   {
     secede();
   }
   else
   {
     printf(" invalid char %c ", prehead);  
     invalid();
   }

  }
  
}


int main()
{
    while(lookahead!='$')
    {
          
        switch (state)
        {
        case 0: 
            lookahead = nexttoken();
           if(lookahead == ' ' || lookahead == '\t' || lookahead == '\n' || lookahead == '\0')
           {
               state=0;
               break;
           } 
           else if(lookahead=='f')
           {
                 state=1;
                 break;
           }
             else if(lookahead=='i')
           {
                 state=4;
                 break;
           }
           else if(isdigit(lookahead)>0)
           {
             invalid();
           }
           else
           {
              state=8;
              break;
           }

        case 1:
            lookahead=nexttoken();
          if(lookahead=='o')
           {
                 state=2;
                 break;
           }

           else 
           {
            state=8;
            break;
           }
        
        case 2:
        lookahead=nexttoken();
          if(lookahead=='r')
           {
             state=3;
             break;
           }
             else 
           {
            state=8;
            break;
           }
      
        case 3:
        lookahead=nexttoken();
          if(lookahead=='$')
           {
             printf("1 ");
            break;
           }
          else if(isdigit(lookahead)||isalpha(lookahead)>0)
          {
              state=8;
               break;
          }
          else
          {
            printf("1 ");
            invalid();
            break;
          }

          
       case 4:
        lookahead=nexttoken();
          if(lookahead=='f')
           {
            state=5;
             break;
           }
           else if(lookahead=='n')
           {
             state=6;
             break;
           }
           else
           {            
            state=10;
            break;
           }

        case 5:
        lookahead=nexttoken();
         if(lookahead=='$')
           {
             printf("2");
            break;
           }
          else if(isdigit(lookahead)||isalpha(lookahead)>0)
          {
              state=10;
               break;
          }
          else
          {
            printf("2 ");
            invalid();
            break;
          }

        case 6:
        lookahead=nexttoken();
           if(lookahead=='t')
           {
             state=7;
             break;
           }
          else 
           {
            state=10;
            break;
           }
      
       case 7:
        lookahead=nexttoken();
         if(lookahead=='$')
           {
             printf("3");
             break;
           }
          else if(isdigit(lookahead)||isalpha(lookahead)>0)
          {
              state=10;
               break;
          }
          else
          {
            printf("3 ");
            invalid();
            break;
          }
       case 8:
        secede();
        break;
      
       case 9:
        invalid();
          break;
       case 10:
        secede();
        break;
       case 11:
       invalid();
        break;

        default:
           printf("error");
           break;
        }
    }

    if (lookahead == '$')
        printf("\n");
    else
         printf("error\n");

  exit(0);
}