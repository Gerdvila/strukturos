#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Plokstuma
{
    int x;
    int y;

};

int EiluciuKiekis(char *filename);
void Uzpildymas(char *filename,struct Plokstuma *masyvas,int eilutes);
void staciakampiai(struct Plokstuma *masyvas,int eilutes, int *count);
void Atlaisvinimas(struct Plokstuma *masyvas, int eilutes);
//void spausdinimas(struct Plokstuma *masyvas, int eilutes, int *count);

int main()
{
    char filename[255];
    scanf("%s",filename);
    struct Plokstuma *masyvas;
    int eilutes=EiluciuKiekis(filename);;
    masyvas=malloc(eilutes*sizeof(struct Plokstuma));
    int *count;
    int *plot;
    if(masyvas!=NULL)
    {
        Uzpildymas(filename,masyvas,eilutes);
        staciakampiai(masyvas,eilutes,count);
        printf("%d",*count);
    }
    else
    {
        printf("Nepavyko alokuoti atminties");
    }
    Atlaisvinimas(masyvas,eilutes);
   // int *count;
    

    return 0;
}
int EiluciuKiekis(char *filename)
{
    int ch, count = 0;
    FILE* fptr = fopen(filename, "r");

    if (fptr != NULL)
    {
        do
        {
            ch = fgetc(fptr);

            if(ch == '\n') count++;
        }
        while (ch != EOF);
    }
    fclose(fptr);
    return count;
}

void Uzpildymas(char *filename,struct Plokstuma *masyvas,int eilutes)
{
    FILE *fp=fopen(filename,"r");
    if(fp!=NULL)
    {
        for(int i=0; i<eilutes;i++)
        {
           fscanf(fp,"%d %d",&masyvas[i].x,&masyvas[i].y);
    
        }
        
    }
    
    else 
    {
        printf("nepavyko atidaryti failo");
    }
    fclose(fp);
}

void staciakampiai(struct Plokstuma *masyvas,int eilutes, int *count)
{
int kintamasis=0;
    for(int i=0;i<eilutes;i++)
    {
       for(int j=0+i;j<eilutes;j++) 
       {
            if(masyvas[i].x==masyvas[j].x && masyvas[i].y!=masyvas[j].y)
            {
                for(int k=0+j;k<eilutes;k++)
                {
                    for(int h=0+k;h<eilutes;h++)
                    {
                    if(masyvas[k].x==masyvas[h].x && masyvas[k].x!=masyvas[i].x)
                        {
                            if(masyvas[k].y==masyvas[i].y && masyvas[h].y==masyvas[j].y ||masyvas[h].y==masyvas[i].y && masyvas[k].y==masyvas[j].y )
                            {
                            
                                kintamasis++;
                                
                            }
                        }
                    else continue;
                    }
                }
            }

        }        
    }

*count=kintamasis;
}

void Atlaisvinimas(struct Plokstuma *masyvas, int eilutes)
{
    for(int i=0;i<eilutes;i++)
    {
            free(masyvas+i);
            
    }
}
