#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

int ft_check_doublon(int argc, int *argv)
{
    int     i;
    int     j;
    
    i = 1;
    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (argv[i] == argv[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

// Fonction pour vérifier si un nombre existe déjà dans le tableau
int is_duplicate(int number, int random_numbers[], int size) {
    for (int i = 0; i < size; i++) {
        if (random_numbers[i] == number) {
            return 1; // Le nombre est un doublon
        }
    }
    return 0; // Le nombre n'est pas un doublon
}

int main() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Taille de la liste à générer
    int n = 500; // Taille de la liste (par exemple 100)
    int random_numbers[n];
    int count = 0;

    // Générer la liste sans doublon
    while (count < n) {
        int num = rand() % 2000 - 1000; // Nombres entre 1 et 1000

        // Vérifier si le nombre est déjà présent dans la liste
        if (!is_duplicate(num, random_numbers, count)) {
            random_numbers[count] = num;
            count++;
        }
    }
	if (ft_check_doublon(n, random_numbers) == 0)
		printf("doublon!!!\n\n");
	else 
		printf("valid\n\n");
    // Affichage des nombres générés
    printf("Liste des nombres aléatoires sans doublon :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", random_numbers[i]);
    }
    printf("\n");

    return 0;
}
