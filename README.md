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
ajoute tous les fichiers a l'expediteur.<br>
``` sh
git commit -m "#commentary"
```
package tous les fichiers.<br>
``` sh
git push
```
envoie tous les fichiers a git, c'est fini.<br>
 ``` sh
git rm .file
```
supprime un fichier du commit.<br>
``` sh
git clone git@github.com:yJuste/#repository.git
```
clone le git de github.<br>

##	SHELL //

###		ALIAS CC -WALL -WEXTRA -WERROR //

``` sh
touch ~/.shrc
```
creer un fichier si ton shell est sur /bin/zsh ( echo $SHELL )<br>
``` sh
open ~/.shrc
```
ouvrir le fichier et coller.
``` sh
alias W='cc -Wall -Wextra -Werror'
```
``` sh
source ~/.shrc
```
appliquer les modifications.<br>

###		STDHEADER 42 //

Pour installer le header 42 sur sa machine, aller sur le site :<br>
``` sh
https://github.com/42Paris/42header
```
Les informations sont clairs et precis. (Si un chemin n'existe pas, vous devez donc le creer soit avec 'mkdir', soit 'touch')<br>
Faites le directement dans le terminal avec ~/... ou vous pouvez l'avoir partout'<br>
Apres avoir coller les informations dans zshrc, vous pouvez utiliser les commandes :<br>
```
vim file.txt
```
* Dans vim, vous faites CTRL + :<br>
* Vous ecrivez soit Stdheader, soit Std, soit vous appuyez sur F1.<br>
* Le header apparait.<br>

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
Tu peux ainsi voir les fuites de memoires et les lignes ou elles sont indiquees. Toujours tester avec des parametres de ton code pour passer dans toutes les fonctions du programme.<br>

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

* Tout d'abord, si tu peux debugger par toi-meme avec une feuille de papier et un stylo, tu seras beaucoup plus concentré et tu comprendras mieux ton code en fond. Le debugging sert surtout pour les fuites de mémoire.
* Creer un algorithme avec un logiciel de debug est à proscrire, vraiment.
* Donc, j'utilise `lldb`.
Juste avant, vous devez compiler tout tes fichiers avec -g, ex :
``` sh
cc -g mon-fichier.c
```
Ensuite, vous devez lancer lldb :
``` sh
lldb mon-fichier.c [parametres]
```
Mettre les parametres va suivre le deroulement pour ce cas particulier. Tu peux tester avec plusieurs autres parametres en fonction de ton code.
Ensuite, tu vas devoir ajouter un breakpoint. Si vous voulez, c'est un endroit d'entrée. Car le point d'entree par defaut est le main(), si tu veux commencer un peu plus loin, tu vas devoir le lancer avec le nom de la fonction, ex :
``` sh
breakpoint set --name main
```
Ceci est le main par defaut, pour une fonction comme :		int	ft_get_next_line(int fd)
``` sh
breakpoint set --name ft_get_next_line
```
* Il y aura alors une interface ou tu pourras naviguer, les commandes a retenir sont `s`, `n`, `finish`. (s = step, n = next) (tu dois juste marquer la lettre).
``` sh
`s` : avancer pas a pas, instruction par instruction
`n` : pas a pas mais si il rencontre une fonction, il le passe (comme si il avait terminé la fonction pointé.)
`finish` : si tu es dans une fonction, tu termines la fonction en cours (tu dois etre dans la fonction.)
```
Pour quitter, tu fais `q` (q = quit).

##	/: EOF

Modifié le 9 octobre 2024 par Juste.<br>
