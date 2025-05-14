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
- [Just_Fractol](https://github.com/yJuste/Just_Fractol)
- [Just_So_Long](https://github.com/yJuste/Just_So_long)

- [Eval 2: Exos_Pisicine](https://github.com/yJuste/Just_Eval)

* Le Milestone 3:

- [Just_Philosophers](https://github.com/yJuste/Just_Philosophers)
- [Just_Minishell](https://github.com/yJuste/Just_Minishell)

- [Eval 3: ft_printf/gnl](https://github.com/yJuste/Just_Eval)

* Le Milestone 4:

- [Just_NetPractice](https://github.com/yJuste/Just_NetPractice)
- [Just_CPP](https://github.com/yJuste/Just_CPP)
- [Just_miniRT](https://github.com/yJuste/Just_miniRT) (en cours)
- [Eval 4: Microshell](https://github.com/yJuste/Just_Eval)

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

## MACOS TERMINAL

* Le terminal Macos est l'outil idéal pour vos projets 42.
* Vous pourrez créer des onglets de terminaux, personnaliser vos terminaux. Utile aussi avec tmux et vim.
* Le site pour voir les raccourcis : [Raccourcis Apple](https://support.apple.com/et-ee/guide/terminal/trmlshtcts/mac)
* Voici les commandes utiles qui sont importants à apprendre:
```sh
Cmd + n
```
* Permet d'ouvrir un terminal.
```sh
Cmd + w
```
* Exit un terminal (ou un onglet).
* Les commandes lorsque vous venez d'ouvrir un terminal.
```sh
Cmd + t
```
* Ouvrre un onglet.
```sh
Cmd + ,
```
* Ouvre les réglages.
```sh
Cmd + i
```
* Renomme le nom de l'onglet.
* Pour naviguer:
```sh
Cmd + [tab]
```
* Passe au prochain onglet.
```sh
Cmd + [shift] + [tab]
```
* Passe à l'onglet précedent.

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
* Tester avec des parametres, si le test de leak que tu veux faire en a besoin.
* Comprendre l’essentiel dans Leaks pour identifier les fuites de mémoire.

* Tu as le nombre de stack représentant les fonctions dans lesquels passe la fuite de mémoire.
* La fuite commence à 0. Il représente l’allocation de ton système.
À 1, c’est l’endroit où tu as malloc. Logiquement, la variable allouée doit être libérée proprement.
* En remontant les stacks, tu trouveras l’endroit où tu n’utilises plus du tout ta variable et où il faut libérer la mémoire. (j’appelle stack mais ce n’est pas ça, c’est juste la piste où passe la fuite.)
* En dessous, tu peux voir 1 (128 bytes), signifiant que c’est un emplacement mémoire de taille 128 bytes. (les bytes peuvent varier en fonction du type, souvent les doubles tableaux).
* 1 signifie qu'il te reste 1 malloc() à free().
Voici l'exemple:
```sh
leaks Report Version: 4.0, multi-line stacks
Process 71341: 185 nodes malloced for 14 KB
Process 71341: 1 leak for 128 total leaked bytes.

STACK OF 1 INSTANCE OF 'ROOT LEAK: <malloc in ft_calloc>':
4   dyld                                  0x1877a8274 start + 2840
3   philo                                 0x1043365ec main + 104
2   philo                                 0x1043366a8 ft_init + 120
1   philo                                 0x104337bfc ft_calloc + 48
0   libsystem_malloc.dylib                0x1879627cc _malloc_zone_malloc_instrumented_or_legacy + 148 
====
    1 (128 bytes) ROOT LEAK: <malloc in ft_calloc 0x137f04200> [128]
```

### TMUX

* Bon, je te présente un gestionnaire de terminaux, plus besoin d'en ouvrir 150 mille, voici Tmux. Il te permet d'en créer sur mesure et n'import au, toujours au bon format.
* Pour ouvrir un tmux, il faut taper `tmux`. Tu te retrouve avec une interface où en bas il y a une bande verte, tu gestionneras tout ici. Ainsi que avec les touches Ctrl + b qui est la commande de base pour tout gérer.
* Les commandes de base pour bien commencer :
- `tmux ls` -> affiche toutes les sessions.
* Pour revenir à une session et la quitter lorsque tu es dans tmux, tu peux faire :
```sh
tmux attach -t 0
```
- 0 peut être changé par X nombre et X nom.
* Pour quitter quand t es dans tmux, c'est:
```sh
Ctrl + b -- d
```
* Cela détache la session tmux, cela signifie que il tourne en arrière-plan, sauf quand le pc est en veille ou éteint, donc pas de panique sur la batterie.
* Dans tmux, il te sera utile de connaître le manuel de leur commande qui se trouve avec : (`--` signifie: et ensuite tape .. )
```sh
Ctrl + b -- Shift + ?
```
* On peut créer plusieurs fenêtres dans une session avec :
```sh
Ctrl + b -- c
```
* (ne pas oublier que ce sont des terminaux, donc si tu veux les quitter, tu peux faire `exit`).
* Ensuite dans une fenêtre, tu peux split les terminaux et travaille avec.
* Les commandes pour gérer efficacement les fenêtres sans connaître par coeur tous les raccourcis, tu peux utiliser :
```sh
Ctrl + b -- Shift + <
Ctrl + b -- Shift + >
```
* D'ici tu peux split les terminaux, c'est très efficace, pour se déplacer, tu fais `Ctrl + b -- [fleches directionelles]`.
* Quand tout est setup, tu peux utiliser Vim et allier les 2 pour encore plus de fun!
* Ensuite pour les tmuxiens, vous avez certaines commandes qui me sont très utiles comme :
```sh
Ctrl + b -- Shift + :
```
* Ouvre une invite pour tu peux taper ici, `:resize-pane -X Y`, permet de redimensioner les split de terminaux. Remplace X par -U -D -L -R pour up, down, left, right. Remplace Y par la taille, une taille de 10 est bien.

### SSH

* SSH permet de se connecter de facon sécurisé à distant via un réseau.
* La commande pour s'y connecter est:
```sh
ssh [ip]
```
* Pour voir les ip connecté au réseau tu peux faire: (cela va lister toutes les connexions présents en temps réel).
```sh
arp -a
```
* Par exemple, j'ai un raspberry et pour me connecter je dois mettre :
```sh
ssh username@hostname.local
```
* Pour se connecter via une clé privée spécifique. Tu dois ajouter le chemin.
```sh
ssh -i chemin/id_rsa
```

## SSH-KEYGEN

* La protection des données est importante et il faut bien se protéger lors des connexions tels que dans les connexions ssh.
* Voici des flags utiles lors de la création de la clé.
* Aller voir qui explique parfaitement comment fonctionne les types de clé et les chiffrements: [Les clés SSH](https://www.acceis.fr/comment-casser-des-cles-privees-ssh-chiffrees/)
* Voici un exemple:
```sh
ssh-keygen -t ed25519 -Z aes256-gcm@openssh.com -b 256 -f ~/.ssh/id_rsa -o -a 500
```
* Le flag `-t` spécifie le type de clé. Les plus connus sont le RSA et le ed25519.
* Le flag `-Z` spécifie le chiffrement. Le plus connu est le AES.
* Le flag `-b` spécifie la taille de la clé. 256bits est bien pour ed25519.
* Le flag `-f` spécifie le nom dans lequel le duo de clé privé/public seront enregistrés.
* Le flag `-o` utilise le nouveau format openSSH.
* Le flag `-a` le nombre d'itération.
* Si tu as ajouté une passphrase, il se peut que à chaque utilisation de la clé ssh, tu dois mettre celui-ci. Pour pallier à ce problème, tu peux le mettre dans l'agent ssh.
```sh
ssh-add ~/.ssh/id_rsa
```
* Le nom id_rsa peut se changer en fonction du nom donné du fichier.

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
* Ensuite, tu vas devoir ajouter un breakpoint avec `b`. Si vous voulez, c’est un endroit d’entrée. Car le point d’entrée par défaut est le main(), si tu veux commencer un peu plus loin, tu vas devoir le lancer avec le nom de la fonction, exemple :
``` sh
(lldb ) b main
```
Ceci est le main par défaut, pour une fonction comme : get_next_line(fd);
``` sh
(lldb) b get_next_line
```
* Il y aura alors une interface où tu pourras naviguer, les commandes à retenir sont s, n, finish. (s = step, n = next) (tu dois juste marquer la lettre).
* s : avancer pas à pas, instruction par instruction  
* n : pas à pas mais si il rencontre une fonction, il la passe (comme si il avait terminé la fonction pointée).  
* finish : si tu es dans une fonction, tu termines la fonction en cours (tu dois être dans la fonction).  
* Pour quitter, tu fais q (q = quit).

### Debbuging with Instruments

* Créer un ficher : entitlements.plist
* Tu peux maitenant le trouver dans le dossier `Instruments`. Le ficher doit etre dans le meme directory que l'executable .out.
* Ensuite, tu peux le signer avec ad-hoc. Cela ne requiert pas un certificat car il inclut deja un titre pour le debugging.
``` sh
codesign --entitlements entitlements.plist --sign - a.out
```
* Vérifie qu'il possède bien les perms:
``` sh
codesign -dvvv --entitlements - a.out
```

### MAKEFILE

* Make (petit logiciel utilisé avec les fichiers Makefile (et pas Makefile.txt, il y a une grande différence)) est utile pour compiler plusieurs fichiers .c en même temps. Ça utilise des commandes shell. Voici un exemple de Makefile très simple :
```make
NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	srcs/ft_get_next_line.c	\
	    srcs/ft_lib.c	    	\
    	srcs/ft_lib2.c	    	\
    	main.c		        	\
    	rush-01.c		        \
    	rush-02.c		        \
	    rush-03.c		        \
    	rush-04.c		        \

OBJ = $(SRC:.c=.o)

RESET			= "\033[0m"
GREEN			= "\033[92m"	# Green
RED			    = "\033[91m"	# Red

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo $(GREEN)"--- EXECUTABLE ./$(NAME) is ready ---"$(RESET)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

rf: re
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

s:
	ls -lh $(NAME)

h:
	head -n 18 main.c

.PHONY: all clean fclean re rf
```

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

Modifié le 9 octobre 2024 par Juste.<br>
Modifié le 14 Mai 2025 par Juste.
