#include "dico.c"

int main(){
  puts("Nous allons tester les foncions: contains, nb_nodes, nb_children, height, nb_words");

  puts("Creation d'un dictionnaire vide que l'on remplit :");
  dico d=create_dico();
  add_rec(d, "ours", 4);
  add_rec(d, "ourse", 5);
  add_rec(d, "ourson", 6);
  add_rec(d, "oursonne", 8);
  add_rec(d, "brule", 5);
  add_rec(d, "brille", 6);
  add_rec(d, "bord", 4);
  add_rec(d, "bordeau", 7);
  add_rec(d, "bateau", 6);
  print_prefixe(d);
  printf("\n");

  puts("Le dictionnaire contient :");
  print_dico(d);
  printf("\n");

  printf("Le dicionnaire contient (iter) 'ours' ?     %d\n",contains_iter(d,"ours",4));
  printf("Le dicionnaire contient (rec) 'ours' ?      %d\n",contains_rec(d,"ours",4));
  printf("Le dicionnaire contient (iter) 'bonjour' ?  %d\n",contains_iter(d,"bonjour",7));
  printf("Le dicionnaire contient (rec) 'bonjour' ?   %d\n",contains_rec(d,"bonjour",7));
  printf("\n");

  printf("nombre de mots=%d\n", nb_words(d));
  printf("nombre de nodes=%d\n", nb_nodes(d));
  printf("taille=%d\n", height(d));
  printf("\n");
  printf("Le nombre d'enfants de b= %d\n",nb_children(d[get_index('b')]));
  printf("Le nombre d'enfants de y= %d\n",nb_children(d[get_index('y')]));
  printf("Le nombre d'enfants de o= %d\n",nb_children(d[get_index('o')]));

  printf("\n");
  puts("Destuction du dictionnaire");
  destroy_dico(&d);
}
