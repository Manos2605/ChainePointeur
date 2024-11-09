#include <iostream>
#include <string>
#include <cstdlib>
#include "header/exercices.h"

int main(){
    while (true){
        std::cout << "Menu : " << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "1. Longueur d'une chaine de caractere" << std::endl;
        std::cout << "2. Copie de chaine de caracteres" << std::endl;
        std::cout << "3. Concatenation de chaine" << std::endl;
        std::cout << "4. Comparaion de chaine" << std::endl;
        std::cout << "5. Recherche de caractere" << std::endl;
        std::cout << "6. Inversion de chaine" << std::endl;
        std::cout << "7. Conversion majuscule/minuscule" << std::endl;
        std::cout << "8. Recherche d'un mot dans une phrase" << std::endl;
        std::cout << "9. Extraction  de sous-chaine" << std::endl;
        std::cout << "10. Suppréssion de caractere" << std::endl;
        std::cout << "11. Compter les mots dans phrase" << std::endl;

        int choix;
        std::cout << "Choisissez un exercice : ";
        std::cin >> choix;

        if(choix == 0){
            break;
        }

        // Nettoyage de la console.
        #ifdef _WIN32
            system("CLS");
        #else
            system("clear");
        #endif

        if(choix == 1){
            std::cout << "1. Longueur  d'une chaine de caractere" << std::endl;
            std::string chaine;
            std::cout << "Entrez une chaine de caractere : ";
            std::cin >> chaine;
            std::cout << "La longueur de la chaine est : " << longueur(chaine.c_str()) << std::endl; // c_str() pour convertir rn une constante
        }

        if(choix == 2){
            std::cout << "2. Copie de chaine de caracteres" << std::endl;
            std::string source;
            std::cout << "Entrez une chaine de caractere : ";
            std::cin >> source;
            char dest2[longueur(source.c_str())];
            copie(dest2, source.c_str());
            std::cout << "Texte copié : " << source << std::endl;
            std::cout << "La copie de la chaine est : " << dest2 << std::endl;
        }

        if(choix == 3){
            std::cout << "3. Concatenation de chaine" << std::endl;
            std::string chaine1, chaine2;
            std::cout << "Entrez une premiere chaine de caractere : ";
            std::cin >> chaine1;
            std::cout << "Entrez une seconde chaine de caractere : ";
            std::cin >> chaine2;
            char dest3[longueur(chaine1.c_str()) + longueur(chaine2.c_str())];
            copie(dest3, chaine1.c_str());
            concatene(dest3, chaine2.c_str());
            std::cout << "La concatenation des chaines est : " << dest3 << std::endl;
        }

        if(choix == 4){
            std::cout << "4. Comparaion de chaine" << std::endl;
            std::string a, b;
            std::cout << "Entrez une premiere chaine de caractere : ";
            std::cin >> a;
            std::cout << "Entrez une seconde chaine de caractere : ";
            std::cin >> b;
            int test = compare(a.c_str(), b.c_str());
            if(test == 0){
                std::cout << "Les chaines sont égales." << std::endl;
            }else if(test > 0){
                std::cout << "La premiere chaine est plus grande que la seconde." << std::endl;
            }else{
                std::cout << "La seconde chaine est plus grande que la premiere." << std::endl;
            }
        }

        if(choix==5){
            std::cout << "5. Recherche de caractere" << std::endl;
            std::string chaine;
            char caractere;
            std::cout << "Entrez une chaine de caractere : ";
            std::cin >> chaine;
            std::cout << "Entrez un caractere : ";
            std::cin >> caractere;
            char* indice = cherche_char(chaine.c_str(), caractere);
            if(indice != NULL){
                std::cout << "Le caractere est trouvé à l'adresse mémoire : " << &indice << std::endl;
            }else{
                std::cout << "Le caractere n'est pas trouvé dans la chaine." << std::endl;
            }
        }

        if(choix == 6){
            std::cout << "6. Inversion de chaine" << std::endl;
            std::string source;
            std::cout << "Entrez une chaine de caractere : ";
            std::cin >> source;
            char chaine[longueur(source.c_str())];
            copie(chaine, source.c_str()); 
            inverse(chaine);
            std::cout << "La chaine inversée est : " << chaine << std::endl;
        }

        if(choix == 7){
            std::cout << "7. Conversion majuscule/minuscule" << std::endl;
            int choice;
            std::cout << "1. Conversion minuscule à majuscule" << std::endl;
            std::cout << "2. Conversion majuscule à minuscule" << std::endl;

            std::cout << "Choisissez votre conversion : ";
            std::cin >> choice;

            // Nettoyage de la console.
            #ifdef _WIN32
                system("CLS");
            #else
                system("clear");
            #endif

            if(choice == 1){
                std::string source;
                std::cout << "Entrez une chaine de caractere : ";
                std::cin >> source;
                char chaine[longueur(source.c_str())];
                copie(chaine, source.c_str());
                to_upper(chaine);
                std::cout << "La chaine en majuscule est : " << chaine << std::endl;
            }

            if(choice == 2){
                std::string source;
                std::cout << "Entrez une chaine de caractere : ";
                std::cin >> source;
                char chaine[longueur(source.c_str())];
                copie(chaine, source.c_str());
                to_lower(chaine);
                std::cout << "La chaine en minuscule est : " << chaine << std::endl;
            }
        }

        if(choix == 8){
            std::cout << "8. Recherche d'un mot dans une phrase" << std::endl;
            std::string phrase, mot;
            std::cout << "Entrez une phrase : ";
            std::cin.ignore();
            std::getline(std::cin, phrase);
            std::cout << "Entrez le mot à charcher : ";
            std::cin >> mot;
            char *position = cherche_mot(phrase.c_str(), mot.c_str());
            if(position!= NULL){
                std::cout << "Le mot est trouvé à la position : " << position << std::endl;
            }else{
                std::cout << "Le mot n'est pas trouvé dans la phrase." << std::endl;
            }
        }

        if(choix == 9){
            std::cout << "9. Extraction  de sous-chaine" << std::endl;
            std::string phrase;
            int debut, longueur;
            std::cout << "Entrez une phrase : ";
            std::cin >> phrase;
            std::getline(std::cin, phrase); // récuperer un ensemble de chaine 
            std::cout << "Entrez la position de début : ";
            std::cin >> debut;
            std::cout << "Entrez la longueur du segment : ";
            std::cin >> longueur;
            char dest[longueur];
            sous_chaine(phrase.c_str(), dest, debut, longueur);
            std::cout << "Le segment est : " << dest << std::endl;
        }

        if(choix == 10){
            std::cout << "10. Suppréssion de caractere" << std::endl;
            std::string source;
            char caractere;
            std::cout << "Entrez une chaine de caractere : ";
            std::cin >> source;
            std::cout << "Entrez le caractere à supprimer : ";
            std::cin >> caractere;
            char chaine[longueur(source.c_str())];
            copie(chaine, source.c_str()); 
            supprime_caractere(chaine, caractere);
            std::cout << "la nom de chaine est : " << chaine << std::endl;
        }

        if(choix == 11){
            std::cout << "11. Compter les mots dans phrase" << std::endl;
            std::string phrase;
            std::cout << "Entrez une phrase : ";
            std::cin.ignore();
            std::getline(std::cin, phrase);
            int nombre_mots = compte_mots(phrase.c_str());
            std::cout << "Il y a " << nombre_mots << " mots dans la phrase." << std::endl;
        }

        #ifdef _WIN32
            system("pause");
        #else
            system("read -p 'Appuyez sur une touche pour continuer...' var");
        #endif

        // Nettoyage de la console.
        #ifdef _WIN32
            system("CLS");
        #else
            system("clear");
        #endif
    }

    return 0;
}