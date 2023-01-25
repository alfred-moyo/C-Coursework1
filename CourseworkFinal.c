#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int Random_Num_Generator (int Ran_Num, int Loop_funct);

void Chance_of_occurence (int g[], int numF, int b);

int Random_Num_Generator (int f, int Loop_funct)
{
int Random_Num;
 srand(time(NULL) + Loop_funct);
 Random_Num = 1 + (rand () % f);
 return Random_Num;
}

void Chance_of_occurence (int g[], int numF, int numT)
{
int chance[25] = {0};
int i, q;
for (i = 1; i <= numT; i++)
{
q =g[i];
chance[q]++;
}

for (i = 1; i <= numF; i++)
{
double y = (chance[i] * (1.0 / numT)) * 100;
printf ("Percentage of occurrence of %d is: %.2f%%\n", i, y);
}
}

int main()
{
unsigned int c;
do{

    int numF, numT, Loop_funct, Max_Attempts[500];
    printf("Enter number of faces:");
    scanf("%d", &numF);
    while (1 >= numF || numF >= 25){
    printf("OOps! Value must be between 1 and 25!\nEnter number of faces:");
    system("color 0c");
    scanf("%d", &numF);
    system("color 0f");
    }

    printf("Enter number of throws:");
    scanf("%d", &numT);
    while (1 >= numT || numT >= 500){
    printf("OOps! Value must be between 1 and 500!\nEnter number of throws:");
    system("color 0c");
    scanf("%d", &numT);
    system("color 0f");
    }
    printf("Generating Throws:\n");

    for (Loop_funct = 1; Loop_funct <= numT; Loop_funct++)
    {
    Max_Attempts[Loop_funct] =
    Random_Num_Generator (numF, Loop_funct);
    printf ("%d\n", Max_Attempts[Loop_funct]);
    }
    Chance_of_occurence (Max_Attempts, numF, numT);
    FILE * the_file = fopen("a_art.txt", "r");
if(the_file == NULL){
    perror("Unable to open the file");
    exit(1);
}
char line[100];
while(fgets(line, sizeof(line), the_file)){
    printf("%s",line);
}
    printf("\nEnter choice:\n");
    scanf("%u",&c);

    } while(c != 0);
        FILE * the_file = fopen("a_art2.txt", "r");
if(the_file == NULL){
    perror("Unable to open the file");
    exit(1);
}
char line[100];
while(fgets(line, sizeof(line), the_file)){
    printf("%s",line);
}

 return 0;
}
