# Libft

Libft est une bibliothèque personnelle écrite en C, qui recrée des fonctions standard de la libc et propose des outils supplémentaires pour faciliter le développement de projets.

## Installation

Clonez le dépôt et compilez la bibliothèque :

```bash
git clone https://github.com/stunox/libft.git
cd libft
make
```
Cela génère un fichier libft.a, une bibliothèque statique que vous pouvez utiliser dans vos projets.

# Utilisation
Ajoutez libft.a à votre projet en l'incluant dans les options de compilation.
Incluez le fichier d'en-tête libft.h dans vos fichiers source.
Exemple
```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, Libft!");
    ft_putstr_fd(str, 1);
    free(str);
    return 0;
}
```
Compilez avec :

```bash
gcc main.c -L. -lft -o main
```
# Contenu
La bibliothèque inclut des fonctions divisées en plusieurs catégories :

Fonctions de la libc : `ft_strlen`, `ft_strcpy`, `ft_atoi`, etc.
Fonctions supplémentaires : `ft_split`, `ft_strjoin`, `ft_itoa`, etc.
Fonctions bonus (manipulation de listes chaînées) : `ft_lstnew`, `ft_lstadd_front`, `ft_lstdelone`, etc.
# Nettoyage
Pour supprimer les fichiers objets et la bibliothèque :

```bash
make clean
```
Pour tout nettoyer (fichiers objets, bibliothèque et binaires) :

```bash
make fclean
```
# Recompilation
Pour recompiler après modification du code source :

```bash
make re
```
# Licence
Ce projet est réalisé dans le cadre du cursus de l'école 42 et n'est pas sous licence officielle. Libre à vous de l'utiliser et de le modifier à des fins éducatives. 
