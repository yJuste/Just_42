Voici toute ma librairie de fonctions basiques en C.

// INTRO

Les fichiers qui vous sont donnes sont disponible pour votre confort. Elles s'utilisent comme une librairie.

/. LIBRARY

* Les fichiers sont des fonctions simples en C tels que ft_putchar, ft_atoi, ft_putnbr. Ceux-ci sont proviennent de librairie deja existante comme <stdlib.h>, <unistd.h>, <stdio> ...
* Les fichiers peuvent aussi etre des fichiers C headers pour contenir des prototypes ou des macros comme ft_abs.h, ft_boolean.h ...
* Les fichiers se presente comme ceci : ( exemple avec ft_split )

```
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns an arr of arr defined by a separator.                          */
/*   • Prototype:   CHAR ** ( char *, char * )                                */
/*        -> malloc ( sizeof(type) * size )                                   */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include <stdlib.h>
```

Le header de 42 qui se compose :

* du nom du fichier : ft_split.c
* d'une description courte de la fonction
* du prototypage avec le type et le nom des parametres
* des fonctions externes utilises
* ( > de la bibliotheque qui se trouve en dessous )

/: PROTOTYPE

Pour rechercher une fonction dans le dossier Just_Lib, soit :
* Vous marquez le nom de la fonction,
* Soit vous écrivez le prototypage avec comme patterne :
[type][space][*][space] ( [space][type][space][*][,][space][type][space][*][space][,]... )

ex (pour ft_split): "CHAR ** ( char *, char * )"
(pour ft_putchar): "VOID ( char )"
(pour ft_calloc): "VOID * ( int, int )"

/:. EOF

* Et si tout cela vous semble complique, demandez de l'aide autour de vous. Internet ainsi que les manuels sont vos amis.
Et Don't Panic!

Modifié le 9 octobre 2024 par Juste

Merci à Lucas pour le ft_convert_base
