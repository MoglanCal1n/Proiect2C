//
// Created by Moglan Calin-Stefan on 06-Dec-23.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "transations.h"

bool citeste_numar_float(float *numar) {
    while (true) {
        if (scanf("%f", numar) == 1) {
            // Dacă s-a citit un număr float, ieșim din buclă și returnăm true
            break;
        } else {
            // Dacă inputul nu este un număr float, curățăm buffer-ul
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("Invalid input. Please reinsert the input:\n");
        }
    }
    return true;
}

bool citeste_numar_intreg(int *numar) {
    while (true) {
        if (scanf("%d", numar) == 1) {
            // Dacă s-a citit un număr întreg, ieșim din buclă și returnăm true
            break;
        } else {
            // Dacă inputul nu este un număr întreg, curățăm buffer-ul
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("Invalid input. Please reinsert the input:\n");
        }
    }
    return true;
}

void citeste_un_cuvant(char *cuvant, int lungime_maxima) {
    getchar();
    fgets(cuvant, lungime_maxima, stdin);

    // Eliminăm newline-ul din șirul citit (înlocuindu-l cu terminatorul de șir '\0')
    size_t lungime = strlen(cuvant);
    if (cuvant[lungime - 1] == '\n') {
        cuvant[lungime - 1] = '\0';
    } else {
        // Dacă newline-ul nu a fost citit, înseamnă că buffer-ul de citire s-a umplut
        // și au rămas caractere suplimentare, deci le curățăm pentru a evita citiri ulterioare nedorite
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }

    // Verificăm dacă cuvantul conține spații
    // Dacă conține, repetăm citirea
    char *spatiu = strchr(cuvant, ' ');
    while (spatiu != NULL) {
        printf("Invalid input. Please reinsert the input:\n");
        fgets(cuvant, lungime_maxima, stdin);

        lungime = strlen(cuvant);
        if (cuvant[lungime - 1] == '\n') {
            cuvant[lungime - 1] = '\0';
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }

        spatiu = strchr(cuvant, ' ');
    }
}

void citeste_utilizator(struct Users *user,int id_cont, int id){
    int type;
    char nume[255], prenume[255], parola[255];

    printf("Please insert the type of the account: (1 - saving;2 - checking;3 - credit):\n");
    citeste_numar_intreg(&type);

    while(type < 1 || type > 3){
        printf("Input data is invalid!\n");
        printf("Please insert the type of the account: (1 - saving;2 - checking;3 - credit):\n");
        citeste_numar_intreg(&type);
    }

    printf("Please insert the last name: \n");
    citeste_un_cuvant(nume, 255);

    printf("Please insert the first name: \n");
    citeste_un_cuvant(prenume, 255);

    printf("Please insert the password: \n");
    fgets(parola, sizeof(parola), stdin);

    add_utilizator(user,id, id_cont, type, nume, prenume, parola);
}

void citeste_cont(struct Account *cont, int id){
    char username[255], parola[255];

    printf("Please insert the username:\n");
    citeste_un_cuvant(username, 255);

    printf("Please insert the password:\n");
    fgets(parola, sizeof (parola), stdin);

    add_account(cont,id, username, parola);
}

int citeste_admin(char parola_admin[]){
    char parola[255];
    printf("Please insert the admin password: \n");
    fgets(parola, sizeof(parola), stdin);

    if(strcmp(parola_admin, parola) == 0)
        return 1;

    return 0;
}

int add_utilizator(struct Users *user ,int id, int id_cont, int type, char nume[], char prenume[], char parola[]){
    user -> id = id;
    user -> id_cont = id_cont;
    user -> type = type;
    strcpy(user -> nume ,nume);
    strcpy(user -> prenume, prenume);
    strcpy(user -> parola, parola);
    return 0;
}

int add_account(struct Account *cont,int id, char username[], char parola[]){
    cont -> id = id;
    strcpy(cont -> username, username);
    strcpy(cont -> parola, parola);
    return 0;
}

int edit_utilizator_nume(struct Users *user){
    char nume[255];
    printf("Please input the new last name:\n");
    citeste_un_cuvant(nume, 255);
    strcpy(user -> nume, nume);
    return 0;
}

int edit_utilizator_prenume(struct Users *user){
    char prenume[255];
    printf("Please input the new first name:\n");
    citeste_un_cuvant(prenume, 255);
    strcpy(user -> prenume, prenume);
    return 0;
}

int edit_utilizator_parola(struct Users *user){
    char parola[255];
    printf("Please input the new password:\n");
    fgets(parola, sizeof (parola), stdin);
    strcpy(user -> parola, parola);
    return 0;
}

int edit_cont_username(struct Account *cont){
    char username[255];
    printf("Please input the new username:\n");
    citeste_un_cuvant(username, 255);
    strcpy(cont -> username, username);
    return 0;
}

int edit_cont_parola(struct Account *cont){
    char parola[255];
    printf("Please input the new password:\n");
    fgets(parola, sizeof (parola), stdin);
    strcpy(cont -> parola, parola);
    return 0;
}

void afisare_cont(struct Account *cont, int nr_conturi){
    for (int i = 0; i < nr_conturi; i++)
        printf("Id account- %d, Username account - %s\n", cont[i].id, cont[i].username);
}



void afisare_utilizatori(struct Users *user, int id, int nr_utilizatori){
    for(int i = 0; i < nr_utilizatori; i++)
        if(user[i].id_cont == id)
            printf("Utilizator cu Id- %d, Tip - %d, Nume - %s, Prenume - %s\n", user[i].id, user[i].type, user[i].nume, user[i].prenume);
}

void afisare_cont_admin(struct Account *cont, int nr_conturi){
    for (int i = 0; i < nr_conturi; i++)
        printf("Id cont - %d, Username cont - %s, Parola - %s\n", cont[i].id, cont[i].username, cont[i].parola);
}



void afisare_utilizatori_admin(struct Users *user, int nr_utilizatori){
    for(int i = 0; i < nr_utilizatori; i++)
            printf("Utilizator cu Id- %d, Tip - %d, Nume - %s, Prenume - %s, \n", user[i].id, user[i].type, user[i].nume, user[i].prenume);
}

int authentication_account(struct Account *cont,int id_citit,  int nr_conturi){
    char parola_citit[255];
    printf("Input the password of the account:\n");
    scanf("%s", parola_citit);
    for(int i = 0; i < nr_conturi; i++)
        if (cont[i].id == id_citit)
            if(strcmp(cont[i].parola, parola_citit) == 0)
                return 1;

    return 0;
}

int authentication_fin_acc(struct Users *user, int nr_fin_acc,int id_citit, int id_cont) {
    char parola_citit[255];
    printf("Input the password of the financial account:\n");
    scanf("%s", parola_citit);
    for (int i = 0; i < nr_fin_acc; i++)
        if (user[i].id == id_citit)
            if (strcmp(user[i].parola, parola_citit) == 0)
                if(id_cont == user[i].id_cont)
                    return 1;
    return 0;
}

void sterge_utilizator(struct Users *user, int *nr_fin_acc){
    int index = -1;
    int id;
    printf("Please input the id of the account you wish to delete!\n");
    citeste_numar_intreg(&id);
    for (int i = 0; i < *nr_fin_acc; i++)
        if(user[i].id == id){
            index = i;
            break;
        }
    if(index != -1) {
        for (int i = index; i < *nr_fin_acc - 1; i++)
            user[i] = user[i + 1];
        (*nr_fin_acc)--;
        printf("Financial account with ID %d successfully deleted!\n", id);
    }else{
        printf("Financial account with ID %d not found!\n", id);
    }
}

void citeste_tranzactie(struct Transactions *transaction, int id_cont, int id_utilizator, int type){
    char description[255];
    float amount;
    int day, month, year;

    printf("Please input the day your transaction was made:\n");
    citeste_numar_intreg(&day);
    while(day < 1 || day > 31){
        printf("Input data is not valid!\n");
        printf("Please input the day your transaction was made:\n");
        citeste_numar_intreg(&day);
    }

    printf("Please input the month your transaction was made:\n");
    citeste_numar_intreg(&month);
    while(month < 1 || month > 12){
        printf("Input data is invalid\n");
        printf("Please input the month your transaction was made:\n");
        citeste_numar_intreg(&month);
    }

    printf("Please input the year your transaction was made:\n");
    citeste_numar_intreg(&year);
    while(year < 2021 || year > 2024){
        printf("Input data is invalid!\n");
        printf("Please input the year your transaction was made:\n");
        citeste_numar_intreg(&year);
    }
    printf("Please input the amount of your transaction!\n");
    citeste_numar_float(&amount);
    getchar();
    printf("Please input the description of your transaction!\n");
    fgets(description, sizeof (description), stdin);

    adauga_tranzactie(transaction, type, amount,  description, id_cont, id_utilizator, day, month, year);
    }

int adauga_tranzactie(struct Transactions *transaction, int type, float amount, char description[], int id_cont, int id_utilizator, int day, int month, int year){
    transaction -> type = type;
    transaction -> day = day;
    transaction -> month = month;
    transaction -> year = year;
    transaction -> id_trans = id_utilizator;
    transaction -> id_cont = id_cont;
    transaction -> amount = amount;
    strcpy(transaction -> description, description);
    return 0;
}

int adauga_transfer(struct Transactions *transaction, int id_cont, int id_tranzactie, int id_dest_cont, int id_dest_utilizator,int type, char description[], float amount,int day, int month, int year ){
    transaction -> type = type;
    transaction -> day = day;
    transaction -> month = month;
    transaction -> year = year;
    transaction -> id_trans = id_tranzactie;
    transaction -> id_dest_cont = id_dest_cont;
    transaction -> id_dest_utilizator = id_dest_utilizator;
    transaction -> id_cont = id_cont;
    transaction -> amount = amount;
    strcpy(transaction -> description, description);
    return 0;
}

void citeste_transfer(struct Transactions *transaction, int id_cont, int id_utilizator, int type){
    char description[255];
    float amount;
    int id_dest_cont, id_dest_utilizator;
    printf("Please input the id of the destination account!\n");
    citeste_numar_intreg(&id_dest_cont);
    getchar();
    printf("Please input the id of the destination financial account!\n");
    citeste_numar_intreg(&id_dest_utilizator);
    int day, month, year;

    printf("Please input the day your transaction was made:\n");
    citeste_numar_intreg(&day);
    while(day < 1 || day > 31){
        printf("Input data is not valid!\n");
        printf("Please input the day your transaction was made:\n");
        citeste_numar_intreg(&day);
    }

    printf("Please input the month your transaction was made:\n");
    citeste_numar_intreg(&month);
    while(month < 1 || month > 12){
        printf("Input data is invalid\n");
        printf("Please input the month your transaction was made:\n");
        citeste_numar_intreg(&month);
    }

    printf("Please input the year your transaction was made:\n");
    citeste_numar_intreg(&year);
    while(year < 2021 || year > 2024){
        printf("Input data is invalid!\n");
        printf("Please input the year your transaction was made:\n");
        citeste_numar_intreg(&year);
    }
    getchar();
    printf("Please input the amount of your transaction!\n");
    citeste_numar_float(&amount);
    getchar();
    printf("Please input the description of your transaction!\n");
    fgets(description, sizeof (description), stdin);

    adauga_transfer(transaction, id_cont, id_utilizator, id_dest_cont, id_dest_utilizator, type, description, amount, day, month, year);
}

float acc_balance(struct Transactions *transaction,  int id_cont, int id_utilizator, int nr_tranzactii){
    float balance = 0;
    for(int i = 0; i < nr_tranzactii; i++){
        if(transaction[i].id_cont == id_cont && transaction[i].id_trans == id_utilizator){
            if (transaction[i].type == 1)
                balance = balance + transaction[i].amount;
            if (transaction[i].type == 3 || transaction[i].type == 2 || transaction[i].type == 4)
                balance = balance - transaction[i].amount;
        }
        if(transaction[i].id_dest_cont == id_cont && transaction[i].id_dest_utilizator == id_utilizator)
            balance += transaction[i].amount;

    }
    return balance;
}

void raport_expense(struct Transactions *transaction, int id_cont, int id_utilizator, int nr_tranzactii){
    float exp = 0;
    for(int i = 0; i < nr_tranzactii; i++)
        if(transaction[i].id_cont == id_cont && transaction[i].id_trans == id_utilizator)
            if(transaction[i].type == 3 || transaction[i].type == 2 || transaction[i].type == 4)
                exp += transaction[i].amount;
    printf("The expenses accumulated a value of: %f", exp);
}

void afiseaza_tranzactii(struct Transactions *transaction, int id_cont, int id_utilizator, int nr_tranzactii){
    for (int i = 0; i< nr_tranzactii; i++)
        if(transaction[i].id_cont == id_cont && transaction[i].id_trans == id_utilizator)
            printf("Transaction with Id account: %d, Id user: %d, Day : %d, Month: %d, Year: %d Type: %d, Amount: %f, Description: %s.\n" ,transaction[i].id_cont, transaction[i].id_trans,transaction[i].day, transaction[i].month, transaction[i].year ,transaction[i].type ,transaction[i].amount, transaction[i].description);
}

void raport_income(struct Transactions *transaction, int id_cont, int id_utilizator, int nr_tranzactii){
    float exp = 0;
    for(int i = 0; i < nr_tranzactii; i++)
        if(transaction[i].id_cont == id_cont && transaction[i].id_trans == id_utilizator)
            if(transaction[i].type == 1)
                exp += transaction[i].amount;
    printf("The incomes accumulated a value of: %f\n", exp);
}

void afiseaza_transfer(struct Transactions *transaction, int id_cont, int id_utilizator, int nr_tranzactii) {
    int okg = 0, okr =0;
    printf("-----Transfers given:\n");
    for(int i = 0; i < nr_tranzactii; i++)
        if(transaction[i].id_cont == id_cont && transaction[i].id_trans == id_utilizator && transaction[i].type == 3){
            printf("Transfer to Id account: %d, Id user: %d, Day: %d, Month: %d, Year: %d ,Value: %f, Description: %s.\n",transaction[i].id_dest_cont,transaction[i].id_dest_utilizator,transaction[i].day, transaction[i].month, transaction[i].year,transaction[i].amount, transaction[i].description);
            okg = 1;
        }

    if(okg == 0)
        printf("No transfers were made!\n");
    printf("-----Transfers received:\n");
    for(int i = 0; i < nr_tranzactii; i++)
        if(transaction[i].id_dest_cont == id_cont && transaction[i].id_dest_utilizator == id_utilizator) {
            printf("Transfer received from Id account: %d, Id user: %d, Value: %f, Description: %s.\n",transaction[i].id_cont, transaction[i].id_trans, transaction[i].amount, transaction[i].description);
            okr = 1;
        }
    if(okr == 0)
        printf("No transfers were received!\n");
}

void afiseaza_tranzactii_admin(struct Transactions *transaction, int nr_tranzactii){
    for(int i = 0; i < nr_tranzactii; i++)
       if(transaction[i].type == 3)
           printf("Transfer to Id account: %d, Id user: %d, Day: %d, Month: %d, Year: %d ,Value: %f, Description: %s.\n",transaction[i].id_dest_cont,transaction[i].id_dest_utilizator,transaction[i].day, transaction[i].month, transaction[i].year,transaction[i].amount, transaction[i].description);
       else
           printf("Transaction with Id account: %d, Id user: %d, Day : %d, Month: %d, Year: %d Type: %d, Amount: %f, Description: %s.\n" ,transaction[i].id_cont, transaction[i].id_trans,transaction[i].day, transaction[i].month, transaction[i].year ,transaction[i].type ,transaction[i].amount, transaction[i].description);

}

void afiseaza_fin_acc(struct Users *user, int id_cont,int nr_fin_acc){
    for (int i = 0; i< nr_fin_acc; i++)
        if(user[i].id_cont == id_cont)
            printf("Account with Id: %d, Last Name: %s, First Name: %s, Type: %d, Password: %s\n", user[i].id, user[i].nume, user[i].prenume, user[i].type, user[i].parola);
}

void scrieConturiInFisier(struct Account *cont, int nr_conturi, const char *numeFisier) {
    FILE *fisier = fopen(numeFisier, "w");
    if (fisier == NULL) {
        printf("This file couldn't be opened.\n");
        return;
    }

    for (int i = 0; i < nr_conturi; i++) {
        fprintf(fisier, "%d %s %s\n", cont[i].id, cont[i].username, cont[i].parola);
    }

    fclose(fisier);
}

int citesteConturi(const char *numeFisier, struct Account *cont, int dimensiuneVector, int frecvcont[]) {
    FILE *fisier = fopen(numeFisier, "r");
    if (fisier == NULL) {
        printf("The file couldn't be opened.\n");
        return -1;
    }

    int index = 0;
    while (fscanf(fisier, "%d %s %s", &cont[index].id, cont[index].username, cont[index].parola) != EOF) {
        index++;
        frecvcont[cont[index].id]++;
        if (index >= dimensiuneVector) {
            printf("Vector dimension is to little for the given data.\n");
            break;
        }
    }
    fclose(fisier);
    return index; // Returnează numărul de structuri citite
}

void scrieUseriInFisier(struct Users *user, int nr_useri, const char *numeFisier2) {
    FILE *fisier = fopen(numeFisier2, "w");
    if (fisier == NULL) {
        printf("The file couldn't be opened write2.");
        return;
    }

    for (int i = 0; i < nr_useri; i++) {
        fprintf(fisier, "%d %d %s %s %d %s\n", user[i].id, user[i].id_cont, user[i].nume, user[i].prenume, user[i].type, user[i].parola);
    }

    fclose(fisier);
}

int citesteUseri(const char *numeFisier2, struct Users *user, int dimensiuneVector, int frecvuser[]) {
    FILE *fisier = fopen(numeFisier2, "r");
    if (fisier == NULL) {
        printf("The file couldn't be opened2.");
        return -1;
    }

    int i = 0;
    while (fscanf(fisier, "%d %d %s %s %d %s\n", &user[i].id, &user[i].id_cont, user[i].nume, user[i].prenume, &user[i].type, user[i].parola ) != EOF) {
        i++;
        frecvuser[user[i].id]++;
        if (i >= dimensiuneVector) {
            printf("Vector dimension is to little for the given data.\n");
            break;
        }
    }
    fclose(fisier);
    return i; // Returnează numărul de structuri citite
}

void scrieTRanzactiiInFisier(struct Transactions *transaction, int nr_tranzactii, const char *numeFisier3) {
    FILE *fisier = fopen(numeFisier3, "w");
    if (fisier == NULL) {
        printf("The file couldn't be opened3.");
        return;
    }

    for (int i = 0; i < nr_tranzactii; i++) {
        fprintf(fisier, "%d %d %d %d %d %d %d %d %.2f %s\n", transaction[i].id_cont, transaction[i].id_trans, transaction[i].id_dest_cont, transaction[i].id_dest_utilizator
        ,transaction[i].day, transaction[i].month, transaction[i].year, transaction[i].type, transaction[i].amount ,transaction[i].description);
    }

    fclose(fisier);
}

int citesteTranzactii(const char *numeFisier3, struct Transactions *transaction, int dimensiuneVector) {
    FILE *fisier = fopen(numeFisier3, "r");
    if (fisier == NULL) {
        printf("The file couldn't be opened read3.");
        return -1;
    }

    int i = 0;
    while (fscanf(fisier, "%d %d %d %d %d %d %d %d %f %[^\n]", &transaction[i].id_cont, &transaction[i].id_trans, &transaction[i].id_dest_cont, &transaction[i].id_dest_utilizator
            , &transaction[i].day, &transaction[i].month, &transaction[i].year ,&transaction[i].type ,&transaction[i].amount, transaction[i].description ) != EOF) {

        i++;
        if (i >= dimensiuneVector) {
            printf("Vector dimension is to little for the given data.\n");
            break;
        }
    }
    fclose(fisier);
    return i; // Returnează numărul de structuri citite
}

void scrieConturiInFisierCSV(struct Account *cont, int nr_conturi, const char *numeFisier) {
    FILE *fisier = fopen(numeFisier, "w");
    if (fisier == NULL) {
        printf("Nu s-a putut deschide fisierul.");
        return;
    }

    for (int i = 0; i < nr_conturi; i++) {
        fprintf(fisier, "%d,%s,%s\n", cont[i].id, cont[i].username, cont[i].parola);
    }

    fclose(fisier);
}

int citesteConturiCSV(const char *numeFisier, struct Account *cont, int dimensiuneVector) {
    FILE *fisier = fopen(numeFisier, "r");
    if (fisier == NULL) {
        printf("Nu s-a putut deschide fisierul.");
        return -1;
    }

    int index = 0;
    while (fscanf(fisier, "%d,%49[^,],%49[^\n]%*c",
                  &cont[index].id, cont[index].username, cont[index].parola) == 3) {
        index++;
        if (index >= dimensiuneVector) {
            printf("Dimensiunea vectorului este prea mică pentru datele date.");
            break;
        }
    }

    fclose(fisier);
    return index; // Returnează numărul de structuri citite
}
void scrieUseriInFisierCSV(struct Users *user, int nr_useri, const char *numeFisier2) {
    FILE *fisier = fopen(numeFisier2, "w");
    if (fisier == NULL) {
        printf("The file couldn't be opened write2.");
        return;
    }

    for (int i = 0; i < nr_useri; i++) {
        fprintf(fisier, "%d,%d,%s,%s,%d,%s\n", user[i].id, user[i].id_cont, user[i].nume, user[i].prenume, user[i].type, user[i].parola);
    }

    fclose(fisier);
}

int citesteUseriCSV(const char *numeFisier2, struct Users *user, int dimensiuneVector) {
    FILE *fisier = fopen(numeFisier2, "r");
    if (fisier == NULL) {
        printf("The file couldn't be opened2.");
        return -1;
    }

    int i = 0;
    while (fscanf(fisier, "%d,%d,%49[^,],%49[^,],%d,%49[^,]\n", &user[i].id, &user[i].id_cont, user[i].nume, user[i].prenume, &user[i].type, user[i].parola ) != EOF) {
        i++;
        if (i >= dimensiuneVector) {
            printf("Vector dimension is to little for the given data.\n");
            break;
        }
    }
    fclose(fisier);
    return i; // Returnează numărul de structuri citite
}

void scrieTRanzactiiInFisierCSV(struct Transactions *transaction, int nr_tranzactii, const char *numeFisier3) {
    FILE *fisier = fopen(numeFisier3, "w");
    if (fisier == NULL) {
        printf("The file couldn't be opened3.");
        return;
    }

    for (int i = 0; i < nr_tranzactii; i++) {
        fprintf(fisier, "%d,%d,%d,%d,%d,%d,%d,%d,%.2f,%s\n", transaction[i].id_cont, transaction[i].id_trans, transaction[i].id_dest_cont, transaction[i].id_dest_utilizator
                ,transaction[i].day, transaction[i].month, transaction[i].year, transaction[i].type, transaction[i].amount ,transaction[i].description);
    }

    fclose(fisier);
}

int citesteTranzactiiCSV(const char *numeFisier3, struct Transactions *transaction, int dimensiuneVector) {
    FILE *fisier = fopen(numeFisier3, "r");
    if (fisier == NULL) {
        printf("The file couldn't be opened read3.");
        return -1;
    }

    int i = 0;
    while (fscanf(fisier, "%d,%d,%d,%d,%d,%d,%d,%d,%f,%[^\n]", &transaction[i].id_cont, &transaction[i].id_trans, &transaction[i].id_dest_cont, &transaction[i].id_dest_utilizator
            , &transaction[i].day, &transaction[i].month, &transaction[i].year ,&transaction[i].type ,&transaction[i].amount, transaction[i].description ) != EOF) {

        i++;
        if (i >= dimensiuneVector) {
            printf("Vector dimension is to little for the given data.\n");
            break;
        }
    }
    fclose(fisier);
    return i; // Returnează numărul de structuri citite
}


void scrieReview(struct Reviews *tranzactie, int *numarReviews, int frecvcont[]) {
    if (*numarReviews < 255) {
        printf("Please insert the id  of the account you want to review:\n");
        scanf("%d", &tranzactie[*numarReviews].id_reviewed_cont); // Citeste id-ul contului review-uit

        printf("Please insert the id of the account who left the review:\n");
        scanf("%d", &tranzactie[*numarReviews].id_reviewer_cont); // Citeste id-ul contului care a dat review-ul

        while(frecvcont[tranzactie[*numarReviews].id_reviewer_cont] != 1 && tranzactie[*numarReviews].id_reviewed_cont != 1){
            printf("One of the ids doesnt exist!\n");

            printf("Please insert the id  of the account you want to review:\n");
            scanf("%d", &tranzactie[*numarReviews].id_reviewed_cont); // Citeste id-ul contului review-uit

            printf("Please insert the id of the account who left the review:\n");
            scanf("%d", &tranzactie[*numarReviews].id_reviewer_cont); // Citeste id-ul contului care a dat review-ul

            printf("Please insert the review:\n");
            scanf(" %[^\n]s", tranzactie[*numarReviews].review); // Citeste review-ul
        }
        (*numarReviews)++; // Incrementarea numărului de review-uri în vector
    } else {
        printf("The maximum number of reviews has been reached.\n");
    }
}


void afisare_review(struct Reviews *recenzie, int id_cont, int nr_recenzii){
    for(int i = 0; i < nr_recenzii; i++)
        if(recenzie[i].id_reviewed_cont == id_cont)
            printf("Review from %d given to %d: %s\n", recenzie[i].id_reviewer_cont, recenzie[i].id_reviewed_cont, recenzie[i].review);
}

void scrieReviewsinFisier(struct Reviews *recenzie, int nr_recenzii, const char *numeFisier4) {
    FILE *fisier = fopen(numeFisier4, "w");
    if (fisier == NULL) {
        printf("This file couldn't be opened.\n");
        return;
    }

    for (int i = 0; i < nr_recenzii; i++) {
        fprintf(fisier, "%d %d %s\n", recenzie[i].id_reviewer_cont, recenzie[i].id_reviewed_cont, recenzie[i].review);
    }

    fclose(fisier);
}

int citesteReviews(const char *numeFisier4, struct Reviews *recenzie, int dimensiuneVector) {
    FILE *fisier = fopen(numeFisier4, "r");
    if (fisier == NULL) {
        printf("The file couldn't be opened.\n");
        return -1;
    }

    int index = 0;
    while (fscanf(fisier, "%d %d %[^\n]", &recenzie[index].id_reviewer_cont, &recenzie[index].id_reviewed_cont, recenzie[index].review) != EOF) {
        index++;
        if (index >= dimensiuneVector) {
            printf("Vector dimension is to little for the given data.\n");
            break;
        }
    }
    fclose(fisier);
    return index; // Returnează numărul de structuri citite
}

void afiseaza_all_review(struct Reviews *recenzie, int nr_recenzii){
    for (int i = 0; i< nr_recenzii; i++)
        printf("Review from %d given to %d: %s\n", recenzie[i].id_reviewer_cont, recenzie[i].id_reviewed_cont, recenzie[i].review);
}
