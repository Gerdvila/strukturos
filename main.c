#include <stdio.h>
#include <stdlib.h>


struct Plokstuma
{
    int x;
    int y;

};

int EiluciuKiekis(char *filename);
void Uzpildymas(char *filename,struct Plokstuma *masyvas,int eilutes);
void staciakampiai(struct Plokstuma *masyvas,int eilutes, int *count);
void koordinaciuzpildymas(struct Plokstuma *masyvas,struct Plokstuma *koordinates,int eilutes);
void Atlaisvinimas(struct Plokstuma *masyvas, int eilutes,int *count,struct Plokstuma *koordinates,int *plot);




int main()
{
    char filename[255];
    scanf("%s",filename);
    struct Plokstuma *masyvas;
    struct Plokstuma *koordinates;
    int eilutes=EiluciuKiekis(filename);
    masyvas=malloc(eilutes*sizeof(struct Plokstuma));
    int *count;
    int *plot;
    
    if(masyvas!=NULL)
    {
        Uzpildymas(filename,masyvas,eilutes);
        staciakampiai(masyvas,eilutes,count);

        koordinates=malloc((3)*sizeof(struct Plokstuma));
        //plot=(int*)malloc((*count)*sizeof(int));
        if(koordinates!=NULL)
        {
            koordinaciuzpildymas(masyvas,koordinates,eilutes);
            for(int i=0;i<(*count)*4;i++)
            {
            printf("[%d][%d]\n",koordinates[i].x,koordinates[i].y);
            }
            Atlaisvinimas(masyvas,eilutes,count,koordinates,plot);
        }
        else{
            printf("nepavyko alokuoti atminties");
        }
        
    }
    else
    {
        printf("Nepavyko alokuoti atminties");
    }
    Atlaisvinimas(masyvas,eilutes,count,koordinates,plot);
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
void koordinaciuzpildymas(struct Plokstuma *masyvas,struct Plokstuma *koordinates,int eilutes)
{
int p=0;
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
                            koordinates[p].x=masyvas[i].x; 
                            koordinates[p].y=masyvas[i].y;
                            koordinates[p+1].x=masyvas[j].x; 
                            koordinates[p+1].y=masyvas[j].y;
                            koordinates[p+2].x=masyvas[h].x; 
                            koordinates[p+2].y=masyvas[h].y;
                            koordinates[p+3].x=masyvas[k].x; 
                            koordinates[p+3].y=masyvas[k].y;
                            p+=4;
                            }
                        }
                    else continue;
                    }
                }
            }

        }        
    }


}

void Atlaisvinimas(struct Plokstuma *masyvas, int eilutes, int *count,struct Plokstuma *koordinates, int *plot)
{
    for(int i=0;i<eilutes;i++)
    {
            free(masyvas+i);
            
    }
    for(int j=0; j<(*count);j++)
    {
        for(int k=0;k<4;k++)
        {
            free(koordinates+(k+(j*4)));
        }
            
    }
    for(int k=0;k<(*count);k++)
    {
        free(plot+k);
    }

}
