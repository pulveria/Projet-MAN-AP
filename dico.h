#ifndef DICO_H
#define DICO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NB_KEYS 26

/*******************************************************************************
 (0) Structure dico
********************************************************************************/
struct node {
    char first;
    int end_of_word;
    struct node ** children;
};

typedef struct node * tree;
typedef struct node ** dico;

unsigned get_index(char c);
char get_char(unsigned index);

/*******************************************************************************
 (1) Primitives de construction et destruction d'un dictionnaire
********************************************************************************/
dico create_dico(void);
void destroy_dico(dico* d);

/*******************************************************************************
 (2) Primitives de manipulation d'un dictionnaire (en tant que forêt)
********************************************************************************/
unsigned nb_children(tree t);
unsigned nb_nodes(dico d);
unsigned max(unsigned tab[]);
unsigned height(dico d);
void print_prefixe(dico d);
int equals(dico d1, dico d2);

/*******************************************************************************
 (3) Utilisation du dictionnaire (itératif)
********************************************************************************/
int contains_iter(dico d, char * word, unsigned size);
int add_iter(dico d, char * word, unsigned size);
int remove_iter(dico d, char * word, unsigned size);

/*******************************************************************************
 (4) Utilisation du dictionnaire (récursif)
********************************************************************************/
int contains_rec(dico d, char * word, unsigned size);
int add_rec(dico d, char * word, unsigned size);
int remove_rec(dico d, char * word, unsigned size);

/*******************************************************************************
 (5) Autres routines (récursives) pour le dictionnaire
********************************************************************************/
unsigned nb_words(dico d);
void print_dico(dico d);

/*******************************************************************************
 (6) Itérateur sur dictionnaire
********************************************************************************/
struct iterator_info {
    tree t;
    int index_word;
};

struct _iterator {
    char * word;
    struct iterator_info * stack;
    int index_stack;
};

typedef struct _iterator iterator;

iterator * start_iterator(dico d);
void destroy_iterator(iterator ** it);
int has_next(iterator * it);
char * next (iterator * it);


#endif
