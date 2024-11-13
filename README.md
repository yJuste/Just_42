# Just_42

## // INTRO

* Voici le tronc commun de 42, tous les exos sont affiches.

## /. HELP

* Toutes ces manipulations sont faites sur MACOS, je ne donne pas d'astuces pour les autres systèmes.
* J'utilise comme IDE : Xcode.
* Les compilateurs cc, gcc et clang sont par defaut sur les macs.
* Vim est par defaut sur les macs.
* Xcode permet de lier git facilement et meme de push sans passer par le terminal.

##	GIT //

###		COMMANDES BASIQUES //

``` sh
git add .
```
'-> ajoute tous les fichiers a l'expediteur.<br>
``` sh
git commit -m "#commentary"
```
'-> package tous les fichiers.<br>
``` sh
git push
```
'-> envoie tous les fichiers a git, c'est fini.<br>
 ``` sh
git rm .file
```
'-> supprime un fichier du commit.<br>
``` sh
git clone git@github.com:yJuste/#repository.git
```
'-> clone le git de github.<br>

``` sh
git reset --hard <id-commit>
```
'-> revient a une ancienne version de git.<br>
``` sh
git push --force
```
'-> suite a reset, tu appliques les modifications.<br>
``` sh
git tag -a v1.0 -m "Libft - Version finale"
git push origin v1.0
```
'-> ajouter un tag quand tu as fini un projet.<br>

##	SHELL //

###		ALIAS CC -WALL -WEXTRA -WERROR //

``` sh
touch ~/.shrc
```
'-> creer un fichier si ton shell est sur /bin/zsh ( echo $SHELL )<br>
``` sh
open ~/.shrc
```
'-> ouvrir le fichier et coller.
``` sh
alias W='cc -Wall -Wextra -Werror'
```
``` sh
source ~/.shrc
```
'-> appliquer les modifications.<br>

###		STDHEADER 42 //

Pour installer le header 42 sur sa machine, aller sur le site :<br>
``` sh
https://github.com/42Paris/42header
```
Les informations sont clairs et precises. (Si un chemin n'existe pas, vous devez donc le creer soit avec 'mkdir', soit 'touch')<br>
Faites le directement dans le terminal avec ~/... ou vous pouvez l'avoir partout'<br>
Apres avoir coller les informations dans zshrc, vous pouvez utiliser les commandes :<br>
```
vim file.txt
```
* Dans vim, vous faites `CTRL + :`<br>
* Vous ecrivez soit Stdheader, soit Std, soit vous appuyez sur F1.<br>
* Le header apparait.<br>

###		NORMINETTE 42 //

Pour installer la norminette, cherchez j'ai la flemme.<br>
Sinon 2 commandes à retenir :<br>
``` sh
norminette
```
'-> Vous devez etre dans le dossier en question (cd <dir-name>) et vous lancer la commande sur tous les fichiers du repertoire.<br>
``` sh
norminette -R CheckDefine
```
'-> Les macros des fichiers .H seront ignores.<br>

###		PMSET //

* Commande mac pour changer les temps d'inactivite du pc. Important de le changer rapidement pour economiser.<br>
* Telecharge en plus la version gratuite de AlDente permettant de charger le pc au maximum a 80%.<br>

###			GPUSWITCH //

* Sur Macos, on peut changer le basculement pour gerer la puissance du gpu. Si vous ne faites que coder et vous ne compilez pas, vous pouvez mettre le gpu au plus bas et inversement.<br>
La commande est :
``` sh
pmset gpuswitch [0, 1, 2]
```
Le niveau 0 est le gpu integre et consomme moins, moins de puissance.<br>
Le niveau 1 est le gpu haute performance, consomme plus, toujours puissant.<br>
Le niveau 2 est le mode automatique, le mac decide de lui meme quand changer.<br>

###			MEMORY LEAKS //

* Si tu veux un outil pour identifier les fuites de memoires, tu peux utiliser "Leaks", l'outil de deboggage par defaut de Xcode.<br>
Il faut tout d'abord initialiser :<br>
``` sh
export MallocStackLogging=1
```
* Ensuite tu peux lancer leaks :<br>
``` sh
leaks --atExit -- ./a.out [parameters]
```
Tu peux ainsi voir les fuites de memoires et les lignes ou elles sont indiquees.<br>
Toujours tester avec des parametres de ton code pour passer dans toutes les fonctions du programme.<br>
Comprendre l'essentiel dans Leaks pour identifer les fuites de memoire.

<img width="612" alt="Leaks-example" src="https://github.com/user-attachments/assets/9c9a1a83-cb62-4797-8f7a-9074e8700974">

Tu as le nombre de stack representant les fonctions dans lesquels passent la fuite de memoire.
La fuite commence à `0`. Il represente l'allocation de ton système.
A `1`, c'est l'endroit où tu as malloc. Logiquement, la variable alloué doit etre libéré proprement. Evite de renvoyer une variable alloué pour la stocker dans une autre variable, ex à proscrire :
``` c
char *block;

block = ft_allocate_str();

char **ft_allocate_str();
{
	str = malloc(...);
	return (str);
}
```
Il vaut mieux passer en parametre la seule et unique variable que tu vas utiliser (tu ne peux pas tout le temps le faire mais c'est une erreur courante.)
``` c
char *block;

ft_allocate_str(&block);

...
```
* En remontant les stacks, tu trouveras l'endroit ou tu n'utilises plus du tout ta variable et où il faut libérer la mémoire. (j'appelle `stack` mais c'est pas ca, c'est juste la piste ou passe la fuite.)
* En desous, tu peux voir `1 (48 bytes)`, signifiant que c'est un emplacement mémoire de taille 48 bytes. (les bytes peuvent varier en fonction du type, souvent les doubles tableaux).


###		CODIUM ( COPILOT POUR XCODE ) //

* Aller sur le site et telecharger l'application.<br>
* Lancer le programme.<br>
* Accepeter les conditions de l'app et de l'extension sur GENERAL et :<br>
	- Accessibility Settings ( accepte )<br>
	- Extensions Settings ( accepte )<br>
* Dans SERVICE :<br>
	- Enregistrer un compte avec SIGN IN.<br>
* Codium est pret.<br>

###		DEBUGGING //

* Tout d'abord, si tu peux debugger par toi-meme avec une feuille de papier et un stylo, tu seras beaucoup plus concentré et tu comprendras mieux ton code en fond. Le debugging sert surtout pour les fuites de mémoire.<br>
* Creer un algorithme avec un logiciel de debug est à proscrire, vraiment.<br>
* Donc, j'utilise `lldb`.<br>
Juste avant, vous devez compiler tout tes fichiers avec -g, ex :<br>
``` sh
cc -g mon-fichier.c
```
Ensuite, vous devez lancer lldb :<br>
``` sh
lldb mon-fichier.c [parametres]
```
Mettre les parametres va suivre le deroulement pour ce cas particulier. Tu peux tester avec plusieurs autres parametres en fonction de ton code.<br>
Ensuite, tu vas devoir ajouter un breakpoint. Si vous voulez, c'est un endroit d'entrée. Car le point d'entree par defaut est le main(), si tu veux commencer un peu plus loin, tu vas devoir le lancer avec le nom de la fonction, ex :<br>
``` sh
breakpoint set --name main
```
Ceci est le main par defaut, pour une fonction comme :		int	ft_get_next_line(int fd)<br>
``` sh
breakpoint set --name ft_get_next_line
```
* Il y aura alors une interface ou tu pourras naviguer, les commandes a retenir sont `s`, `n`, `finish`. (s = step, n = next) (tu dois juste marquer la lettre).<br>
``` sh
`s` : avancer pas a pas, instruction par instruction
`n` : pas a pas mais si il rencontre une fonction, il le passe (comme si il avait terminé la fonction pointé.)
`finish` : si tu es dans une fonction, tu termines la fonction en cours (tu dois etre dans la fonction.)
```
Pour quitter, tu fais `q` (q = quit).<br>

###		MAKEFILE

* Make (petit logiciel utilisé avec les fichiers Makefile (et pas Makefile.txt, il y a une grande différence)) est utile pour compiler plusieurs fichiers .c en meme temps. Ca utilise des commandes **shell**. Voici un exemple de Makefile tres simple :

<img width="675" alt="Makefil example" src="https://github.com/user-attachments/assets/a44fd852-9ec3-43e3-8dcb-0a68ebfc8121">


##	/: EOF

Modifié le 9 octobre 2024 par Juste.<br>
