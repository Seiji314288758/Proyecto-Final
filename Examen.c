/*Victor Seiji Nieto Morita
Examen */

#include <stdio.h>
#include <stdlib.h>

#define MAX_OYENTES 100
#define NUM_CANCIONES 10

int main ()
{
  int votos[MAX_OYENTES][3];
  int puntos_canciones[NUM_CANCIONES] = {0};
  int puntos_oyentes[MAX_OYENTES] = {0};
  int num_oyentes = 0;
  int i, j;

  printf("=== CONCURSO DE LA RADIO ===\n\n");

  printf("1. INGRESO DE VOTOS:\n");
  printf("Ingrese los tres votos (formato: cancion1 cancion2 cancion3)\n");
  printf("Para terminar, ingrese -1 como primer valor\n\n");

  for (i = 0; i < MAX_OYENTES; i++)
    {
     printf("Oyente %d: ", i);
     scanf("%d", &votos[i][0]);

     if (votos[i][0] == -1)
      {
       break;
      }

     scanf("%d %d", &votos[i][1], &votos[i][2]);

     int voto_valido = 1;
     for (j = 0; j < 3; j++)
       {
         if (votos[i][j] < 0 || votos[i][j] > 9)
          {
           printf("Error: Los votos deben estar entre 0 y 9. Reingrese.\n");
           i--;
           voto_valido = 0;
           break;
          }
       }
     if (voto_valido)
      {
       num_oyentes++;
      }
    }
    printf("\nTotal de oyentes: %d\n\n", num_oyentes);

    printf("2. CLACULO DE VOTOS:\n");

    for (i = 0; i < num_oyentes; i++)
    {
     puntos_canciones[votos[i][0]] += 3;
     puntos_canciones[votos[i][1]] += 2;
     puntos_canciones[votos[i][2]] += 1;
    }

    for (i = 0; i < NUM_CANCIONES; i++)
      {
       printf("Cancion %d: %d votos\n", i, puntos_canciones[i]);
      }

    int primera_cancion = -1, segunda_cancion = -1;
    int max_puntos1 = -1, max_puntos2 = -1;

    for (i = 0; i < NUM_CANCIONES; i++)
      {
       if (puntos_canciones[i] > max_puntos1)
        {
         max_puntos2 = max_puntos1;
         segunda_cancion = primera_cancion;
         max_puntos1 = puntos_canciones[i];
         primera_cancion = i;
        }
       else if (puntos_canciones[i] > max_puntos2)
          {
           max_puntos2 = puntos_canciones[i];
           segunda_cancion = i;
          }
      }

      printf("\n1a cancion: %d (%d puntos)\n", primera_cancion, max_puntos1);
      printf("2a cancion: %d (%d puntos)\n\n", segunda_cancion, max_puntos2);

      printf("3. CALCULO DE PUNTOS DE LOS OYENTES:\n");

      i = 0;
      while (i < num_oyentes)
          {
           int tiene_primera = 0;
           int tiene_segunda = 0;

           j = 0;
           do
            {
             if (votos[i][j] == primera_cancion)
              {
               tiene_primera = 1;
              } 
             if (votos[i][j] == segunda_cancion)
              {
               tiene_segunda = 1;
              }
              j++;
            }
            while (j < 3);

            if (tiene_primera)
             {
              puntos_oyentes[i] += 30;
             }
            if (tiene_segunda)
             {
              puntos_oyentes[i] += 20;
             }
            if (tiene_primera && tiene_segunda)
             {
              puntos_oyentes[i] += 10;
             }

            printf("Oyente %d: %d puntos\n", i, puntos_oyentes[i]);
            i++;
          }

         int oyente_ganador = -1;
         int max_puntos_oyente = -1;

         for (i = 0; i < num_oyentes; i++)
           {
            if (puntos_oyentes[i] > max_puntos_oyente)
             {
              max_puntos_oyente = puntos_oyentes[i];
              oyente_ganador = i;
             }
           }

         printf("\n=== RESULTADO FINAL ===\n");
         printf("GANADOR: el oyente numero %d con %d puntos\n", oyente_ganador, max_puntos_oyente);

         if (oyente_ganador != -1)
          {
           printf("\nDetalles del ganador:\n");
           printf("Oyente %d voto por: %d (1ro), %d (2do), %d (3ro)\n", oyente_ganador, votos[oyente_ganador][0], votos[oyente_ganador][1], votos[oyente_ganador][2]);
          }
   return 0;
}
