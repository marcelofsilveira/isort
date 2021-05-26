/* Arquivo isort.c */
/* Layout modificado manualmente para melhorar a legibilidade */

#define MAX 1000

#include <stdio.h>

void isort (int a[], int l, int r)
{
   int i;
   for (i = l+1; i <= r; i++) {
      int j = i, v = a[i];
      while (j > l && v < a[j-1]) {
         a[j] = a[j-1];
         j--;
      }
      a[j] = v;
   }
}

void main (int numargs, char *arg[])
{
   FILE *arq;
   int n, a[MAX+1];
   int i;
   if (numargs != 3) {
      fprintf(stderr, "\nUso: isort <nomearq1> <nomearq2>");
      fprintf(stderr, "\n     <nomearq1> é o nome do arquivo de dados");
      fprintf(stderr, "\n     <nomearq2> é o nome do arquivo de resultados\n");
      return;
   }
   arq = fopen(arg[1], "r");
   if (arq == NULL) {
      fprintf(stderr, "\nNão encontrei arquivo %s\n", arg[1]);
      return;
   }
   n = 0;
   while (fscanf(arq, "%d", &a[n]) == 1) {
      ++n;
      if (n > MAX) {
         fprintf(stderr, "\nNão sei lidar com mais que %d números\n", MAX);
         return;
      }
   };
   fclose(arq);
   isort(a, 0, n-1);
   arq = fopen(arg[2], "w");
   if (arq == NULL) {
      fprintf(stderr, "\nSocorro! Não consigo abrir arquivo %s\n", arg[2]);
      return;
   }
   for (i = 0; i < n; ++i)
      fprintf(arq, "%d\n", a[i]);
   fclose(arq);
}

