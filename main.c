#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Plokstuma
{
    int x;
    int y;

};

int eiluciuKiekis(char *filename);
void uzpildymas(char *filename,struct Plokstuma *masyvas,int eilutes);
void staciakampiai(struct Plokstuma *masyvas, int eilutes);

int main()
{
    char filename[255];
    scanf("%s",filename);
    struct Plokstuma *masyvas;
    int eilutes=eiluciuKiekis(filename);;
    masyvas=malloc(eilutes*sizeof(struct Plokstuma));
    if(masyvas!=NULL)
    {
        uzpildymas(filename,masyvas,eilutes);
        free(masyvas);
    }
    else
    {
        printf("Nepavyko alokuoti atminties");
    }

   // int *count;
    staciakampiai(masyvas,eilutes);

    return 0;
}
int eiluciuKiekis(char *filename)
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
    return count+1;
}

void uzpildymas(char *filename,struct Plokstuma *masyvas,int eilutes)
{
    FILE *fp=fopen(filename,"r");
    if(fp!=NULL)
    {
        for(int i=0; i<eilutes;i++)
        {
           fscanf(fp,"%d %d",&masyvas[i].x,&masyvas[i].y);

           printf("%4d %4d\n",masyvas[i].x,masyvas[i].y);
           
        }
        
    }
    
    else 
    {
        printf("nepavyko atidaryti failo");
    }
    fclose(fp);
}

void staciakampiai(struct Plokstuma *masyvas, int eilutes)
{
printf("kitoje funkcijoje : \n");
    for(int i=0;i<eilutes;i++)
    {
       printf("%4d %4d\n",masyvas[i].x,masyvas[i].y);

    }
            
}

    
