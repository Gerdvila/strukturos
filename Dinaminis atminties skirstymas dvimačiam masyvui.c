#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void uzpildyk(int N, int **mas)
{
  int i, j, sk, *eil;

  for (i = 0; i < N; i++, mas++)
  {
      sk = rand() % 5;
      eil = (int*) malloc((sk + 1) * sizeof(int));
      *mas = eil;
      *eil = sk;
      eil++;
      for (j = 0; j < sk; j++, eil++)
      {
        *eil = rand() % 10;
      }
  }
}

void spausdink(int N, int **mas)
{
  int i, j, sk, *eil;
  for (i = 0; i < N; i++, mas++)
  {
      eil = *mas;
      sk = *eil;
      eil++;
      for (j = 0; j < sk; j++, eil++)
      {
        printf("%3d", *eil);
      }
      printf("\n");
  }
}

void atlaisvink(int N, int **mas)
{
  int i, *eil;
  for (i = 0; i < N; i++, mas++)
  {
    eil = *mas;
    free(eil);
  }
}

int main()
{
    int **mas, N;
    srand(0);
    printf("Kiek eiluciu bus masyve? ");
    scanf("%d", &N);
    //mas = (int**) malloc(N * sizeof(int *));
    mas = (int**) calloc(N, sizeof(int *));
    if (mas != NULL)
    {
      uzpildyk(N, mas);
      spausdink(N, mas);
      atlaisvink(N, mas);
    }
    else
    {
      printf("Nepavyko isskirti atminties");
    }
    free(mas);

    return 0;
}


