#include <stdio.h>
struct Processsor
{
    int pros[20];
}sp[20];
int main()
{
   
   int spr,ispr,fltp[100],nfltp=0,np;
   scanf("%d\n",&np);
   scanf("%d %d",&spr,&ispr);
   printf("\tSource Processsor %d\n",spr);
   int i=0;
   while(1)
   {   if(i==np)
        break;
       printf("\tProcessor %d\n\tis faulty? \n\t0.NO\n\t1.YES\n\t",i);
       scanf("%d",&fltp[i]);
       if(fltp[i]==1)
       nfltp++;
       i++;
   }
   if(nfltp>((np-1)/3))
        printf("\tAgreement not possible");
    else
   {
       for(i=0;i<np;i++)
       {
           if(i==spr)
            continue;
           else
            {
                sp[i].pros[spr]=ispr;
                sp[i].pros[i]=0;
            }
       }
       for(i=0;i<np;i++)
       {
           if(i==spr)
           continue;
           else if(fltp[i]==0)
           {
               for(int j=0;j<np;j++)
                {
                    if(j==spr||j==i)
                        continue;
                    else 
                        {   
                            sp[j].pros[i]=ispr;
                        }
                }
           }
           else if(fltp[i]==1)
           {
               for(int j=0;j<np;j++)
                {
                    if(j==spr||j==i)
                        continue;
                    else
                    {
                        sp[j].pros[i]=rand()%2;
                    }
                }
           }
       }
       
   }
for(int i=0;i<np;i++)
{
    if(i==spr)
        continue;
    else
    {   printf("\nProcessor-%d\t",i);
        for(int j=0;j<np;j++)
        {       if(j==i)
                    continue;
                printf("%d\t",sp[i].pros[j]);
        }
    }
}
   
   

    return 0;
}