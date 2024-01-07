//
// Created by Moglan Calin-Stefan on 06-Dec-23.
//

#ifndef PROIECT2_PROGRAMAREINC_TRANSATIONS_H
#define PROIECT2_PROGRAMAREINC_TRANSATIONS_H

#include <stdbool.h>

struct Reviews{
    char review[255];
    int id_reviewed_cont;
    int id_reviewer_cont;
};
struct Transactions {
    float amount;
    int id_cont, id_trans, type, id_dest_cont, id_dest_utilizator, day, month, year;
    char description[255];
};

struct Users{
    int id, id_cont, type;
    char nume[255], prenume[255], parola[255];
    float balance;
};

struct Account{
    int id;
    char username[255], parola[255];
};



int add_utilizator(struct Users *user, int id,int id_cont, int type, char nume[], char prenume[], char parola[]);

int edit_utilizator_nume(struct Users *user);

int edit_utilizator_prenume(struct Users *user);

int edit_utilizator_parola(struct Users *user);

void citeste_utilizator(struct Users *user, int id_cont, int id);

int add_account(struct Account *cont,int id, char username[], char parola[]);

int edit_cont_username(struct Account *cont);

int edit_cont_parola(struct Account *cont);

void citeste_cont(struct Account *cont, int id);

void afisare_cont(struct Account *cont, int nr_conturi);

void afisare_utilizatori(struct Users *user, int id, int nr_utilizatori);

void afisare_cont_admin(struct Account *cont, int nr_conturi);

void afisare_utilizatori_admin(struct Users *user, int nr_utilizatori);

int authentication_account(struct Account *cont,int id_citit, int nr_utilizatori);

int authentication_fin_acc(struct Users *user, int nr_fin_acc, int id_citit, int id_cont);

void sterge_utilizator(struct Users *user, int *nr_fin_acc);

void citeste_tranzactie(struct Transactions *transaction, int id_cont, int id_utilizator, int type);

int adauga_tranzactie(struct Transactions *transaction, int type, float amount, char description[], int id_cont, int id_utilizator, int day, int month, int year);

int adauga_transfer(struct Transactions *transaction, int id_cont, int id_tranzactie, int id_dest_cont, int id_dest_utilizator,int type, char description[], float amount, int day, int month, int year );

void citeste_transfer(struct Transactions *transaction, int id_cont, int id_utilizator, int type);

float acc_balance(struct Transactions *transaction, int id_cont, int id_utilizator, int nr_tranzactii);

void raport_expense(struct Transactions *transaction, int id_cont, int id_utilizator, int nr_tranzactii);

void afiseaza_tranzactii(struct Transactions *transaction, int id_cont, int id_utilizator, int nr_tranzactii);

void raport_income(struct Transactions *transaction, int id_cont, int id_utilizator, int nr_tranzactii);

void afiseaza_transfer(struct Transactions *transaction, int id_cont, int id_utilizator, int nr_tranzactii);

void citeste_un_cuvant(char *cuvant, int lungime_maxima);

void afiseaza_fin_acc(struct Users *user, int id_cont, int nr_fin_acc);

bool citeste_numar_intreg(int *numar);

int citeste_admin(char parola_admin[255]);

void afiseaza_tranzactii_admin(struct Transactions *transaction, int nr_tranzactii);

void scrieConturiInFisier(struct Account *cont, int nr_conturi, const char *numeFisier);

int citesteConturi(const char *numeFisier, struct Account *cont, int dimensiuneVector, int frecvcont[]);

void scrieUseriInFisier(struct Users *user, int nr_useri, const char *numeFisier2);

int citesteUseri(const char *numeFisier2, struct Users *user, int dimensiuneVector, int frecvuser[]);

int citesteTranzactii(const char *numeFisier3, struct Transactions *transaction, int dimensiuneVector);

void scrieTRanzactiiInFisier(struct Transactions *transaction, int nr_tranzactii, const char *numeFisier3);

void scrieConturiInFisierCSV(struct Account *cont, int nr_conturi, const char *numeFisier);

int citesteConturiCSV(const char *numeFisier, struct Account *cont, int dimensiuneVector);

void scrieUseriInFisierCSV(struct Users *user, int nr_useri, const char *numeFisier2);

int citesteUseriCSV(const char *numeFisier2, struct Users *user, int dimensiuneVector);

int citesteTranzactiiCSV(const char *numeFisier3, struct Transactions *transaction, int dimensiuneVector);

void scrieTRanzactiiInFisierCSV(struct Transactions *transaction, int nr_tranzactii, const char *numeFisier3);

void scrieReview(struct Reviews *tranzactie, int *numarReviews, int frecvcont[]);

void afisare_review(struct Reviews *recenzie, int id_cont, int nr_recenzii);

void scrieReviewsinFisier(struct Reviews *recenzie, int nr_recenzii, const char *numeFisier4);

int citesteReviews(const char *numeFisier4, struct Reviews *recenzie, int dimensiuneVector);

void afiseaza_all_review(struct Reviews *recenzie, int nr_recenzii);



#endif //PROIECT2_PROGRAMAREINC_TRANSATIONS_H
