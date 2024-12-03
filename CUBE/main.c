#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

float tableau[8][3] = {
	{-30, 30, 30},
	{30, 30, 30},
	{-30, -30, 30},
	{30, -30, 30},
	{-30, 30, -30},
	{30, 30, -30},
	{-30, -30, -30},
	{30, -30, -30}
};


float camera[3] = {0, 0, 70};
float FOV = 50;
float degre = 0.05;
float size = 0.8;
int decalage = 70;

char *ascii = "@&NM0KAUh6PkqwSE2]ayjx[IifFJ)vTz/*cr!+><;=^,:'-.` "; // 52 caracteres

float vabs(float n)
{
    if (n < 0)
        return -n;
    return n;
}

char	dist_to_ascii(float distance)
{
	int res = roundf(distance / 2);
	if (res >= 52)
	{
		res = 52;
	}
	
	return (ascii[res - 10]);
}

float dist_3d(float p1[3])
{
	int res = vabs(p1[2] - camera[2]);
	return (res);
}


char get_random_char()
{
    int random_char = rand() % (126 - 32 + 1) + 32;
    return (char)random_char;
}

char *creer_chaine(int lignes, int espaces_par_ligne) {
    // Calcul de la taille totale de la chaîne
    int taille_totale = lignes * (espaces_par_ligne + 1) + 1;

    // Allocation du buffer pour la chaîne
    char *chaine = (char *)malloc(taille_totale * sizeof(char));
    if (chaine == NULL) {
        printf("Erreur d'allocation de mémoire.\n");
        return NULL;
    }

    // Remplissage de la chaîne
    for (int i = 0; i < lignes; i++) {
        // Remplir 100 espaces puis un '\n'
        memset(chaine + i * (espaces_par_ligne + 1), ' ', espaces_par_ligne);
        chaine[i * (espaces_par_ligne + 1) + espaces_par_ligne] = '\n';
    }
    chaine[taille_totale - 1] = '\0';  // Ajouter le caractère de fin de chaîne

    return chaine;
}


void xyz_to_xy(float point[3], float res[2])
{
	res[0] = (point[1] * FOV) / vabs(camera[2] - point[2]);
	res[1] = (point[0] * FOV) / vabs(camera[2] - point[2]);
}

int xy_to_str(float x, float y)
{
	int resx = roundf(y) / 2;
	int resy = roundf(x);
	return (resx * 102 + resy);
}

void rotatey(float point[3])
{
	float x = (point[0] * cos(degre)) - (point[2] * sin(degre));
	float z = (point[0] * sin(degre)) + (point[2] * cos(degre));
	point[0] = x;
	point[2] = z;
}

void rotatex(float point[3])
{
	float x = (point[0] * cos(degre)) - (point[1] * sin(degre));
	float z = (point[0] * sin(degre)) + (point[1] * cos(degre));
	point[0] = x;
	point[1] = z;
}

void rotatez(float point[3])
{
	float x = (point[1] * cos(degre * 2)) - (point[2] * sin(degre * 2));
	float z = (point[1] * sin(degre * 2)) + (point[2] * cos(degre * 2));
	point[1] = x;
	point[2] = z;
}

int	get_ascii(int indexchar, char *str)
{
	char c = str[indexchar];
	int i = 0;
	while (ascii[i] != c)
	{
		i ++;
	}
	return i;
}

void drawline(float p1[2], float p2[2], char *str) {
    float dx = p2[0] - p1[0];
    float dy = p2[1] - p1[1];

    // Calcul du nombre d'itérations en fonction de la distance entre p1 et p2
    float distance = sqrt(dx * dx + dy * dy);
    int steps = (int)(distance * 10); // Precision au dixième

    // Itérer sur les points de la droite entre p1 et p2
    for (int i = 0; i <= steps; ++i) {
        // Calcul de l'interpolation pour x et y
        float t = i / (float)steps;
        float x = p1[0] + t * dx;
        float y = p1[1] + t * dy;

        // Affichage du point avec une précision au dixième près
        str[xy_to_str(x, y)] = get_random_char();
    }
}


void	strchange(char *str, char *str2)
{
	printf("\033[H\033[J");
	memcpy(str, str2, strlen(str2) + 1);

	float p01[2];
	float p02[2];
	float p03[2];
	float p04[2];
	float p11[2];
	float p12[2];
	float p13[2];
	float p14[2];

	xyz_to_xy(tableau[0], p01);
	xyz_to_xy(tableau[1], p02);
	xyz_to_xy(tableau[2], p03);
	xyz_to_xy(tableau[3], p04);
	xyz_to_xy(tableau[4], p11);
	xyz_to_xy(tableau[5], p12);
	xyz_to_xy(tableau[6], p13);
	xyz_to_xy(tableau[7], p14);

	p01[0] += decalage; p01[1] += decalage;
	p02[0] += decalage; p02[1] += decalage;
	p03[0] += decalage; p03[1] += decalage;
	p04[0] += decalage; p04[1] += decalage;
	p11[0] += decalage; p11[1] += decalage;
	p12[0] += decalage; p12[1] += decalage;
	p13[0] += decalage; p13[1] += decalage;
	p14[0] += decalage; p14[1] += decalage;

	p01[0] *= size; p01[1] *= size;
	p02[0] *= size; p02[1] *= size;
	p03[0] *= size; p03[1] *= size;
	p04[0] *= size; p04[1] *= size;
	p11[0] *= size; p11[1] *= size;
	p12[0] *= size; p12[1] *= size;
	p13[0] *= size; p13[1] *= size;
	p14[0] *= size; p14[1] *= size;

	str[xy_to_str(p01[0], p01[1])] = dist_to_ascii(dist_3d(tableau[0]));
	str[xy_to_str(p02[0], p02[1])] = dist_to_ascii(dist_3d(tableau[1]));
	str[xy_to_str(p03[0], p03[1])] = dist_to_ascii(dist_3d(tableau[2]));
	str[xy_to_str(p04[0], p04[1])] = dist_to_ascii(dist_3d(tableau[3]));
	str[xy_to_str(p11[0], p11[1])] = dist_to_ascii(dist_3d(tableau[4]));
	str[xy_to_str(p12[0], p12[1])] = dist_to_ascii(dist_3d(tableau[5]));
	str[xy_to_str(p13[0], p13[1])] = dist_to_ascii(dist_3d(tableau[6]));
	str[xy_to_str(p14[0], p14[1])] = dist_to_ascii(dist_3d(tableau[7]));
	
	rotatey(tableau[0]);
	rotatey(tableau[1]);
	rotatey(tableau[2]);
	rotatey(tableau[3]);
	rotatey(tableau[4]);
	rotatey(tableau[5]);
	rotatey(tableau[6]);
	rotatey(tableau[7]);

	rotatex(tableau[0]);
	rotatex(tableau[1]);
	rotatex(tableau[2]);
	rotatex(tableau[3]);
	rotatex(tableau[4]);
	rotatex(tableau[5]);
	rotatex(tableau[6]);
	rotatex(tableau[7]); 

	drawline(p01, p02, str);
	drawline(p03, p04, str);
	drawline(p01, p03, str);
	drawline(p02, p04, str);

	drawline(p11, p12, str);
	drawline(p13, p14, str);
	drawline(p11, p13, str);
	drawline(p12, p14, str);

	drawline(p01, p11, str);
	drawline(p02, p12, str);
	drawline(p03, p13, str);
	drawline(p04, p14, str);


	printf("%s", str);

    int console_width = 80;

	for (int i = 0; i < 8; i++) {
		// Utiliser les bonnes projections selon l'indice
		float *projection = (i < 4) ? p01 : p11;  // Choisir p01 ou p11 selon l'indice
		printf("p%02d: projection x = %.2f, projection y = %.2f", i + 1, projection[0], projection[1]);
		
		// Ajouter des espaces entre les données
		for (int j = 0; j < console_width - 40; j++) {
			printf(" ");
		}

		// Affichage des coordonnées originales
		printf("p%02d: x = %.2f, y = %.2f, z = %.2f\n", i + 1, tableau[i][0], tableau[i][1], tableau[i][2]);
	}

	usleep(50000);
}


int main() {
    int lignes = 52;
    int espaces_par_ligne = 101;

    char *chaine = creer_chaine(lignes, espaces_par_ligne);
    if (chaine == NULL) {
        return 1;
    }

    char *chaine2 = creer_chaine(lignes, espaces_par_ligne);
    if (chaine == NULL) {
        return 1;
    }

    while (1) {
        strchange(chaine, chaine2);
    }

    free(chaine);

    return 0;
}
