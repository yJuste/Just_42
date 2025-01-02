# Just_42

## // INTRO

Voici le tronc commun de 42, tous les exos sont affichés.

### Références de mes projets 42 :

* Le Milestone 0:

- [Just_Libft](https://github.com/yJuste/Just_Libft)

* Le Milestone 1:

- [Just_Born2BeRoot](https://github.com/yJuste/Just_Born2beRoot)
- [Just_Get_Next_Line](https://github.com/yJuste/Just_Get_Next_Line)
- [Just_Printf](https://github.com/yJuste/Just_Printf)

* Le Milestone 2:

- [Just_Push_Swap](https://github.com/yJuste/Just_Push_Swap)
- [Just_Minitalk](https://github.com/yJuste/Just_Minitalk)
- [Just_Fdf](https://github.com/yJuste/Just_Fdf)
- [Eval 2](https://github.com/yJuste/Just_Eval)

* Le Milestone 3:

- [Just_Philosophers](https://github.com/yJuste/Just_Philosophers)
... en cours.

* Other Ressources

- [Just_Piscine](https://github.com/yJuste/Just_Piscine)
- [Just_Reloaded](https://github.com/yJuste/Just_Reloaded)
- [Just_Lib](https://github.com/yJuste/Just_Lib)
- [Just_Eval](https://github.com/yJuste/Just_Eval)

## /. HELP

* Toutes les manipulations sont faites sur MACOS, je ne donne pas d'astuces pour les autres systèmes.
* J'utilise comme IDE : Xcode.
* Les compilateurs cc, gcc et clang sont par défaut sur les macs.
* Vim est par défaut sur les macs.
* Xcode permet de lier git facilement même de push sans passer par le terminal.

## GIT //

### COMMANDES BASIQUES //

``` sh
git add .
```
→ ajoute tous les fichiers à l'expéditeur.
``` sh
git commit -m "#commentary"
```
→ package tous les fichiers.
``` sh
git push
```
→ envoie tous les fichiers à git, c'est fini.
``` sh
git rm .file
```
→ supprime un fichier du commit.
``` sh
git clone git@github.com:yJuste/#repository.git
```
→ clone le git de github.
``` sh
git reset --hard <id-commit>
```
→ revient à une ancienne version de git.
``` sh
git push --force
```
→ suite à reset, tu appliques les modifications.

* For adding a tag:

``` sh
git tag -a v1.0 -m "Libft - Version finale"
git push origin v1.0
```
→ ajouter un tag quand tu as fini un projet.

## SHELL //

### ALIAS CC -Wall -Wextra -Werror //

``` sh
touch ~/.shrc
```
→ crée un fichier si ton shell est sur /bin/zsh (echo $SHELL).

``` sh
open ~/.shrc
```
→ ouvre le fichier et colle :

``` sh
alias W='cc -Wall -Wextra -Werror'
source ~/.shrc
```
→ applique les modifications.

### STDHEADER 42 //

Pour installer le header 42 sur la machine, va sur le site :

``` sh
https://github.com/42Paris/42header
```
* Les informations sont claires et précises. (Si un chemin n'existe pas, vous devez donc le créer soit avec mkdir, soit touch).
* Faites-le directement dans le terminal avec ~/... où vous pouvez l'avoir partout.
* Après avoir collé les informations dans zshrc, vous pouvez utiliser les commandes :

``` sh
vim file.txt
```
Dans vim, vous faites CTRL + :
* Vous écrivez soit Stdheader, soit Std, soit vous appuyez sur F1.
Le header apparaît.

### NORMINETTE 42 //

Pour installer la norminette, cherchez j’ai la flemme.
Sinon, 2 commandes à retenir :

``` sh
norminette
```
→ Vous devez être dans le dossier en question (cd <dir-name>) et vous lancez la commande sur tous les fichiers du répertoire.

``` sh
norminette -R CheckDefine
```
→ Les macros des fichiers .H seront ignorées.

### PMSET //

* Commande mac pour changer les temps d’inactivité du pc. Important de le changer rapidement pour économiser.
* Télécharge en plus la version gratuite de AlDente permettant de charger le pc au maximum à 80 %.

### GPUSWITCH //

* Sur Macos, on peut changer le basculement pour gérer la puissance du gpu. Si vous ne faites que coder et ne compilez pas, vous pouvez mettre le gpu au plus bas et inversement.

La commande est :
``` sh
pmset gpuswitch [0, 1, 2]
```
Le niveau 0 est le gpu intégré et consomme moins, moins de puissance.
Le niveau 1 est le gpu haute performance, consomme plus, toujours puissant.
Le niveau 2 est le mode automatique, le mac décide de lui-même quand changer.

### MEMORY LEAKS //

* Si tu veux un outil pour identifier les fuites de mémoires, tu peux utiliser "Leaks", l’outil de débogage par défaut de Xcode.
Il faut tout d'abord initialiser ( pas obligatoire finalement ) :
``` sh
export MallocStackLogging=1
```
Ensuite tu peux lancer leaks :
``` sh
leaks --atExit -- ./a.out [parameters]
```
* Tu peux ainsi voir les fuites de mémoires et les lignes où elles sont indiquées.
* Toujours tester avec des paramètres de ton code pour passer dans toutes les fonctions du programme.
* Comprendre l’essentiel dans Leaks pour identifier les fuites de mémoire.

* Tu as le nombre de stack représentant les fonctions dans lesquels passe la fuite de mémoire.
* La fuite commence à 0. Il représente l’allocation de ton système.
À 1, c’est l’endroit où tu as malloc. Logiquement, la variable allouée doit être libérée proprement. Évite de renvoyer une variable allouée pour la stocker dans une autre variable, exemple à proscrire :
``` c
char *block;

block = ft_allocate_str();

char **ft_allocate_str()
{
    str = malloc(...);
    return (str);
}
```
* Il vaut mieux passer en paramètre la seule et unique variable que tu vas utiliser (tu ne peux pas tout le temps le faire mais c’est une erreur courante).
``` c
char *block;

ft_allocate_str(&block);

...
```
* En remontant les stacks, tu trouveras l’endroit où tu n’utilises plus du tout ta variable et où il faut libérer la mémoire. (j’appelle stack mais ce n’est pas ça, c’est juste la piste où passe la fuite.)
* En dessous, tu peux voir 1 (48 bytes), signifiant que c’est un emplacement mémoire de taille 48 bytes. (les bytes peuvent varier en fonction du type, souvent les doubles tableaux).

### CODIUM (COPILOT POUR XCODE) //

* Aller sur le site et télécharger l’application.
* Lancer le programme.
* Accepter les conditions de l’app et de l’extension sur GENERAL et :
Accessibility Settings (accepte).
Extensions Settings (accepte).
* Dans SERVICE :
Enregistrer un compte avec SIGN IN.
Codium est prêt.

### DEBUGGING //

* Tout d’abord, si tu peux déboguer par toi-même avec une feuille de papier et un stylo, tu seras beaucoup plus concentré et tu comprendras mieux ton code en fond. Le debugging sert surtout pour les fuites de mémoire.
* Créer un algorithme avec un logiciel de debug est à proscrire, vraiment.
* Donc, j’utilise lldb.
Juste avant, vous devez compiler tous vos fichiers avec -g, exemple :
``` sh
cc -g mon-fichier.c
```
Ensuite, vous devez lancer lldb :
``` sh
lldb mon-fichier.c [paramètres]
```
* Mettre les paramètres va suivre le déroulement pour ce cas particulier. Tu peux tester avec plusieurs autres paramètres en fonction de ton code.
* Ensuite, tu vas devoir ajouter un breakpoint. Si vous voulez, c’est un endroit d’entrée. Car le point d’entrée par défaut est le main(), si tu veux commencer un peu plus loin, tu vas devoir le lancer avec le nom de la fonction, exemple :
``` sh
breakpoint set --name main
```
Ceci est le main par défaut, pour une fonction comme :
``` c
int	ft_get_next_line(int fd)
```
``` sh
(lldb) breakpoint set --name ft_get_next_line
```
* Il y aura alors une interface où tu pourras naviguer, les commandes à retenir sont s, n, finish. (s = step, n = next) (tu dois juste marquer la lettre).
* s : avancer pas à pas, instruction par instruction  
* n : pas à pas mais si il rencontre une fonction, il la passe (comme si il avait terminé la fonction pointée).  
* finish : si tu es dans une fonction, tu termines la fonction en cours (tu dois être dans la fonction).  
* Pour quitter, tu fais q (q = quit).

### MAKEFILE

* Make (petit logiciel utilisé avec les fichiers Makefile (et pas Makefile.txt, il y a une grande différence)) est utile pour compiler plusieurs fichiers .c en même temps. Ça utilise des commandes shell. Voici un exemple de Makefile très simple :

### Les archives

* Si tu souhaites utiliser des archives de fichiers compilés pour en faire une librairie static, voila comment faire :
``` sh
ar rcs libft.a *.o
```
* Il faut que le nom de la lib commence par 'lib...'.
* Ensuite, pour le relier à un main, tu dois inclure le fichier .h de la bibliotheque
``` c
#include "libft.h"
```

* Lors de la compilation, tu dois utiliser en flags `-L. -lft`
``` sh
cc ft_test.c -L . -lft
```
* Cette commande signifie : J'inclus la lbrairie '-L' depuis le dossier courant '.', puis j'inclus la libft.a '-lft' ( c'est en fait le nom sans le .a et en raccourci '-l' plutôt que 'lib')

## // EOF:

Modifié le 9 octobre 2024 par Juste.
