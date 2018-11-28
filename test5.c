#include "dico.c"

int main(){
  puts("Test de l'iterateur\n");
  dico d=create_dico();
  puts("On cree un dictionnaire vide dans lequel on ajoute: {ours, ourse, ourson, oursonne, brule, ours, brille, ours, bateau, bord, bordeau}");
  add_rec(d, "ours", 4);
  add_rec(d, "ourse", 5);
  add_rec(d, "ourson", 6);
  add_rec(d, "oursonne", 8);
  add_rec(d, "brule", 5);
  add_rec(d, "ours", 4);
  add_rec(d, "brille", 6);
  add_rec(d, "ours", 4);
  add_rec(d, "bateau", 6);
  add_rec(d, "bord", 4);
  add_rec(d, "bordeau", 7);
  printf("\n");

  puts("Creation de l'itérateur, qui nous fournit itérativement :");
  iterator * dit = start_iterator(d);
  while (has_next(dit)) printf("-%s", next(dit));
  destroy_iterator(&dit);
  printf("\n");
  puts("Destruction de l'itérateur");

  printf("\n");
  puts("Destuction du dictionnaire");
  destroy_dico(&d);
}
