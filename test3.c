#include "dico.c"

int main(){

  puts("Test de la fonction equals");
  puts("On crée 2 dictionnaires avec rec/iter");

  dico d_iter=create_dico();
  add_iter(d_iter, "ours", 4);
  add_iter(d_iter, "ourse", 5);
  add_iter(d_iter, "ourson", 6);
  add_iter(d_iter, "oursonne", 8);
  add_iter(d_iter, "brule", 5);
  add_iter(d_iter, "brille", 6);
  add_iter(d_iter, "bord", 4);
  add_iter(d_iter, "bordeau", 7);
  add_iter(d_iter, "bateau", 6);
  printf("\n");
  printf("d_iter contient:\n");
  print_dico(d_iter);

  dico d_rec=create_dico();
  add_rec(d_rec, "ours", 4);
  add_rec(d_rec, "ourse", 5);
  add_rec(d_rec, "ourson", 6);
  add_rec(d_rec, "oursonne", 8);
  printf("\n");
  printf("d_rec contient:\n");
  print_dico(d_rec);

  printf("\n");
  printf("On teste l'égalité: %d \n",equals(d_iter,d_rec));
  printf("\n");

  puts("On complète le dictionnaire d_rec");
  add_rec(d_rec, "brule", 5);
  add_rec(d_rec, "brille", 6);
  add_rec(d_rec, "bord", 4);
  add_rec(d_rec, "bordeau", 7);
  add_rec(d_rec, "bateau", 6);
  printf("\n");
  printf("d_iter contient:\n");
  print_dico(d_iter);
  printf("\n");
  printf("d_rec contient:\n");
  print_dico(d_rec);

  printf("\n");
  printf("On teste l'égalité: %d \n",equals(d_iter,d_rec));
  printf("\n");


  puts("On retire ours dans les 2 avec rec/iter");
  remove_rec(d_rec,"ours",4);
  remove_iter(d_iter,"ours",4);

  printf("d_iter contient:\n");
  print_dico(d_iter);
  printf("\n");

  printf("d_rec contient:\n");
  print_dico(d_rec);
  printf("\n");

  printf("On reteste l'égalité: %d \n",equals(d_iter,d_rec));
  printf("\n");


  puts("On retire brille uniquement dans d_iter");
  remove_iter(d_iter,"brille",6);

  printf("d_iter contient:\n");
  print_dico(d_iter);
  printf("\n");

  printf("d_rec contient:\n");
  print_dico(d_rec);
  printf("\n");

  printf("On reteste l'égalité: %d \n",equals(d_iter,d_rec));
  printf("\n");

  puts("Destuction des dictionnaires");
  destroy_dico(&d_iter);
  destroy_dico(&d_rec);
}
