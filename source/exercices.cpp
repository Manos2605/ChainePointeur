#include "../header/exercices.h"
#include <iostream>

int longueur(const char* chaine){
    int length = 0;
    while (chaine[length]!= '\0') {
        length++;
    }
    
    return length;
}

void copie(char* dest, const char* source) {
    int i;
    for (i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0'; 
}

void concatene(char* dest, const char* source) {
   int i = 0;
    // Aller jusqu'à la dernuère lettre de destination
    while (dest[i] != '\0') {
        i++;
    }

    // Ajouter à la suite de dest, les lettre de source
    for (int j = 0; source[j] != '\0'; j++, i++) {
        dest[i] = source[j];
    }
    dest[i] = '\0';
}

int compare(const char* chaine1, const char* chaine2){
    int test = 0;
    int i = 0;
    while (chaine1[i] != '\0' && chaine2[i] != '\0') {
        if (chaine1[i]!= chaine2[i]) {
            test = 0;
            break;
        }
    
        i++;
    }

    if (chaine1[i] < chaine2[i]) test--;
    if (chaine1[i] > chaine2[i]) test++;

    return test;
}

char* cherche_char(const char* chaine, char caractere) {
    int i = 0;
    while (chaine[i] != '\0') {
        if (chaine[i] == caractere) {
            // utilise un cast de const char* en char* comme la fonction renvoie un char*
            return (char*)&chaine[i];
        }
        i++;
    }
    return NULL;
}

void inverse(char* chaine) {
    int length = longueur(chaine);
    char invers;
    for (int i = 0; i < length / 2; i++) {
        invers = chaine[i];
        chaine[i] = chaine[length - 1 - i];
        chaine[length - 1 - i] = invers;
    }
}

// La différence entre un caractère minuscule et son équivalent majuscule est de 32
void to_upper(char* chaine){
    int i = 0;
    while (chaine[i]!= '\0') {
        if (chaine[i] >= 'a' && chaine[i] <= 'z') {
            chaine[i] -= 32;
        }
        i++;
    }
}
void to_lower(char* chaine){
    int i = 0;
    while (chaine[i]!= '\0') {
        if (chaine[i] >= 'A' && chaine[i] <= 'Z') {
            chaine[i] += 32;
        }
        i++;
    }
}

char * cherche_mot(const char* phrase, const char* mot){
    int length_mot = longueur(mot);
    int i = 0;
    while (phrase[i]!= '\0') {
        if (phrase[i] == mot[0]) {
            int j = 1;
            while (mot[j]!= '\0' && phrase[i+j]!= '\0' && phrase[i+j] == mot[j]) {
                j++;
            }
            if (mot[j] == '\0') {
                return (char*)&phrase[i];
            }
        }
        i++;
    }

    return NULL;
}

void sous_chaine(const char* source, char* dest, int debut, int longueur){
    int i = 0;
    int j = debut;
    while (j < debut + longueur + 1 && source[j]!= '\0') {
        dest[i] = source[j - 2];
        i++;
        j++;
    }
    dest[i] = '\0';
}

void supprime_caractere(char* chaine, char caractere){
    int i = 0, j = 0;
    while (chaine[i] != '\0') {
        if (chaine[i] != caractere) {
            chaine[j] = chaine[i];
            j++;
        }
        i++;
    }

    chaine[j] = '\0';
}

int compte_mots(const char* phrase){
    int count = 0;
    int i = 0;
    while (phrase[i]!= '\0') {
        if (phrase[i] == ' ') {
            count++;
        }
        i++;
    }

    return count + 1;
}