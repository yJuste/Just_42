/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

#define MAX_N 9 // Taille maximale de la grille

// Fonction pour afficher la grille
void afficherGrille(int grid[MAX_N][MAX_N], int N) {
    for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
	    printf("%d ", grid[i][j]);
	}
	printf("\n");
    }
    printf("-------------------------------\n"); // Séparateur entre les grilles
}

// Fonction pour vérifier s'il est sûr de placer un nombre dans une cellule
int estValide(int grid[MAX_N][MAX_N], int row, int col, int num, int N) {
    // Vérifier si le nombre est déjà présent dans la ligne
    for (int x = 0; x < N; x++) {
	if (grid[row][x] == num) {
	    return 0;
	}
    }

    // Vérifier si le nombre est déjà présent dans la colonne
    for (int x = 0; x < N; x++) {
	if (grid[x][col] == num) {
	    return 0;
	}
    }

    return 1; // Le nombre peut être placé dans la cellule
}

// Fonction récursive pour remplir la grille et afficher toutes les solutions
void remplirGrille(int grid[MAX_N][MAX_N], int row, int col, int* count, int N) {
    // Si nous atteignons la fin de la grille, une solution est trouvée
    if (row == N - 1 && col == N) {
	(*count)++;  // Incrémenter le compteur de solutions
	printf("Solution #%d:\n", *count);
	afficherGrille(grid, N); // Afficher la grille
	return;
    }

    // Passer à la ligne suivante si nous atteignons la fin d'une ligne
    if (col == N) {
	row++;
	col = 0;
    }

    // Essayer de placer les chiffres de 1 à N dans la cellule
    for (int num = 1; num <= N; num++) {
	if (estValide(grid, row, col, num, N)) {
	    grid[row][col] = num; // Placer le chiffre

	    // Passer à la cellule suivante
	    remplirGrille(grid, row, col + 1, count, N);

	    // Retirer le chiffre après avoir testé la solution
	    grid[row][col] = 0;
	}
    }
}

// Fonction principale pour générer et afficher toutes les grilles de taille NxN
void genererToutesLesGrilles(int N) {
    int grid[MAX_N][MAX_N] = {0}; // Initialiser une grille vide
    int count = 0;                // Compteur de solutions

    // Appel de la fonction récursive pour remplir la grille
    remplirGrille(grid, 0, 0, &count, N);

    // Afficher le nombre total de solutions
    printf("Nombre total de solutions pour une grille %dx%d: %d\n", N, N, count);
}

int main() {
    int N;

    // Demander à l'utilisateur la taille de la grille
    printf("Entrez la taille de la grille (entre 1 et 9): ");
    scanf("%d", &N);

    // Vérifier que la taille est valide
    if (N >= 1 && N <= 9) {
	genererToutesLesGrilles(N); // Générer les solutions pour une grille de taille NxN
    } else {
	printf("Taille invalide. Veuillez entrer un nombre entre 1 et 9.\n");
    }

    return 0;
}
