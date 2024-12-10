#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
//pour les fleches
#define UP_ARROW 1
#define DOWN_ARROW 2
#define ENTER_KEY 3
// Définition des couleurs
#define ROUGE "\x1b[31m"
#define VERT "\x1b[32m"
#define BLEU "\x1b[34m"
#define JAUNE "\x1b[33m"
#define RESET "\x1b[0m"
#define RESET   "\x1b[0m"
#define BOLD    "\x1b[1m"
#define BLUE    "\x1b[34m"
#define GREEN   "\x1b[32m"
#define RED     "\x1b[31m"
#define YELLOW  "\x1b[33m"
#define CYAN    "\x1b[36m"
#define MAGENTA "\x1b[35m"
#define MAX_LIGNE 200
#define BLEU "\033[34m"
#define JAUNE "\033[33m"
#define VERT "\033[32m"
#define ROUGE "\033[31m"
#define RESET "\033[0m"
#define ROUGE "\x1b[31m"
#define VERT "\x1b[32m"
#define BLEU "\x1b[34m"
#define JAUNE "\x1b[33m"
#define RESET "\x1b[0m"
#define GRIS "\x1b[37m"


char nomMedicament[100];
char maniereUtilisation[500];
int joursParMois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char ligne[256];
int jour_fichier, mois_fichier, annee_fichier;
char nom_patient[50];
int rendezvous_trouve = 0;






typedef struct {
    int id;
    char nom[50];
    int age;
    char sexe[10];
    char adresse[100];
    char telephone[20];
    char email[50];
    char traitement[100];
    char historique[200];
    int date_naissance;
    int prenom;
} Patient;


typedef struct {
    char id[10];
    char mot_de_passe[20];
    char nom[100];
    char prenom[100];
    char date_naissance[20];
    char adresse[200];
    char telephone[20];
} Patient1;
//zouz stuct patient khater wa7da chyesta3mlha l medecin w lokhra e secretaire wel patient(keef ya3ml compte)
//(wa7da fiha les information de base w lokhra les informations specifiques )











void saisir_patientSECPOURDOC(Patient *p) {

    printf("\n%s=====================================================%s\n", CYAN, RESET);
    printf("%s        Saisie des informations du patient%s\n", GREEN, RESET);
    printf("%s=====================================================%s\n", CYAN, RESET);

    // Saisie de l'ID
    printf("\n%s[1] Entrez l'ID du patient (uniquement des chiffres) : %s", BLUE, RESET);
    while (scanf("%d", &p->id) != 1) {
        printf("%sVeuillez entrer un ID valide (uniquement des chiffres) : %s", RED, RESET);
        while (getchar() != '\n'); // Nettoyer le buffer
    }

    // Saisie du nom
    printf("\n%s[2] Entrez le nom du patient : %s", BLUE, RESET);
    while (1) {
        if (scanf("%s", p->nom) == 1) break;
        printf("%sVeuillez entrer un nom valide (pas de caractères spéciaux) : %s", RED, RESET);
        while (getchar() != '\n'); // Nettoyer le buffer
    }

    // Saisie de l'âge
    printf("\n%s[3] Entrez l'âge du patient : %s", BLUE, RESET);
    while (scanf("%d", &p->age) != 1 || p->age < 0 || p->age > 120) {
        printf("%sVeuillez entrer un âge valide (entre 0 et 120) : %s", RED, RESET);
        while (getchar() != '\n'); // Nettoyer le buffer
    }

    // Saisie du sexe
    printf("\n%s[4] Entrez le sexe du patient (Homme/Femme) : %s", BLUE, RESET);
    while (1) {
        if (scanf("%s", p->sexe) == 1 && (strcmp(p->sexe, "Homme") == 0 || strcmp(p->sexe, "Femme") == 0)) break;
        printf("%sVeuillez entrer un sexe valide (Homme/Femme) : %s", RED, RESET);
        while (getchar() != '\n'); // Nettoyer le buffer
    }

    // Saisie de l'adresse
    printf("\n%s[5] Entrez l'adresse du patient : %s", BLUE, RESET);
    while (1) {
        if (scanf("%s", p->adresse) == 1) break;
        printf("%sVeuillez entrer une adresse valide : %s", RED, RESET);
        while (getchar() != '\n'); // Nettoyer le buffer
    }

    // Saisie du numéro de téléphone
    printf("\n%s[6] Entrez le numéro de téléphone du patient (ex: 0123456789) : %s", BLUE, RESET);
    while (1) {
        if (scanf("%s", p->telephone) == 1 && strlen(p->telephone) == 10) break;
        printf("%sVeuillez entrer un numéro de téléphone valide (10 chiffres) : %s", RED, RESET);
        while (getchar() != '\n'); // Nettoyer le buffer
    }

    // Saisie de l'email
    printf("\n%s[7] Entrez l'email du patient : %s", BLUE, RESET);
    while (1) {
        if (scanf("%s", p->email) == 1 && strchr(p->email, '@') != NULL) break;
        printf("%sVeuillez entrer un email valide : %s", RED, RESET);
        while (getchar() != '\n'); // Nettoyer le buffer
    }

    // Confirmation de la saisie avec un motif et une couleur
    printf("\n%s=====================================================%s\n", CYAN, RESET);
    printf("%sLes informations du patient ont été saisies avec succès !%s\n", GREEN, RESET);
    printf("%s=====================================================%s\n", CYAN, RESET);

    printf("Appuyez sur Entrée pour continuer...");
    getchar();  // Consomme le '\n' restant dans le buffer
    getchar();  // Attend que l'utilisateur appuie sur Entrée

}

//hedhom t9ayadhom e secretaire







//hedhom yzeedhom e tbib ba3d


// Fonction pour capturer les flèches et la touche Entrée
int getKeyPress() {
    int ch = _getch();
    if (ch == 0 || ch == 224) { // Touche spéciale
        switch (_getch()) {
            case 72: return UP_ARROW;    // Flèche haut
            case 80: return DOWN_ARROW;  // Flèche bas
        }
    }
    if (ch == 13) return ENTER_KEY; // Touche Entrée
    return 0;
}

// Fonction pour afficher le menu avec sélection dynamique
int choisir_operation() {
    const char* operations[] = {
        "0.Consultation initiale",
        "1.Détartrage (Nettoyage des dents)",
        "2.Blanchiment des dents",
        "3.Plombage (Obturation dentaire)",
        "4.Couronne dentaire",
        "5.Canal Radiculaire (Traitement de canal)",
        "6.Extraction dentaire",
        "7.Implants dentaires",
        "8.Prothèses dentaires",
        "9.Facettes dentaires",
        "10.Chirurgie parodontale",
        "11.Traitement des gencives",
        "12.Orthodontie (Appareils dentaires)",
        "13.Chirurgie buccale",
        "14.Radiographie dentaire",
        "15.Greffe osseuse",
        "16.Sinus Lift",
        "17.Chirurgie orthognathique",
        "18.Invisalign",
        "19.Extraction de dents de sagesse"
    };

    int numOperations = sizeof(operations) / sizeof(operations[0]);
    int selected = 0;  // Initialisation de la sélection
    int key;

    // Affichage du menu avec sélection dynamique
    while (1) {
        // Clear screen ou autre méthode selon votre système
        system("cls");  // Ou utilisez 'clear' si sur un système Unix

        printf("L'opération dentaire faite est :\n\n");

        for (int i = 0; i < numOperations; i++) {
            if (i == selected) {
                // Utilisation d'une couleur différente pour la sélection (si nécessaire)
                printf(" -> %s\n", operations[i]);
            } else {
                printf("    %s\n", operations[i]);
            }
        }

        key = getKeyPress();  // Capturer la touche

        if (key == UP_ARROW) {
            selected = (selected - 1 + numOperations) % numOperations;  // Navigation circulaire
        } else if (key == DOWN_ARROW) {
            selected = (selected + 1) % numOperations;
        } else if (key == ENTER_KEY) {
            break;  // L'utilisateur a validé son choix
        }
    }

    return selected + 1;  // Retourne le choix sous forme d'un nombre (1-20)
}






float obtenir_prix(int choix) {
    //les prix sont confirmées par un dentiste
    switch (choix) {
        case 1: return 60.0;
        case 2: return 85.0;
        case 3: return 250.0;
        case 4: return 120.0;
        case 5: return 400.0;
        case 6: return 200.0;
        case 7: return 100.0;
        case 8: return 1400.0;
        case 9: return 550.0;
        case 10: return 450.0;
        case 11: return 300.0;
        case 12: return 225.0;
        case 13: return 2000.0;
        case 14: return 450.0;
        case 15: return 65.0;
        case 16: return 750.0;
        case 17: return 1250.0;
        case 18: return 3500.0;
        case 19: return 3500.0;
        case 20: return 200.0;
        default: return 0.0;
    }
}
//kol patient yet9ayed fi fiche b esmou

void enregistrer_patient_dans_fichier(const Patient *p) {

        char nom_fichier[100];
        snprintf(nom_fichier, sizeof(nom_fichier), "%s.txt", p->nom);
//bech k yabda famma espace tbadlou-
        for (int i = 0; nom_fichier[i] != '\0'; i++) {
            if (nom_fichier[i] == ' ') {
                nom_fichier[i] = '_';
            }
        }

        FILE *fichier = fopen(nom_fichier, "w");
        if (fichier == NULL) {
            printf("Erreur : impossible d'ouvrir le fichier %s\n", nom_fichier);
            return;
        }

        fprintf(fichier, "ID: %d\nNom: %s\nAge: %d\nSexe: %s\nAdresse: %s\nTelephone: %s\nEmail:%s\n",
                p->id, p->nom, p->age, p->sexe, p->adresse, p->telephone, p->email);
        fprintf(fichier, "----------------------------------------\n");
        fclose(fichier);

        printf("Fiche du patient enregistrée dans le fichier : %s\n", nom_fichier);
    }

//affichage te3 l fiche(l tbib)


void afficher_fiche_patient() {
    char nom[50];
    char nom_fichier[100];

    // Demande du nom du patient
    printf("Entrez le nom du patient pour afficher sa fiche : ");
    scanf("%s", nom);

    // Créer le nom du fichier à partir du nom du patient
    snprintf(nom_fichier, sizeof(nom_fichier), "%s.txt", nom);

    // Remplacer les espaces par des underscores (_)
    for (int i = 0; nom_fichier[i] != '\0'; i++) {
        if (nom_fichier[i] == ' ') {
            nom_fichier[i] = '_';
        }
    }

    // Ouvrir le fichier correspondant
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("DESOLEE, le patient '%s' n'existe pas :(  Veuillez l'enregistrer d'abord !!\n", nom);
        return;
    }

    // Afficher la fiche du patient
    printf("\n--- Fiche du patient : %s ---\n", nom);
    char ligne[256];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf("%s", ligne);
    }
    printf("----------------------------------------\n");
    fclose(fichier);

    // Ajouter une pause pour que l'utilisateur puisse lire la fiche avant de revenir au menu
    printf("\nAppuyez sur une touche pour revenir au menu...\n");
    getchar();  // Cette ligne attend que l'utilisateur appuie sur une touche (pour éviter de quitter immédiatement)
    getchar();  // Utilisé pour consommer le caractère de nouvelle ligne restant après l'appel de scanf
}

void affichermafiche() {
    char nom[50];
    char nom_fichier[100];

    // Demande du nom du patient
    printf("SALUT § POUVEZ VOUS ENTRER VOTRE NOM SVP : ");
    scanf("%s", nom);

    // Créer le nom du fichier à partir du nom du patient
    snprintf(nom_fichier, sizeof(nom_fichier), "%s.txt", nom);

    // Remplacer les espaces par des underscores (_)
    for (int i = 0; nom_fichier[i] != '\0'; i++) {
        if (nom_fichier[i] == ' ') {
            nom_fichier[i] = '_';
        }
    }

    // Ouvrir le fichier correspondant
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("DESOLEE, le patient '%s' n'existe pas :(  Veuillez l'enregistrer d'abord !!\n", nom);
        return;
    }

    // Afficher la fiche du patient
    printf("\n---  VOTRE FiCHE  : %s ---\n", nom);
    char ligne[256];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf("%s", ligne);
    }
    printf("----------------------------------------\n");
    fclose(fichier);

    // Ajouter une pause pour que l'utilisateur puisse lire la fiche avant de revenir au menu
    printf("\nAppuyez sur une touche pour revenir au menu...\n");
    getchar();  // Cette ligne attend que l'utilisateur appuie sur une touche (pour éviter de quitter immédiatement)
    getchar();  // Utilisé pour consommer le caractère de nouvelle ligne restant après l'appel de scanf
}





//tbib y9ayed kol marra dwe wel maniere d'utilisation mte3ou
//bech k ya3ti dwe ll patient wel patient yansa kifeh 9alou tbib yochrbou
//juste y7el l app w yekteb esmou well app heya l t9ollo kol chay(yab9ach yemrej f tbib)
//kol dwe m9ayed f fiche b esmou



// Structure pour représenter un médicament dans la liste chaînée
typedef struct Medicament {
    char nom[100];
    char maniereUtilisation[200];
    struct Medicament *suivant;  // Pointeur vers le médicament suivant
} Medicament;

// Fonction pour ajouter un médicament à la liste chaînée
// Fonction pour ajouter un médicament à la liste chaînée
void ajouterMedicament(Medicament **tete, const char *nomFichier) {
    // Déclaration des variables pour stocker les informations
    char nomMedicament[100];
    char maniereUtilisation[200];

    // Demander le nom du médicament à l'utilisateur
    printf("Entrez le nom du médicament :  ");
    fgets(nomMedicament, sizeof(nomMedicament), stdin);
    nomMedicament[strcspn(nomMedicament, "\n")] = '\0';  // Supprimer le '\n' à la fin

    // Demander la manière d'utilisation à l'utilisateur
    printf("Entrez la manière d'utilisation : ");
    fgets(maniereUtilisation, sizeof(maniereUtilisation), stdin);
    maniereUtilisation[strcspn(maniereUtilisation, "\n")] = '\0';  // Supprimer le '\n' à la fin

    // Écrire les informations dans le fichier
    FILE *fichier = fopen(nomFichier, "a");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    fprintf(fichier, "%s :\n", nomMedicament);
    fprintf(fichier, "Manière d'utilisation : %s\n\n", maniereUtilisation);
    fclose(fichier);

    // Ajouter le médicament à la liste chaînée
    Medicament *nouveauMedicament = (Medicament *)malloc(sizeof(Medicament));
    if (nouveauMedicament == NULL) {
        perror("Erreur d'allocation de mémoire");
        exit(EXIT_FAILURE);
    }

    // Remplir les informations du médicament
    strcpy(nouveauMedicament->nom, nomMedicament);
    strcpy(nouveauMedicament->maniereUtilisation, maniereUtilisation);
    nouveauMedicament->suivant = NULL;

    // Ajouter à la fin de la liste chaînée
    if (*tete == NULL) {
        *tete = nouveauMedicament;  // Si la liste est vide, le nouveau médicament devient la tête
    } else {
        Medicament *temp = *tete;
        while (temp->suivant != NULL) {
            temp = temp->suivant;  // Parcourir jusqu'à la fin
        }
        temp->suivant = nouveauMedicament;  // Ajouter à la fin de la liste
    }

    // Message de confirmation
    printf("Le médicament '%s' a été ajouté au fichier.\n", nomMedicament);
    printf("Appuyez sur Entrée pour continuer...");
    getchar();  // Consomme le '\n' restant dans le buffer
}

// Fonction pour afficher un médicament et sa manière d'utilisation
void afficherMedicament(Medicament *tete, const char *nomFichier) {
    char nomMedicament[100];
    int trouve = 0;

    // Affichage avec couleur et motif
    printf("\033[34m\n--- Recherche du médicament ---\n\033[0m");
    printf("\033[33mEntrez le nom du médicament à rechercher : \033[0m");
    fgets(nomMedicament, sizeof(nomMedicament), stdin);
    nomMedicament[strcspn(nomMedicament, "\n")] = '\0';  // Supprimer le '\n' à la fin

    // Recherche du médicament dans la liste chaînée
    Medicament *temp = tete;
    while (temp != NULL) {
        if (strcmp(temp->nom, nomMedicament) == 0) {
            printf("\033[32m%s\033[0m", temp->nom);  // Affichage du nom du médicament en vert
            printf("\nManière d'utilisation : %s\n", temp->maniereUtilisation);
            trouve = 1;
            break;
        }
        temp = temp->suivant;
    }

    // Si médicament non trouvé dans la liste chaînée
    if (!trouve) {
        printf("\033[31mMédicament '%s' introuvable dans la liste chaînée.\n\033[0m", nomMedicament);
    }

    // Affichage avec couleur et motif
    printf("\033[33m----------------------------------------\n\033[0m");
    printf("Appuyez sur Entrée pour continuer...");
    getchar();  // Consomme le '\n' restant dans le buffer
}
Medicament *tete = NULL;

//keef tbib ya3ti dwe ll patient yet7atlou fel fiche mte3ou chnowa dwe l ye5ou fih
void associer_medicament_patient(const char *nomFichierPatient) {
    char nomMedicament[100];
    printf("Entrez le nom du médicament à associer : ");
    scanf(" %[^\n]", nomMedicament);

    FILE *fichier = fopen(nomFichierPatient, "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture de la fiche du patient.\n");
        return;
    }

    fprintf(fichier, "Médicament associé : %s\n", nomMedicament);
    fclose(fichier);

    printf("Le médicament '%s' a été ajouté à la fiche du patient '%s'.\n", nomMedicament, nomFichierPatient);
}
//enregistrement des symptomes par le docteur
void enregistrerSymptomes(const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    char symptome[100];
    char continuer = 'o';
    printf(" | BIENVENU DANS VOTRE ESPACE LIBRE | \n");
    while (continuer == 'o' || continuer == 'O') {

        printf("******************************************\n");
        scanf(" %[^\n]", symptome);
        fprintf(fichier, "%s\n", symptome);
        printf("Voulez-vous ajouter une autre chose  ? (o/n) : ");
        scanf(" %c", &continuer);
    }
    fclose(fichier);
}

// BECH L PATIENT W SECRETAIRE W TBIB YNAJMOU YETWASLOU M3A B3ADHHOM


#define MAX_REMARQUES 10000

// Structure pour une remarque

#define MAX_REMARQUES 100

typedef struct {
    char message[500];
} Remarque;

// Pile (LIFO)
typedef struct {
    Remarque elements[MAX_REMARQUES];
    int top;
} Pile;

// Déclaration d'une pile globale
Pile pile;

// Initialiser la pile
void initialiser_pile() {
    pile.top = -1;  // Pile vide au départ
}

// Ajouter une remarque à la pile
void empiler(const char *remarque) {
    if (pile.top < MAX_REMARQUES - 1) {
        pile.top++;
        strncpy(pile.elements[pile.top].message, remarque, sizeof(pile.elements[pile.top].message));
        printf("Remarque ajoutée à la pile : %s\n", remarque);
    } else {
        printf("Erreur : Pile pleine. Impossible d'ajouter la remarque.\n");
    }
}

// Fonction pour ajouter une remarque
void ajouter_remarque() {
    char remarque[500];

    printf("Entrez votre message : ");
    getchar(); // Consomme un éventuel '\n' résiduel

    fgets(remarque, sizeof(remarque), stdin);
    remarque[strcspn(remarque, "\n")] = 0;  // Supprime le '\n' final

    empiler(remarque); // Ajoute la remarque à la pile

    // Enregistrer dans un fichier
    FILE *fichier = fopen("remarques.txt", "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fprintf(fichier, "Message : %s\n", remarque);
    fclose(fichier);

    printf("Remarque enregistrée avec succès.\n");
}




// Définir des codes de couleur ANSI


// Fonction pour afficher les remarques avec un cadre coloré
void afficher_remarques() {
    FILE *fichier = fopen("remarques.txt", "r");
    if (fichier == NULL) {
        printf(ROUGE "Aucun message à afficher.\n" RESET);
        printf("Appuyez sur Entrée pour continuer...");
        getchar();  // Consomme le '\n' restant dans le buffer
        getchar();  // Attend que l'utilisateur appuie sur Entrée

        return;
    }

    char ligne[500];

    // Affichage avec motif et couleurs
    printf(BLEU "\n=========================================\n" RESET);
    printf(BLEU "|           --- DISCUSSION ---         |\n" RESET);
    printf(BLEU "=========================================\n" RESET);

    // Lire et afficher chaque ligne du fichier (les remarques)
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf(GRIS "%s" RESET, ligne);  // Affichage des remarques en gris
    }

    // Affichage du cadre de fin
    printf(BLEU "=========================================\n" RESET);
    printf("Appuyez sur Entrée pour continuer...");
    getchar();  // Consomme le '\n' restant dans le buffer
    getchar();  // Attend que l'utilisateur appuie sur Entrée


    fclose(fichier);
}


//keef tbib wela secretaire yabdew 7achethom b fiche te3 patient
//ylawjou 3lih b esmou



void ajouter_patient_fichier(Patient1 *patient, const char *nom_fichier) {
    FILE *f = fopen(nom_fichier, "a");
    if (!f) {
        printf("Erreur : impossible d'écrire dans le fichier %s.\n", nom_fichier);
        return;
    }
    fprintf(f, "%s %s %s %s %s %s %s\n",
            patient->id, patient->mot_de_passe,
            patient->nom, patient->prenom,
            patient->date_naissance, patient->adresse,
            patient->telephone);
    fclose(f);
}





// Fonction pour rechercher un patient dans le fichier
void rechercher_patient(Patient1 *patients, int nombre_patients) {
    char nom_patient[100];
    int trouve = 0;

    // Demander le nom du patient à rechercher
    printf("Entrez le nom du patient à rechercher : ");
    fgets(nom_patient, sizeof(nom_patient), stdin);

    // Supprimer le retour à la ligne à la fin de l'entrée utilisateur
    nom_patient[strcspn(nom_patient, "\n")] = 0;

    // Parcourir le tableau de patients et comparer les noms
    for (int i = 0; i < nombre_patients; i++) {
        if (strstr(patients[i].nom, nom_patient) != NULL) {
            printf("Patient trouvé : %s %s, %s, %s\n",
                   patients[i].prenom,
                   patients[i].nom,
                   patients[i].date_naissance,
                   patients[i].telephone);
            printf("Appuyez sur Entrée pour continuer...");
            getchar();  // Consomme le '\n' restant dans le buffer
            getchar();  // Attend que l'utilisateur appuie sur Entrée

            trouve = 1;
            break;
        }
    }

    // Si le patient n'est pas trouvé
    if (!trouve) {
        printf("Patient non trouvé.\n");
        printf("Appuyez sur Entrée pour continuer...");
        getchar();  // Consomme le '\n' restant dans le buffer
        getchar();  // Attend que l'utilisateur appuie sur Entrée

    }
}

//ynajem patient yo8let wela ybadel 7aja donc secretaire tbadalou les info elli tbadlou
//(num tlfn w les info generales)
void modifier_informations_patient() {
    FILE *fichier = fopen("patients.txt", "r+");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier des patients.\n");
        return;
    }

    char ligne[200], nom_patient[100], nouveau_telephone[50];
    int trouvé = 0;

    printf("Entrez le nom du patient à modifier : ");
    getchar();
    fgets(nom_patient, sizeof(nom_patient), stdin);

    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (strstr(ligne, nom_patient) != NULL) {
            printf("Informations actuelles : %s", ligne);
            printf("Entrez le nouveau numéro de téléphone : ");
            fgets(nouveau_telephone, sizeof(nouveau_telephone), stdin);
            fprintf(fichier, "\n");
            fprintf(fichier, "Nom : %sTéléphone : %s", nom_patient, nouveau_telephone);
            trouvé = 1;
            break;
        }
    }

    if (!trouvé) {
        printf("Patient non trouvé.\n");
        printf("Appuyez sur Entrée pour continuer...");
        getchar();  // Consomme le '\n' restant dans le buffer
        getchar();  // Attend que l'utilisateur appuie sur Entrée

    }

    fclose(fichier);
    if (trouvé) {
        printf("Informations modifiées avec succès.\n");
        printf("Appuyez sur Entrée pour continuer...");
        getchar();  // Consomme le '\n' restant dans le buffer
        getchar();  // Attend que l'utilisateur appuie sur Entrée

    }
}
//keef rendez vous yetbadel nwalli nfasa5 l 9dim

void supprimer_rendezvous() {
    FILE *fichier = fopen("rendezvous.txt", "r");
    if (fichier == NULL) {
        printf("Aucun rendez-vous à supprimer.\n");
        printf("Appuyez sur Entrée pour continuer...");
        getchar();  // Consomme le '\n' restant dans le buffer
        getchar();  // Attend que l'utilisateur appuie sur Entrée

        return;
    }

    char ligne[200];
    int i = 1, choix;
    printf("Liste des rendez-vous :\n");
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf("%d. %s", i++, ligne);
    }
    fclose(fichier);

    printf("Entrez le numéro du rendez-vous à supprimer : ");
    scanf("%d", &choix);


    FILE *temp = fopen("temp.txt", "w");
    fichier = fopen("rendezvous.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour la suppression.\n");
        printf("Appuyez sur Entrée pour continuer...");
        getchar();  // Consomme le '\n' restant dans le buffer
        getchar();  // Attend que l'utilisateur appuie sur Entrée

        return;
    }

    i = 1;
    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (i != choix) {
            fputs(ligne, temp);
        }
        i++;
    }

    fclose(fichier);
    fclose(temp);

    remove("rendezvous.txt");
    rename("temp.txt", "rendezvous.txt");

    printf("Rendez-vous supprimé avec succès.\n");
    printf("Appuyez sur Entrée pour continuer...");
    getchar();  // Consomme le '\n' restant dans le buffer
    getchar();  // Attend que l'utilisateur appuie sur Entrée

}
//hedhi yest7a9ha tbib w secretaire bech ychoufou les rendez vous l mawjoudin

void afficherrendezvous() {
    FILE *fichier = fopen("rendezvous.txt", "r");
    if (fichier == NULL) {
        printf("\033[1;31mAucun rendez-vous à afficher.\033[0m\n");
        printf("Appuyez sur Entrée pour continuer...");
        getchar();  // Consomme le '\n' restant dans le buffer
        getchar();  // Attend que l'utilisateur appuie sur Entrée

        // Texte en rouge pour erreur
        return;
    }

    char ligne[200];

    // Bordure colorée pour le titre
    printf("\033[1;34m--- \033[1;37mRendez-vous programmés \033[1;34m---\033[0m\n");  // Titre en bleu

    // Afficher chaque ligne avec une bordure et un style amélioré
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf("\033[1;32m| \033[0m%s\033[1;32m |\033[0m\n", ligne);  // Texte vert avec bordure
    }

    // Bordure de fin
    printf("\033[1;34m---------------------------\033[0m\n");
    printf("Appuyez sur Entrée pour continuer...");
    getchar();  // Consomme le '\n' restant dans le buffer
    getchar();  // Attend que l'utilisateur appuie sur Entrée

    // Bordure bleu foncé

    fclose(fichier);
}

void ajouter_rendezvous() {
    FILE *fichier = fopen("rendezvous.txt", "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier des rendez-vous.\n");
        return;
    }

    char nom_patient[100], date_rdv[50], heure_rdv[50];
    printf("Entrez le nom du patient : ");
    getchar();
    fgets(nom_patient, sizeof(nom_patient), stdin);

    printf("Entrez la date du rendez-vous (jj/mm/aaaa) : ");
    fgets(date_rdv, sizeof(date_rdv), stdin);

    printf("Entrez l'heure du rendez-vous (hh:mm) : ");
    fgets(heure_rdv, sizeof(heure_rdv), stdin);

    fprintf(fichier, "Patient : %sDate : %sHeure : %s\n", nom_patient, date_rdv, heure_rdv);
    fclose(fichier);

    printf("Rendez-vous ajouté avec succès.\n");
    printf("Appuyez sur Entrée pour continuer...");
    getchar();  // Consomme le '\n' restant dans le buffer
    getchar();  // Attend que l'utilisateur appuie sur Entrée

}

void calculerProchaineDate(int jour, int mois, int annee, int joursAjout, int *jourProchain, int *moisProchain, int *anneeProchain) {
    int joursParMois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    jour += joursAjout;
    while (jour > joursParMois[mois - 1]) {
        jour -= joursParMois[mois - 1];
        mois++;
        if (mois > 12) {
            mois = 1;
            annee++;
        }
    }
    *jourProchain = jour;
    *moisProchain = mois;
    *anneeProchain = annee;
}

//test7a9ha scretaire bech ta3ref date heki tnajem tzeed fiha rendez vous wela la
void afficher_rendezvous_par_date(int jour, int mois, int annee) {
    FILE *fichier = fopen("rendezvous.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier des rendez-vous.\n");
        printf("Appuyez sur Entrée pour continuer...");
        getchar();
        return;
    }

    char ligne[256];
    char nom_patient[100], date_rdv[50], heure_rdv[50];
    int jour_fichier, mois_fichier, annee_fichier;
    int rendezvous_trouve = 0;

    printf("\n--- Rendez-vous pour la date %02d/%02d/%04d ---\n", jour, mois, annee);

    while (fgets(ligne, sizeof(ligne), fichier)) {
        // Lire le nom du patient
        if (sscanf(ligne, "Patient : %[^\n]", nom_patient) == 1) {
            // Lire la date du rendez-vous
            if (fgets(ligne, sizeof(ligne), fichier) &&
                sscanf(ligne, "Date : %d/%d/%d", &jour_fichier, &mois_fichier, &annee_fichier) == 3) {
                // Lire l'heure du rendez-vous
                if (fgets(ligne, sizeof(ligne), fichier) && sscanf(ligne, "Heure : %[^\n]", heure_rdv) == 1) {
                    // Vérifier si la date correspond
                    if (jour_fichier == jour && mois_fichier == mois && annee_fichier == annee) {
                        printf("Nom du patient : %s", nom_patient); // Nom inclut déjà un '\n'
                        printf("Date : %02d/%02d/%04d\n", jour_fichier, mois_fichier, annee_fichier);
                        printf("Heure : %s\n", heure_rdv);
                        rendezvous_trouve = 1;
                    }
                }
                }
        }
    }

    if (!rendezvous_trouve) {
        printf("Aucun rendez-vous trouvé pour cette date.\n");
    }

    printf("----------------------------------------\n");
    printf("Appuyez sur Entrée pour continuer...");
    getchar();
    getchar();
    fclose(fichier);
}



//hedhi li ta3ti adresse w mdp lkol patient bech ye5ou l acces ll fiche te3ou



#define MAX_PATIENTS 1000 // Définir une taille maximale pour le tableau des patients





Patient1 patients[MAX_PATIENTS];
int nombre_patients = 0;
const char *nom_fichier_patients = "patients.txt";


void afficher_rendezvous_patient() {
    FILE *fichier = fopen("rendezvous.txt", "r");
    if (fichier == NULL) {
        printf("Aucun rendez-vous à afficher.\n");
        return;
    }

    char ligne[MAX_LIGNE];
    printf("\n--- Rendez-vous programmés ---\n");
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf("%s", ligne);
    }
    printf("---------------------------\n");
    printf("Appuyez sur Entrée pour continuer...");
    getchar();  // Consomme le '\n' restant dans le buffer
    getchar();  // Attend que l'utilisateur appuie sur Entrée

    fclose(fichier);
}
//patient yab3eth w ya9ra msgs
//k yal9a mochkl fl info generale te3ou ybadalha
void ajouter_remarque_patient() {
    FILE *fichier = fopen("remarques.txt", "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier des remarques.\n");
        return;
    }

    char remarque[MAX_LIGNE];
    printf("Entrez votre message  : ");
    getchar();
    fgets(remarque, sizeof(remarque), stdin);

    fprintf(fichier, " message du patient  : %s\n", remarque);
    fclose(fichier);

    printf("message envoyée avec succès.\n");
}

void lire_remarques_patient() {
    FILE *fichier = fopen("remarques.txt", "r");
    if (fichier == NULL) {
        printf("Aucun message à afficher.\n");
        return;
    }

    char ligne[MAX_LIGNE];
    printf("\n--- discussion ---\n");
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf("%s", ligne);
    }
    printf("-----------------\n");
    fclose(fichier);
}



void modifier_fiche_patient(Patient1 *p) {
    int choix = 1; // Option sélectionnée par défaut
    char key;

    while (1) {
        system("cls");  // Efface l'écran (Windows uniquement)

        // Afficher le menu
        printf("\033[1;34m--- Modifier ma fiche ---\033[0m\n\n");

        for (int i = 1; i <= 3; i++) {
            if (choix == i) {
                printf("\033[1;32m%d. ", i);  // Vert pour l'option sélectionnée
            } else {
                printf("\033[0;37m%d. ", i);  // Blanc pour les autres options
            }

            if (i == 1) {
                printf("Modifier l'adresse\n");
            } else if (i == 2) {
                printf("Modifier le numéro de téléphone\n");
            } else if (i == 3) {
                printf("Retour\n");
            }
        }

        // Capturer la touche pressée
        key = _getch();

        // Détecter les flèches directionnelles
        if (key == -32 || key == 224) {  // Préfixe des flèches sur Windows
            key = _getch();
            if (key == 72 && choix > 1) {  // Flèche haut
                choix--;
            } else if (key == 80 && choix < 3) {  // Flèche bas
                choix++;
            }
        } else if (key == 13) {  // Touche Entrée
            switch (choix) {
                case 1:
                    printf("Entrez la nouvelle adresse : ");
                    getchar();  // Consommer le \n restant
                    fgets(p->adresse, sizeof(p->adresse), stdin);
                    p->adresse[strcspn(p->adresse, "\n")] = '\0';  // Supprimer le \n
                    printf("\033[1;32mAdresse mise à jour avec succès.\033[0m\n");
                    getchar();  // Pause
                    return;  // Sortie après modification
                case 2:
                    printf("Entrez le nouveau numéro de téléphone : ");
                    scanf("%s", p->telephone);
                    printf("\033[1;32mNuméro de téléphone mis à jour avec succès.\033[0m\n");
                    getchar();  // Pause
                    getchar();  // Pause
                    return;  // Sortie après modification
                case 3:
                    return;  // Retour au menu principal
                default:
                    printf("\033[1;31mChoix invalide.\033[0m\n");
            }
        }
    }
}


void modifier_fiche_docteur(const char *nom_patient) {
    // Changer les espaces dans le nom du patient en underscores pour générer le nom du fichier
    char fichier_patient[100];
    snprintf(fichier_patient, sizeof(fichier_patient), "%s.txt", nom_patient);

    // Remplacer les espaces par des underscores
    for (int i = 0; fichier_patient[i] != '\0'; i++) {
        if (fichier_patient[i] == ' ') {
            fichier_patient[i] = '_';
        }
    }

    // Ouvrir le fichier du patient
    FILE *fichier = fopen(fichier_patient, "r+");
    if (fichier == NULL) {
        printf("\033[1;31mErreur : impossible d'ouvrir la fiche du patient %s. Vérifiez que le fichier existe.\033[0m\n", fichier_patient);
        return;
    }

    // Afficher un cadre avec des couleurs pour la fiche actuelle du patient
    printf("\033[1;36m---------------------------------------------------\033[0m\n");
    printf("\033[1;36m          Fiche actuelle du patient %s            \033[0m\n", nom_patient);
    printf("\033[1;36m---------------------------------------------------\033[0m\n");

    char ligne[256];
    int contenu_existe = 0;
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf("\033[0;37m%s\033[0m", ligne);  // Afficher les informations existantes du patient
        contenu_existe = 1; // Indiquer qu'il y a du contenu dans la fiche
    }

    if (!contenu_existe) {
        printf("\033[1;33mLa fiche est vide. Vous pouvez ajouter des informations.\033[0m\n");
    }

    // Se repositionner à la fin du fichier pour ajouter de nouvelles informations
    fseek(fichier, 0, SEEK_END);

    // Demander et saisir les nouvelles informations
    char traitement[100], historique[100];
    printf("\033[1;32m\nEntrez le traitement : \033[0m");
    getchar(); // Vider le buffer avant fgets
    fgets(traitement, sizeof(traitement), stdin);
    traitement[strcspn(traitement, "\n")] = '\0'; // Supprimer le retour à la ligne

    printf("\033[1;32mEntrez l'historique médical : \033[0m");
    fgets(historique, sizeof(historique), stdin);
    historique[strcspn(historique, "\n")] = '\0'; // Supprimer le retour à la ligne

    // Enregistrer les nouvelles informations dans le fichier
    fprintf(fichier, "\033[1;34m\nTraitement : %s\033[0m\n", traitement);
    fprintf(fichier, "\033[1;34mHistorique : %s\033[0m\n", historique);

    // Choisir l'opération à effectuer
    printf("\033[1;33m\nChoisissez une opération :\033[0m\n");
    choisir_operation();

    int choix;
    printf("\033[1;32mVotre choix : \033[0m");
    scanf("%d", &choix);

    float prix = obtenir_prix(choix);
    fprintf(fichier, "\033[1;34mOpération effectuée : %d (Prix : %.2f TND)\033[0m\n", choix, prix);
    fprintf(fichier, "\033[1;36m----------------------------------------\033[0m\n");

    fclose(fichier);

    // Affichage d'un message de confirmation
    printf("\033[1;32m\nLes modifications ont été enregistrées avec succès dans la fiche du patient.\033[0m\n");
}

#ifdef _WIN32

#define CLEAR_SCREEN() system("cls")
#define SET_COLOR(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)
#define RESET_COLOR() SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)
#else
#include <unistd.h>
#define CLEAR_SCREEN() system("clear")
#define SET_COLOR(color) printf("\033[%dm", color)
#define RESET_COLOR() printf("\033[0m")
#endif

#define MAX_PATIENTS 100

void show_DoctorMenu(char* nextScreen);
void show_SecretaryMenu(char* nextScreen);
void show_PatientMenu(char* nextScreen);
// Fonction pour capturer les flèches et Entrée

void clearScreen() {
    system("cls");
}



void showMenu(const char* title, const char* options[], int numOptions, int selected) {
    clearScreen();
    printf(" | %s |\n\n", title);
    for (int i = 0; i < numOptions; i++) {
        if (i == selected) {
            SET_COLOR(11); // Couleur bleue pour la sélection
            printf(" -> %s\n", options[i]);
            RESET_COLOR();
        } else {
            printf("    %s\n", options[i]);
        }
    }
}
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(hConsole, position);
}

// Centrer et afficher un texte
void showCenteredText(const char* text, int row, int screenWidth) {
    int textLength = strlen(text);
    int xPosition = (screenWidth - textLength) / 2;
    setCursorPosition(xPosition, row);
    printf("%s", text);
}

void espace_secretaire() {
    int patient_index;
    int selected = 0; // Option sélectionnée par défaut
    int numOptions = 9; // Nombre total d'options dans le menu
    int key;

    const char* options[] = {
        "Enregistrer un patient",
        "Envoyer un message",
        "Afficher les messages reçus (la discussion)",
        "Ajouter un rendez-vous",
        "Supprimer un rendez-vous",
        "Afficher les rendez-vous pour une date donnée",
        "Afficher toutes les rendez-vous",
        "Afficher fiche patient",
        "RETOUR MENU PRINCIPAL"
    };

    do {
        clearScreen();  // Effacer l'écran avant chaque affichage du menu

        // Obtenir les dimensions de la console
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        int screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        int screenHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        // Afficher le titre centré
        setColor(13); // Couleur rose
        showCenteredText("***************************************", screenHeight / 2 - 3, screenWidth);
        showCenteredText("*          Espace Secrétaire          *", screenHeight / 2 - 2, screenWidth);
        showCenteredText("***************************************", screenHeight / 2 - 1, screenWidth);
        setColor(7); // Réinitialisation

        // Afficher les options avec surbrillance
        for (int i = 0; i < numOptions; i++) {
            if (i == selected) {
                if (i == numOptions - 1) {
                    setColor(12); // Couleur rouge pour "RETOUR MENU PRINCIPAL"
                } else {
                    setColor(10); // Couleur verte pour les autres options
                }
            } else {
                setColor(7); // Couleur par défaut
            }
            setCursorPosition((screenWidth - strlen(options[i]) - 4) / 2, (screenHeight / 2) + i);
            printf("  %s  ", options[i]);
        }
        setColor(7); // Réinitialisation

        // Gestion des touches
        key = getKeyPress();
        if (key == UP_ARROW) {
            selected = (selected - 1 + numOptions) % numOptions; // Navigation vers le haut (cercle)
        } else if (key == DOWN_ARROW) {
            selected = (selected + 1) % numOptions; // Navigation vers le bas (cercle)
        } else if (key == ENTER_KEY) {
            clearScreen(); // Effacer l'écran avant d'exécuter une action
            switch (selected) {
                case 0: {
                    Patient1 new_patient;
                    saisir_patientSECPOURDOC(&new_patient);
                    enregistrer_patient_dans_fichier(&new_patient);
                    break;
                }
                case 1:
                    initialiser_pile();
                    ajouter_remarque();
                    printf("Message envoyé ! Appuyez sur Entrée pour continuer...");
                    getchar();
                    break;
                case 2:
                    afficher_remarques();
                    break;
                case 3:
                    ajouter_rendezvous();
                    break;
                case 4:
                    supprimer_rendezvous();
                    break;
                case 5: {
                    int jour, mois, annee;
                    printf("Entrez la date pour laquelle afficher les rendez-vous (jour mois année) : ");
                    scanf("%d %d %d", &jour, &mois, &annee);
                    afficher_rendezvous_par_date(jour, mois, annee);
                    break;
                }
                case 6:
                    afficher_rendezvous_patient(NULL);
                    break;
                case 7:
                    afficher_fiche_patient();
                    getchar();
                    break;
                case 8:
                    printf("Retour au menu principal...\n");
                    Sleep(2000);
                    return;
                default:
                    printf("Choix invalide, veuillez réessayer.\n");
                    break;
            }
            printf("\nAppuyez sur Entrée pour revenir au menu...");
            getchar();
        }
    } while (1);
}


#include <stdbool.h>



// Codes ANSI pour les couleurs
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

void afficher_mesrendezvous() {
    FILE *fichier = fopen("rendezvous.txt", "r");
    if (fichier == NULL) {
        printf(RED "Aucun rendez-vous à afficher.\n" RESET);
        return;
    }

    char ligne[256];
    char nom_patient[100], nom_patient_fichier[100], date_rdv[50], heure_rdv[50];
    bool hasAppointments = false; // Indique si des rendez-vous pour ce patient ont été trouvés

    // Demander le nom du patient
    printf(YELLOW "Entrez votre nom : " RESET);
    getchar(); // Consomme le caractère '\n' restant
    fgets(nom_patient, sizeof(nom_patient), stdin);

    // Supprimer le '\n' final si présent
    size_t len = strlen(nom_patient);
    if (len > 0 && nom_patient[len - 1] == '\n') {
        nom_patient[len - 1] = '\0';
    }

    printf(BLUE "\n==========================================\n" RESET);
    printf(BOLD "  Rendez-vous pour %s\n" RESET, nom_patient);
    printf(BLUE "==========================================\n" RESET);

    // Lecture et recherche des rendez-vous
    while (fgets(ligne, sizeof(ligne), fichier)) {
        // Lire le nom du patient enregistré
        if (sscanf(ligne, "Patient : %[^\n]", nom_patient_fichier) == 1) {
            // Comparer le nom avec celui entré par l'utilisateur
            if (strcmp(nom_patient_fichier, nom_patient) == 0) {
                // Lire la date du rendez-vous
                if (fgets(ligne, sizeof(ligne), fichier) &&
                    sscanf(ligne, "Date : %[^\n]", date_rdv) == 1) {
                    // Lire l'heure du rendez-vous
                    if (fgets(ligne, sizeof(ligne), fichier) &&
                        sscanf(ligne, "Heure : %[^\n]", heure_rdv) == 1) {
                        // Afficher les détails du rendez-vous
                        printf(GREEN "------------------------------------------\n" RESET);
                        printf(CYAN "Date : " RESET "%s", date_rdv); // Inclut déjà un '\n'
                        printf(CYAN "Heure : " RESET "%s", heure_rdv);
                        hasAppointments = true;
                    }
                }
            }
        }
    }

    if (!hasAppointments) {
        printf(RED "\nAucun rendez-vous trouvé pour %s.\n" RESET, nom_patient);
    }

    printf(BLUE "==========================================\n" RESET);
    printf(YELLOW "Appuyez sur Entrée pour continuer...\n" RESET);
    getchar(); // Attend que l'utilisateur appuie sur Entrée
    fclose(fichier);
}
void libererListeMedicaments(Medicament *listeMedicaments) {
    Medicament *temp;
    while (listeMedicaments != NULL) {
        temp = listeMedicaments;
        listeMedicaments = listeMedicaments->suivant;
        free(temp);
    }
}


void interface_patient(Patient1 *patients, int patient_index) {
    int selected = 0; // Option sélectionnée par défaut
    int numOptions = 7; // Nombre total d'options dans le menu
    int key;

    Patient1 *p = &patients[patient_index];

    const char* options[] = {
        "Afficher ma fiche",
        "Voir mes rendez-vous",
        "Envoyer un message",
        "Voir les messages reçus",
        "Modifier mes informations",
        "Chercher un médicament (manière d'utilisation)",
        "RETOUR MENU PRINCIPAL"
    };

    do {
        clearScreen();  // Effacer l'écran avant d'afficher le menu

        // Obtenir les dimensions de la console
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        int screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        int screenHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        // Afficher le titre centré
        setColor(13); // Couleur rose
        showCenteredText("***************************************", screenHeight / 2 - 3, screenWidth);
        showCenteredText("*         Interface Patient           *", screenHeight / 2 - 2, screenWidth);
        showCenteredText("***************************************", screenHeight / 2 - 1, screenWidth);
        setColor(7); // Réinitialisation

        // Afficher les options avec surbrillance
        for (int i = 0; i < numOptions; i++) {
            if (i == selected) {
                if (i == numOptions - 1) {
                    setColor(12); // Couleur rouge pour "RETOUR MENU PRINCIPAL"
                } else {
                    setColor(10); // Couleur verte pour les autres options
                }
            } else {
                setColor(7); // Couleur par défaut
            }
            setCursorPosition((screenWidth - strlen(options[i]) - 4) / 2, (screenHeight / 2) + i);
            printf("  %s  ", options[i]);
        }
        setColor(7); // Réinitialisation

        // Gestion des touches
        key = getKeyPress();
        if (key == UP_ARROW) {
            selected = (selected - 1 + numOptions) % numOptions; // Navigation vers le haut (cercle)
        } else if (key == DOWN_ARROW) {
            selected = (selected + 1) % numOptions; // Navigation vers le bas (cercle)
        } else if (key == ENTER_KEY) {
            clearScreen();  // Effacer l'écran avant d'exécuter la fonction sélectionnée
            switch (selected) {
                case 0:
                    affichermafiche();
                    break;
                case 1:
                    afficher_mesrendezvous(p);
                    break;
                case 2:
                    ajouter_remarque_patient(p);
                    break;
                case 3:
                    lire_remarques_patient(p);
                    printf("Appuyez sur Entrée pour continuer...");
                    getchar();  // Consomme le '\n' restant dans le buffer
                    break;
                case 4:
                    modifier_fiche_patient(p);
                    break;
                case 5: {

                    afficherMedicament(tete, "medicaments.txt");
                    break;
                }
                case 6:
                    printf(" | MERCI POUR VOTRE VISITE ! |\n");
                    Sleep(2000);
                    return; // Retour au menu principal
                default:
                    printf("Choix invalide, veuillez réessayer.\n");
                    break;
            }
        }
    } while (1);
}


// Affiche le menu avec le titre en rose dans un cadre
void chowMenu(const char* title, const char* options[], int numOptions, int selected) {
    system("cls");

    // Obtenir les dimensions de la console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int screenHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Afficher le titre centré
    setColor(13); // Couleur rose pour le titre
    showCenteredText("*************************************", screenHeight / 2 - 2, screenWidth);
    showCenteredText("* BIENVENUE CHEZ NOTRE CLINIQUE DENTAIRE *", screenHeight / 2 - 1, screenWidth);
    showCenteredText("*************************************", screenHeight / 2, screenWidth);
    setColor(7); // Réinitialisation à la couleur par défaut

    // Afficher les options en dessous
    for (int i = 0; i < numOptions; i++) {
        setCursorPosition((screenWidth - strlen(options[i]) - 4) / 2, (screenHeight / 2) + 2 + i);
        if (i == selected) {
            setColor(10); // Couleur verte pour l'option sélectionnée
            printf("> [%s] <", options[i]);
            setColor(7); // Réinitialisation à la couleur par défaut après l'option
        } else {
            printf("  %s  ", options[i]);
        }
    }
}



int main() {
    char nextScreen[20];
    strcpy(nextScreen, "main");

    while (1) {
        if (strcmp(nextScreen, "main") == 0) {
            const char* options[] = {
                "Espace Docteur",
                "Espace Secretaire",
                "Espace Patient",
                "Quitter"
            };
            int numOptions = sizeof(options) / sizeof(options[0]);
            int selected = 0;
            int key;

            while (1) {
                // Effacer l'écran et afficher le menu
                system("cls");

                // Obtenir les dimensions de la console
                CONSOLE_SCREEN_BUFFER_INFO csbi;
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                GetConsoleScreenBufferInfo(hConsole, &csbi);
                int screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
                int screenHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

                // Afficher le titre centré
                setColor(13); // Rose
                showCenteredText("*************************************", screenHeight / 2 - 3, screenWidth);
                showCenteredText("* BIENVENU CHEZ NOTRE CLINIQUE DENTAIRE *", screenHeight / 2 - 2, screenWidth);
                showCenteredText("*************************************", screenHeight / 2 - 1, screenWidth);
                setColor(7); // Réinitialisation

                // Afficher les options
                for (int i = 0; i < numOptions; i++) {
                    setCursorPosition((screenWidth - strlen(options[i]) - 4) / 2, (screenHeight / 2) + i);
                    if (i == selected) {
                        if (i == 3) {
                            setColor(12); // Rouge pour "Quitter"
                        } else {
                            setColor(10); // Vert pour les autres options sélectionnées
                        }
                        printf("> [%s] <", options[i]);
                    } else {
                        setColor(7); // Couleur par défaut
                        printf("  %s  ", options[i]);
                    }
                }
                setColor(7); // Réinitialisation à la couleur par défaut

                // Navigation dans le menu
                key = getKeyPress();
                if (key == UP_ARROW) {
                    selected = (selected - 1 + numOptions) % numOptions; // Navigation circulaire vers le haut
                } else if (key == DOWN_ARROW) {
                    selected = (selected + 1) % numOptions; // Navigation circulaire vers le bas
                } else if (key == ENTER_KEY) {
                    if (selected == 0) {
                        strcpy(nextScreen, "doctor");
                    } else if (selected == 1) {
                        strcpy(nextScreen, "secretary");
                    } else if (selected == 2) {
                        strcpy(nextScreen, "patient");
                    } else if (selected == 3) {
                        printf("Merci de votre visite !\n");
                        return 0; // Quitter le programme
                    }
                    break;
                }
            }
        } else if (strcmp(nextScreen, "doctor") == 0) {
            show_DoctorMenu(nextScreen);
        } else if (strcmp(nextScreen, "secretary") == 0) {
            show_SecretaryMenu(nextScreen);
        } else if (strcmp(nextScreen, "patient") == 0) {
            show_PatientMenu(nextScreen);
        } else {
            printf("Erreur : Écran inconnu. Retour au menu principal.\n");
            Sleep(2000);
            strcpy(nextScreen, "main");
        }
    }
}

// Exemple des menus secondaires (inchangés sauf si navigation nécessaire)
void show_DoctorMenu(char* nextScreen) {
    const char* doctorOptions[] = {
        "Compléter la fiche d'un patient",
        "Afficher la fiche d'un patient",
        "Espace libre",
        "Enregistrer le prochain rendez-vous",
        "Afficher les rendez-vous enregistrés",
        "Afficher les rendez-vous pour une date donnée",
        "Ajouter un médicament",
        "Associer un médicament à un patient",
        "Envoyer un message",
        "Lire les messages",
        "Retour"
    };

    int numOptions = sizeof(doctorOptions) / sizeof(doctorOptions[0]);
    int selected = 0;
    int key;

    while (1) {
        clearScreen();  // Effacer l'écran avant d'afficher le menu

        // Affichage du menu avec changement de couleur
        for (int i = 0; i < numOptions; i++) {
            // Obtenir les dimensions de la console pour centrer
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            int screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

            setCursorPosition((screenWidth - strlen(doctorOptions[i])) / 2, i + 5); // Centrer les options verticalement
            if (i == selected) {
                if (i == 10) {
                    setColor(12); // Rouge pour "Retour"
                } else {
                    setColor(10); // Vert pour les autres options sélectionnées
                }
                printf("> [%s] <", doctorOptions[i]);
            } else {
                setColor(7); // Couleur par défaut
                printf("  %s  ", doctorOptions[i]);
            }
        }
        setColor(7); // Réinitialisation de la couleur par défaut

        key = getKeyPress();

        if (key == UP_ARROW) {
            selected = (selected - 1 + numOptions) % numOptions; // Navigation circulaire vers le haut
        } else if (key == DOWN_ARROW) {
            selected = (selected + 1) % numOptions; // Navigation circulaire vers le bas
        } else if (key == ENTER_KEY) {
            clearScreen();  // Effacer l'écran avant d'exécuter la fonction sélectionnée
            switch (selected) {
                case 0: {
                    char nom_patient[50];
                    printf("Entrez le nom du patient : ");
                    scanf("%s", nom_patient);
                    modifier_fiche_docteur(nom_patient);
                    break;
                }
                case 1:
                    afficher_fiche_patient();
                    printf("\nAppuyez sur une touche pour revenir au menu principal...\n");
                    getchar();
                    break;
                case 2:
                    enregistrerSymptomes("symptomes.txt");
                    break;
                case 3: {
                    char nom_patient[50];
                    int jour, mois, annee, joursAjout;
                    printf("Entrez le nom du patient : ");
                    scanf("%s", nom_patient);
                    printf("Entrez la date de CE dernier rendez-vous (jour mois année) : ");
                    scanf("%d %d %d", &jour, &mois, &annee);
                    printf("Donnez le nombre de jours après lequel le patient doit revenir : ");
                    scanf("%d", &joursAjout);
                    int jourProchain, moisProchain, anneeProchain;
                    calculerProchaineDate(jour, mois, annee, joursAjout, &jourProchain, &moisProchain, &anneeProchain);
                    printf("Prochain rendez-vous : %d/%d/%d\n", jourProchain, moisProchain, anneeProchain);
                    getchar();
                    break;
                }
                case 4:
                    afficherrendezvous();

                    break;
                case 5: {
                    int jour, mois, annee;
                    printf("Entrez la date pour laquelle afficher les rendez-vous (jour mois année) : ");
                    scanf("%d %d %d", &jour, &mois, &annee);
                    afficher_rendezvous_par_date(jour, mois, annee);
                    getchar();
                    break;
                }
                case 6:
                    ajouterMedicament(&tete, "medicaments.txt");
                    getchar();
                    break;
                case 7: {
                    char nom_patient[50];
                    printf("Entrez le nom du patient : ");
                    scanf("%s", nom_patient);
                    char fichier_patient[100];
                    snprintf(fichier_patient, sizeof(fichier_patient), "%s.txt", nom_patient);
                    associer_medicament_patient(fichier_patient);
                    getchar();
                    getchar();
                    break;
                }
                case 8:
                    ajouter_remarque();
                getchar();
                    break;
                case 9:
                    afficher_remarques();
                    break;
                case 10:
                    strcpy(nextScreen, "main"); // Retour au menu principal
                    return;
                default:
                    printf("Choix invalide, veuillez réessayer.\n");
                    break;
            }
        }
    }
}

void show_SecretaryMenu(char* nextScreen) {
    printf("Affichage du menu Secrétaire...\n");
    espace_secretaire();

    Sleep(2000);
    strcpy(nextScreen, "main");
}
int patient_index;
void show_PatientMenu(char* nextScreen) {
    printf("Affichage du menu Patient...\n");
    Patient1 patients[MAX_PATIENTS];


    // Charger les patients depuis le fichier

    interface_patient(patients, patient_index);


        // Actions après la fin de la boucle
        Sleep(2000);
        strcpy(nextScreen, "main");
    }
