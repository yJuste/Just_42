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

#define N 9 // Taille de la grille 9x9

// Fonction pour afficher la grille
void afficherGrille(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
	    printf("%d ", grid[i][j]);
	}
	printf("\n");
    }
    printf("-------------------------------\n"); // Séparateur entre les grilles
}

// Fonction pour vérifier s'il est sûr de placer un nombre dans une cellule
int estValide(int grid[N][N], int row, int col, int num) {
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
void remplirGrille(int grid[N][N], int row, int col, int* count) {
    // Si nous atteignons la fin de la grille, une solution est trouvée
    if (row == N - 1 && col == N) {
	(*count)++;  // Incrémenter le compteur de solutions
	printf("Solution #%d:\n", *count);
	afficherGrille(grid); // Afficher la grille
	return;
    }

    // Passer à la ligne suivante si nous atteignons la fin d'une ligne
    if (col == N) {
	row++;
	col = 0;
    }

    // Essayer de placer les chiffres de 1 à 9 dans la cellule
    for (int num = 1; num <= 9; num++) {
	if (estValide(grid, row, col, num)) {
	    grid[row][col] = num; // Placer le chiffre

	    // Passer à la cellule suivante
	    remplirGrille(grid, row, col + 1, count);

	    // Retirer le chiffre après avoir testé la solution
	    grid[row][col] = 0;
	}
    }
}

// Fonction principale pour générer et afficher toutes les grilles
void genererToutesLesGrilles() {
    int grid[N][N] = {0}; // Initialiser une grille vide
    int count = 0;        // Compteur de solutions

    // Appel de la fonction récursive pour remplir la grille
    remplirGrille(grid, 0, 0, &count);

    // Afficher le nombre total de solutions
    printf("Nombre total de solutions: %d\n", count);
}

int main() {
    genererToutesLesGrilles();
    return 0;
}
