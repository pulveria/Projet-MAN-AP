#include "dico.h"

#define NB_KEYS 26
unsigned get_index(char c) { return c - 'a'; }
char get_char(unsigned index) { return index + 'a'; }


/*******************************************************************************
 (1) Primitives de construction et destruction d'un dictionnaire
********************************************************************************/

dico create_dico(){
    return (dico)calloc(NB_KEYS,sizeof(struct node*));
}


void destroy_dico(dico *d){
    for(int i=0;i<NB_KEYS;i++){
        if ((*d)[i] != NULL){
            destroy_dico(&((*d)[i]->children));
            free((*d)[i]);
            (*d)[i]=NULL;
        }
    }
    free(*d);
}


/*******************************************************************************
 (2) Primitives de manipulation d'un dictionnaire (en tant que forêt)
********************************************************************************/

unsigned nb_children(tree t){
    if(t == NULL) return 0;
    unsigned nb_child=0;
    for(int i=0;i<NB_KEYS;i++){
        if ((t->children[i])!=NULL) nb_child++;
    }
    return nb_child;
}


unsigned nb_nodes(dico d){
    unsigned nb=0;
    for(int i=0;i<NB_KEYS;i++){
        if(d[i]!=NULL) nb+= 1 + nb_nodes((d[i])->children);
    }
    return nb;
}


unsigned max(unsigned tab[]){
    unsigned m=0;
    for(int i=0; i<NB_KEYS; i++){
        if(tab[i]>m) m=tab[i];
    }
    return m;
}

unsigned height(dico d){
    unsigned tab[NB_KEYS]={0};
    for(int i=0;i<NB_KEYS;i++){
        if((d[i])!=NULL) tab[i]+=1+height(d[i]->children);
    }
    return max(tab);
}


void print(dico d, char s[30]){
    for(int i=0;i<NB_KEYS;i++){
        if(d[i]!=NULL){
            char *fin="";
            if(d[i]->end_of_word) fin="*";
            printf("%s%c%s\n", s, d[i]->first, fin);
            if(nb_children(d[i])!=0){
                print(d[i]->children, strcat(s, "+ "));
                s[strlen(s)-2]='\0';
            }
        }
    }
}

void print_prefixe(dico d){
    int vide=1;
    for(int i=0;i<NB_KEYS;i++){
        if(d[i]!=NULL) vide=0;
    }
    if(vide==1){
        puts("Le dictionnaire est vide !");
        return;
    }
    char s[30]="";
    print(d, s);
}


int equals(dico d1, dico d2){
    int a=1;
    for(unsigned i=0;i<NB_KEYS;i++){
        if((d1[i]==NULL && d2[i]!=NULL) || (d1[i]!=NULL && d2[i]==NULL)) return 0;
        if(d1[i]!=NULL && d2[i]!=NULL) a=equals(d1[i]->children, d2[i]->children);
        if(a==0) break;
    }
    return a;
}


/*******************************************************************************
 (3) Utilisation du dictionnaire (itératif)
********************************************************************************/

int contains_iter(dico d, char * word, unsigned size){
    unsigned i=0;
    if(word==NULL)return 1;
    dico temp=d;
    while (i<size){
        if(temp[get_index(word[i])]==NULL || (i==size-1 && temp[get_index(word[i])]!=NULL && temp[get_index(word[i])]->end_of_word==0)) return 0;
        temp=temp[get_index(word[i])]->children;
        i++;
    }
    return 1;
}


int add_iter(dico d, char * word, unsigned size){
    if(contains_iter(d, word, size)) return 0;
    dico temp=d;
    unsigned i=0;
    while (i<size){
        if(temp[get_index(word[i])]==NULL){
            tree t=calloc(1, sizeof(struct node));
            t->first=word[i];
            t->end_of_word=0;
            t->children=create_dico();
            temp[get_index(word[i])]=t;
        }
        if(i==size-1) temp[get_index(word[i])]->end_of_word=1;
        temp=temp[get_index(word[i])]->children;
        i++;
    }
    return 1;
}


int remove_iter(dico d, char * word, unsigned size){
    if(!contains_iter(d, word, size) || word==NULL) return 0;
    dico d2=d;
    dico temp=d;
    unsigned j=get_index(word[0]);
    unsigned i=0;
    while(i<size){
        if((d2[get_index(word[i])]->end_of_word==1 && nb_children(d2[get_index(word[i])])!=0) || nb_children(d2[get_index(word[i])])>1){
            temp=d2[get_index(word[i])]->children;
            j=get_index(word[i+1]);
        }
        if(i<size-1) d2=d2[get_index(word[i])]->children;
        i++;
    }
    i--;
    if(nb_children(d2[get_index(word[i])])==0){
        destroy_dico(&temp[j]->children);
        temp[j]=NULL;
    }
    else d2[get_index(word[i])]->end_of_word=0;
    return 1;
}


/*******************************************************************************
 (4) Utilisation du dictionnaire (récursif)
********************************************************************************/

int contains_rec(dico d, char * word, unsigned size){
    if(size==0) return 1;
    if(d[get_index(word[0])]){
        if(size==1){
            if(d[get_index(word[0])]->end_of_word==1) return 1;
            return 0;
        }
        return contains_rec(d[get_index(word[0])]->children, &word[1], size-1);
    }
    return 0;
}


int add_rec(dico d, char * word, unsigned size){
    if(contains_rec(d, word, size)==1) return 0;
    if(d[get_index(word[0])]==NULL){
        tree t=calloc(1, sizeof(struct node));
        t->first=word[0];
        t->end_of_word=0;
        t->children=create_dico();
        d[get_index(word[0])]=t;
    }
    if(size==1){
        d[get_index(word[0])]->end_of_word=1;
        return 1;
    }
    return add_rec(d[get_index(word[0])]->children, &word[1], size-1);
}


int rm(dico d, char * word, unsigned size, dico temp, unsigned j){
    if((d[get_index(word[0])]->end_of_word==1 && nb_children(d[get_index(word[0])])!=0) || nb_children(d[get_index(word[0])])>1){
        temp=d[get_index(word[0])]->children;
        j=get_index(word[1]);
    }
    if(j>26){
        temp=d;
        j=get_index(word[0]);
    }
    if(size==1){
        if(nb_children(d[get_index(word[0])])==0){
            destroy_dico(&temp[j]->children);
            temp[j]=NULL;
        }
        else d[get_index(word[0])]->end_of_word=0;
        return 1;
    }
    return rm(d[get_index(word[0])]->children, &(word[1]), size-1, temp, j);
}

int remove_rec(dico d, char * word, unsigned size){
    if(!contains_rec(d, word, size) || size==0) return 0;
    dico temp=d;
    unsigned j=30;
    return rm(d, word, size, temp, j);
}


/*******************************************************************************
 (5) Autres routines (récursives) pour le dictionnaire
********************************************************************************/

unsigned nb_words(dico d){
    unsigned nb=0;
    for(int i=0;i<NB_KEYS;i++){
        if(d[i]!=NULL){
            if(d[i]->end_of_word==1) nb+= 1;
            nb+=nb_words((d[i])->children);
        }
    }
    return nb;
}


void affiche(dico d, char s[30]){
    for(int i=0;i<NB_KEYS;i++){
        if(d[i]!=NULL){
            strcat(s, &d[i]->first);
            if(d[i]->end_of_word==1) printf("%s\n", s);
            affiche(d[i]->children, s);
            s[strlen(s)-1]='\0';
        }
    }
}

void print_dico(dico d){
    int vide=1;
    for(int i=0;i<NB_KEYS;i++){
        if(d[i]!=NULL) vide=0;
    }
    if(vide==1){
        puts("Le dictionnaire est vide !");
        return;
    }
    char s[30]="";
    affiche(d, s);
}


/*******************************************************************************
 (6) Itérateur sur dictionnaire
********************************************************************************/

iterator * start_iterator(dico d){
    iterator *it = calloc(1, sizeof(iterator));
    it->word = calloc(height(d), sizeof(char));
    it->stack = calloc(nb_nodes(d), sizeof(struct iterator_info));
    it->index_stack=-1;
    for(int i=0;i<NB_KEYS;i++){
        if(d[i]!=NULL){
            struct iterator_info it_info;
            it_info.t=d[i];
            it_info.index_word=0;
            it->index_stack++;
            it->stack[it->index_stack]=it_info;
        }
    }
    return it;
}


void destroy_iterator(iterator ** it){
    while((*it)->index_stack>=0){
        destroy_dico(&((*it)->stack[(*it)->index_stack]).t->children);
        (*it)->index_stack--;
    }
    free((*it)->stack);
    free((*it)->word);
    free(*it);
}


int has_next(iterator * it){
    if(it->index_stack<0) return 0;
    return 1;
}


char * next (iterator * it){
    int end_of_word=0;
    do{
        it->word[it->stack[it->index_stack].index_word]=it->stack[it->index_stack].t->first;
        it->word[it->stack[it->index_stack].index_word +1]='\0';
        int index_word= it->stack[it->index_stack].index_word +1;
        end_of_word=it->stack[it->index_stack].t->end_of_word;
        dico d=it->stack[it->index_stack].t->children;
        it->index_stack--;
        for(int i=0;i<NB_KEYS;i++){
            if(d[i]!=NULL){
                //printf("\ncoucou\n");
                struct iterator_info it_info;
                it_info.t=d[i];
                it_info.index_word=index_word;
                it->index_stack++;
                it->stack[it->index_stack]=it_info;
            }
        }
    } while(end_of_word==0);
    return it->word;
}
