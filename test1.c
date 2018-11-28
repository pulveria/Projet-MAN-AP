#include "dico.c"

int main(){
  puts("Création d'un dictionnaire vide");
  dico d=create_dico();
  print_prefixe(d);
  printf("\n");
  puts("On ajoute (iter) dans le dictionnaire: {ours, ourse, oursonne, ourson, brule, ours, brille, ours, zoo}");

  puts("On ajoute ours");
  add_iter(d, "ours", 4);
  print_prefixe(d);
  printf("\n");

  puts("On ajoute ourse");
  add_iter(d, "ourse", 5);
  print_prefixe(d);
  printf("\n");

  puts("On ajoute oursonne");
  add_iter(d, "oursonne", 8);
  print_prefixe(d);
  printf("\n");

  puts("On ajoute ourson");
  add_iter(d, "ourson", 6);
  print_prefixe(d);
  printf("\n");

  puts("On ajoute brule");
  add_iter(d, "brule", 5);
  print_prefixe(d);
  printf("\n");

  puts("On ajoute ours");
  add_iter(d, "ours", 4);
  print_prefixe(d);
  printf("\n");

  puts("On ajoute brille");
  add_iter(d, "brille", 6);
  print_prefixe(d);
  printf("\n");

  puts("On ajoute ours");
  add_iter(d, "ours", 4);
  print_prefixe(d);
  printf("\n");

  puts("On ajoute zoo");
  add_iter(d, "zoo", 3);
  print_prefixe(d);
  printf("\n");

  puts("On affiche le dictionnaire :");
  print_dico(d);
  printf("\n");

  puts("Destuction du dictionnaire");
  destroy_dico(&d);
}
