#include <math.h>
#include <stdio.h>
#define SIZE 4

// Function Declarations
void input(int [], int *, int *, int *, int *);
void playerFix(float [], int, int, int, int);
void PPM(float [], int[], float[]);

// MAIN
int main(void)

{

  // Local Declarations
  float points[SIZE];
  int matches[SIZE];
  float ppm[SIZE];
  int noPlayers = 0;
  int winner1 = 0;
  int winner2 = 0;
  int winner3 = 0;
  int i;
  FILE* inputF;
  FILE* outputF;
  FILE* output2;
  FILE* inputM;
  FILE* output3;
  FILE* outputP;

  inputF = fopen("score.txt", "r");
  outputF = fopen("currentScore.txt", "w");
  inputM = fopen("matches.txt", "r");

  fscanf(inputF, "%f\t%f\t%f\t%f", &points[0], &points[1], &points[2], &points[3]);
  fscanf(inputM, "%d\t%d\t%d\t%d", &matches[0], &matches[1], &matches[2], &matches[3]);
  input(matches, &noPlayers, &winner1, &winner2, &winner3);
  playerFix(points, noPlayers, winner1, winner2, winner3);
  PPM(points, matches, ppm);

  fprintf(outputF, "SIDD\tANU\tAMIT\tSUHU\n");
  fprintf(outputF, "----------------------------\n");
  fprintf(outputF, "%.3f\t%.3f\t%.3f\t%.3f", ppm[0], ppm[1], ppm[2], ppm[3]);

  fclose(inputF);
  fclose(outputF);

  output2 = fopen("score.txt", "w");
  fprintf(output2, "%f\t%f\t%f\t%f", points[0], points[1], points[2], points[3]);
  fclose(output2);

  output3 = fopen("matches.txt", "w");
  fprintf(output3, "%d\t%d\t%d\t%d", matches[0], matches[1], matches[2], matches[3]);
  fclose(output3);

  outputP = fopen("ppm.txt", "w");
  fprintf(outputP, "%.3f\t%.3f\t%.3f\t%.3f", ppm[0], ppm[1], ppm[2], ppm[3]);
  fclose(outputP);

  printf("\n\nSIDD\tANU\tAMIT\tSUHU\n");
  printf("----------------------------\n");
  printf("%0.3f\t%0.3f\t%0.3f\t%0.3f\n\n", ppm[0], ppm[1], ppm[2], ppm[3]);

  return 0;

}
/************************************************************
*************************************************************
************************************************************/
void input(int data[], int *num, int *w1, int *w2, int *w3)

{

  int j;
  int p = 0;

  printf("How many people were playing? ");
  scanf("%d", num);

  if (*num < 4)
  {
    printf("\nWho all are playing?");
    printf("\n1. Sidd\n2. Anu\n3. Amit\n4. Suhu\nAnswer: ");
    switch (*num)
    {
      case 3:
            {
              for(j = 0; j < 3; j++)
              {
                scanf("%d", &p);
                data[p-1]++;
              }
              break;
            }
      case 2:
            {
              for(j = 0; j < 2; j++)
              {
                scanf("%d", &p);
                data[p-1]++;
              }
              break;
            }
    }
  }
  else
  {
    for (p = 0; p < SIZE; p++)
      data[p]++;
  }

  printf("\nWho won the match? ");
  printf("\n1. Sidd\n2. Anu\n3. Amit\n4. Suhu\nAnswer: ");
  scanf("%d", w1);

  if (*num == 3)
  {
    printf("\nWho came in second? ");
    printf("\n1. Sidd\n2. Anu\n3. Amit\n4. Suhu\nAnswer: ");
    scanf("%d", w2);
  }

  if (*num == 4)
  {
    printf("\nWho came in second? ");
    printf("\n1. Sidd\n2. Anu\n3. Amit\n4. Suhu\nAnswer: ");
    scanf("%d", w2);
    printf("\nWho came in third? ");
    printf("\n1. Sidd\n2. Anu\n3. Amit\n4. Suhu\nAnswer: ");
    scanf("%d", w3);
  }

  return;

}

/************************************************************
*************************************************************
************************************************************/
void playerFix(float data[], int num, int w1, int w2, int w3)

{
  switch (num)
  {
    case 2: data[w1 - 1] += 0.5;
            break;
    case 3:
          {
            data[w1 - 1] += 2 / 3;
            data[w2 - 1] += 1 / 3;
          }
          break;
    case 4:
          {
            data[w1 - 1] += 0.75;
            data[w2 - 1] += 0.5;
            data[w3 - 1] += 0.25;
          }
  }

  return;

}

/************************************************************
*************************************************************
************************************************************/
void PPM(float points[], int match[], float ppm[])

{

  int i;

  for (i = 0; i < SIZE; i++)
    ppm[i] = points[i] / match[i];

  return;

}
