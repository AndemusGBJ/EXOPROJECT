/* Programme permettant d'afficher alternativement les lignes lues dans deux fichiers diff�rents*/
#include <stdio.h>

 /* Cette fonction lit jusqu'� la fin la ligne en cours et l'affiche � l'�cran*/

 int affiche_ligne (FILE * in)
 {
     int c;
     while ((c = getc(in)) != EOF){
        putc(c, stdout);
        if (c== '\n')
            break;
     }
     return c != EOF;
 }

 /* Cette fonction lit les deux fichiers et affiche les lignes lues dans chacun*/

 void merge (char * src1, char * src2)
 {
     FILE * in1, *in2;
     int err1, err2;
     err1=0;
     err2=0;

     in1 = fopen(src1, "r");
     if (in1 == NULL)
     {
         fprintf(stderr, "impossible de lire le fichier %s\n", src2);
         err2=1;
     }
     while (!err1 || !err2)
     {
         if (!err1)
         {
             err1 = !affiche_ligne(in1);
         }
         if (!err2)
         {
             err2 = !affiche_ligne(in2);
         }
     }
     if (in1 != NULL)
        fclose(in1);
     if (in2 != NULL)
        fclose (in2);
 }

 /*Programme principale*/

 int main(void)
 {
     char src1[256], src2[256];
     printf("Entrer le nom du premier fichier : ");
     scanf("%256s", src1);
     printf("Entrer le nom du second fichier : ");
     scanf("%256s", src2);

     printf("\n");
     merge(src1,src2);

     return 0;
 }

