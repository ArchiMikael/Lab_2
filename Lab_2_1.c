#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
  long int n = 0, i = 0;
  float mx = 0.0, mn = 0.0, randn = 0.0;
  FILE *file = NULL;
  file = fopen("output_1.txt", "w");
  if (file == NULL)
  {
    printf("Error while opening file 'output_1.txt'. Press any key and Enter to exit.");
    scanf("%d", &n);
    return 0;
  }
  printf("n=");
  scanf("%d", &n);
  if (n <= 0)
  {
    printf("Error: n must be greater than 0. Press any key and Enter to exit.");
    scanf("%d", &n);
    return 0;
  }
  printf("min=");
  scanf("%f", &mn);
  printf("max=");
  scanf("%f", &mx);
  if (mn > mx)
  {
    printf("Error: min > max. Press any key and Enter to exit.");
    scanf("%d", &n);
    return 0;
  }
  fprintf(file, "%d\n", n);
  for(i = 0; i < n; i++)
  {
    randn = (float)rand() / RAND_MAX * (mx - mn) + mn;
    fprintf(file, "%f\n", randn);
  }
  fclose(file);
  printf("Generation finished successfully. Press any key to exit.");
  getch();
}