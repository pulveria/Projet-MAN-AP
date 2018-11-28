#include "dico.c"

int main(){

    puts("Creation d'un dictionnaire vide");
    dico d=create_dico();
    printf("\n");

    puts("On ajoute dans le dictionnaire: {ours, ourse, ourson, oursonne, brule, ours, brille, ours, bateau, bord, bordeau}");
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

    printf("Dans le dicitonnaire, il y a: \n");
    print_dico(d);
    printf("\n");

    puts("On retire (rec) dans le dictionnaire: {ours, ourse, ourson, oursonne, brule, ours, brille, ours, bateau, bord, bordeau}");

    printf("On retire ours \n");
    remove_rec(d,"ours",4);
    print_prefixe(d);
    printf("\n");

    printf("On retire help \n");
    remove_rec(d,"help",4);
    print_prefixe(d);
    printf("\n");

    printf("On retire oursonne \n");
    remove_rec(d,"oursonne",8);
    print_prefixe(d);
    printf("\n");

    printf("On retire ourse \n");
    remove_rec(d,"ourse",5);
    print_prefixe(d);
    printf("\n");

    printf("On retire ourson \n");
    remove_rec(d,"ourson",6);
    print_prefixe(d);
    printf("\n");

    printf("On retire bordeau \n");
    remove_rec(d,"bordeau",7);
    print_prefixe(d);
    printf("\n");

    puts("Ce qu'il reste à la fin:");
    print_dico(d);
    printf("\n");

    puts("Destuction du dictionnaire");
    destroy_dico(&d);
}
