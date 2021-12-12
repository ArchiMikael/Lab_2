#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void BubbleSort(float *mas, int size)
{
  long int i = 0, j = 0;
  char noSwap = 1;
  float temp = 0.0;
  for (i = size - 1; i >= 0; i--)
  {
    noSwap = 1;
    for (j = 0; j < i; j++)
    {
      if (mas[j] > mas[j + 1])
      {
        temp = mas[j];
        mas[j] = mas[j + 1];
        mas[j + 1] = temp;
        noSwap = 0;
      }
    }
    if (noSwap == 1)
      break;
  }
}

void InsertSort(float *mas, int size)
{
  long int i = 0, loc = 0;
  float temp = 0.0;
  for (i = 1; i < size; i++)
  {
    temp = mas[i];
    loc = i - 1;
    while(loc >= 0 && mas[loc] > temp)
    {
      mas[loc + 1] = mas[loc];
      loc--;
    }
    mas[loc + 1] = temp;
  }
}

void QuickSort(float *mas, int size)
{
  int i = 0, j = size - 1;
  float mid = mas[(int)(size / 2)];
  float temp = 0.0;
  do {
    while(mas[i] < mid)
    {
      i++;
    }
    while(mas[j] > mid)
    {
      j--;
    }
    if (i <= j)
    {
      temp = mas[i];
      mas[i] = mas[j];
      mas[j] = temp;
      i++;
      j--;
    }
  } while (i <= j);
  if(j > 0) {
    QuickSort(mas, j + 1);
  }
  if (i < size) {
    QuickSort(&mas[i], size - i);
  }
}

int main()
{
  long int n = 0, i = 0, j = 0, loc = 0, comm = 0;
  float mx = 0.0, mn = 0.0, temp = 0.0;
  float readn = 0.0;
  float* mas;
  float* masC;
  FILE *file = NULL;
  clock_t t_start;
  clock_t t_end;
  file = fopen("output_1.txt", "r");
  if (file == NULL)
  {
    printf("No file named 'output_1.txt' found. Press any key to exit.");
    getch();
    return 0;
  }
  fscanf(file, "%d", &n);
  mas = (float*)malloc(n * sizeof(float));
  masC = (float*)malloc(n * sizeof(float));
  for (i = 0; i < n; i++)
  {
    fscanf(file, "%f", &readn);
    mas[i] = readn;
    masC[i] = readn;
  }
  fclose(file);
  while (comm != 3)
  {
    printf("Select command:\n1 - Print numbers\n2 - Sort numbers\n3 - Exit\n");
    scanf("%d", &comm);
    switch(comm)
    {
      case 1:
        {
          for (i = 0; i < n; i++)
          {
            printf("%lf\n", masC[i]);
          }
          printf("\n");
          break;
        }
      case 2:
        {
          t_start = clock();
          BubbleSort(masC, n);
          t_end = clock();
          file = fopen("output_2_1.txt", "w");
          for (i = 0; i < n; i++)
          {
            fprintf(file, "%lf\n", masC[i]);
            masC[i] = mas[i];
          }
          fclose(file);
          printf("Bubble sort time: %lf seconds.\n", (float)((t_end - t_start) / CLOCKS_PER_SEC));
          t_start = clock();
          InsertSort(masC, n);
          t_end = clock();
          file = fopen("output_2_2.txt", "w");
          for (i = 0; i < n; i++)
          {
            fprintf(file, "%lf\n", masC[i]);
            masC[i] = mas[i];
          }
          fclose(file);
          printf("Insert sort time: %lf seconds.\n", (float)((t_end - t_start) / CLOCKS_PER_SEC));
          t_start = clock();
          QuickSort(masC, n);
          t_end = clock();
          file = fopen("output_2_3.txt", "w");
          for (i = 0; i < n; i++)
          {
            fprintf(file, "%lf\n", masC[i]);
            masC[i] = mas[i];
          }
          fclose(file);
          printf("Quick sort time: %lf seconds.\n", (float)((t_end - t_start) / CLOCKS_PER_SEC));
          printf("Results of sorts saved into files 'output_2_1.txt', 'output_2_2.txt', 'output_2_3.txt'.\n\n");
          break;
        }
      default:
        break;
    }
  }
  free(mas);
  free(masC);
  return 0;
}