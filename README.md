# Just_42

// INTRO

* Voici le tronc commun de 42, tous les exos sont affiches.

/. HELP

* Toutes ces manipulations sont faites sur MACOS, je ne donne pas d'astuces pour les autres systèmes.
* J'utilise comme IDE : Xcode.
* Les compilateurs cc, gcc et clang sont par defaut sur les macs.
* Vim est par defaut sur les macs.
* Xcode permet de lier git facilement et meme de push sans passer par le terminal.
* 


GIT //

COMMANDES BASIQUES //

>>> git add .
	ajoute tous les fichiers a l'expediteur.
>>> git commit -m "#commentary"
	package tous les fichiers.
>>> git push
	envoie tous les fichiers a git, c'est fini.
>>> git rm #file
	supprime un fichier du commit.
>>> git clone git@github.com:yJuste/#repository.git
	clone le git de github.

SHELL //

ALIAS CC -WALL -WEXTRA -WERROR //

>>> touch ~/.shrc
	creer un fichier si ton shell est sur /bin/zsh (echo $SHELL )

>>> open ~/.shrc
	ouvrir le fichier et coller.
	``` sh
	alias W='cc -Wall -Wextra -Werror'
	```
>>> source ~/.shrc
	appliquer les modifications.

STDHEADER 42 //

* Pour installer le header 42 sur sa machine, aller sur le site :
	https://github.com/42Paris/42header
* Les informations sont clairs et precis. (Si un chemin n'existe pas, vous devez donc le creer soit avec 'mkdir', soit 'touch')
* Faites le directement dans le terminal avec ~/... ou vous pouvez l'avoir partout'
* Apres avoir coller les informations dans zshrc, vous pouvez utiliser les commandes :
	vim file.txt
* Dans vim, vous faites CTRL + :
* Vous ecrivez soit Stdheader, soit Std, soit vous appuyez sur F1.
* Le header apparait.


CODIUM ( COPILOT POUR XCODE ) //

* Aller sur le site et telecharger l'application.
* Lancer le programme.
* Accepeter les conditions de l'app et de l'extension sur GENERAL et :
	- Accessibility Settings ( accepte )
	- Extensions Settings ( accepte )
* Dans SERVICE :
	- Enregistrer un compte avec SIGN IN.
* Codium est pret.
