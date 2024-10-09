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

* `git add .`<br>
	ajoute tous les fichiers a l'expediteur.<br>
* `git commit -m "#commentary"`<br>
	package tous les fichiers.<br>
* `git push`<br>
	envoie tous les fichiers a git, c'est fini.<br>
* `git rm .file`<br>
	supprime un fichier du commit.<br>
* `git clone git@github.com:yJuste/#repository.git`<br>
	clone le git de github.<br>

##	SHELL //

###		ALIAS CC -WALL -WEXTRA -WERROR //

* `touch ~/.shrc`
	creer un fichier si ton shell est sur /bin/zsh ( echo $SHELL )<br>

* `open ~/.shrc`
	ouvrir le fichier et coller.<br>
	``` sh
	alias W='cc -Wall -Wextra -Werror'
	```
* `source ~/.shrc`
	appliquer les modifications.<br>

###		STDHEADER 42 //

* Pour installer le header 42 sur sa machine, aller sur le site :<br>
`https://github.com/42Paris/42header`<br>
* Les informations sont clairs et precis. (Si un chemin n'existe pas, vous devez donc le creer soit avec 'mkdir', soit 'touch')<br>
* Faites le directement dans le terminal avec ~/... ou vous pouvez l'avoir partout'<br>
* Apres avoir coller les informations dans zshrc, vous pouvez utiliser les commandes :<br>
`vim file.txt`<br>
* Dans vim, vous faites CTRL + :<br>
* Vous ecrivez soit Stdheader, soit Std, soit vous appuyez sur F1.<br>
* Le header apparait.<br>

###		PMSET //

* Commande mac pour changer les temps d'inactivite du pc. Important de le changer rapidement pour economiser.<br>
* Telecharge en plus la version gratuite de AlDente permettant de charger le pc au maximum a 80%.<br>

###			GPUSWITCH //

* Sur Macos, on peut changer le basculement pour gerer la puissance du gpu. Si vous ne faites que coder et vous ne compilez pas, vous pouvez mettre le gpu au plus bas et inversement.<br>
La commande est : `pmset gpuswitch [0, 1, 2]`<br>
Le niveau 0 est le gpu integre et consomme moins, moins de puissance.<br>
Le niveau 1 est le gpu haute performance, consomme plus, toujours puissant.<br>
Le niveau 2 est le mode automatique, le mac decide de lui meme quand changer.<br>

###			MEMORY LEAKS //

* Si tu veux un outil pour identifier les fuites de memoires, tu peux utiliser "Leaks", l'outil de deboggage par defaut de Xcode.<br>
Il faut tout d'abord initialiser :<br>
`export MallocStackLogging=1`<br>
* Ensuite tu peux lancer leaks :<br>
`leaks --atExit -- ./a.out [parameters]`<br>
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

##	/: EOF

Modifié le 9 octobre 2024 par Juste.
