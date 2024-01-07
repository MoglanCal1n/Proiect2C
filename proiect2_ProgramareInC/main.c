#include <stdio.h>
#include "transations.h"
#include "prints.h"

int frecvuseri[255], frecvcont[255];
char parola_admin[255] = "CalinAdmin\n";
char numeFisier[255] = "cont.txt";
char numeFisier2[255] = "user.txt";
char numeFisier3[255] = "tranzactie.txt";
char numeFisier4[255] = "review.txt";

int main() {
    FILE *fisier = fopen("Log.txt", "a");
    struct Users user1[255];
    struct Account conturi[255];
    struct Transactions tranzactii[255];
    struct Reviews recenzie[255];
    int nr_recenzii = citesteReviews(numeFisier4, recenzie, 255);
    int nr_fin_acc = citesteUseri(numeFisier2, user1, 255, frecvuseri);
    int nr_conturi = citesteConturi(numeFisier, conturi, 255, frecvcont);
    int nr_tranzactii = citesteTranzactii(numeFisier3, tranzactii, 255);
    int input = 1, chstrans;
    float raport_exp;

    while(input != 0){
        print_entry();
        printf("Please input the function:\n");
        citeste_numar_intreg(&input);
        while(input < 0 || input > 4){
            printf("Invalid input. Please reinsert!\n");
            printf("Please input the function:\n");
            citeste_numar_intreg(&input);
        }
        getchar();
        if(input == 1){
            print_authentication_account();
            int id_citit;
            printf("Input the id of the account:\n");
            citeste_numar_intreg(&id_citit);
            getchar();
            if(authentication_account(conturi, id_citit, nr_conturi) == 1){
                fprintf(fisier, "User with account id: %d logged in.\n", id_citit);
                raport_exp = 0;
                int chsacc = 1;
                printf("Authentication successful!\n");
                while (chsacc != 0) {
                    print_account();
                    printf("Please input the function:\n");
                    citeste_numar_intreg(&chsacc);
                    while(chsacc < 0 || chsacc > 6){
                        printf("Invalid input. Please reinsert!\n");
                        printf("Please input the function:\n");
                        citeste_numar_intreg(&chsacc);
                    }
                    if (chsacc == 1)
                    {
                        print_edit_user();
                        int press;
                        citeste_numar_intreg(&press);
                        while(press < 1 || press > 2){
                            printf("Invalid input. Please reinsert!\n");
                            citeste_numar_intreg(&press);
                        }
                        if(press == 1){
                            edit_cont_username(conturi);
                            afisare_cont(conturi, nr_conturi);
                            fprintf(fisier, "User with account id: %d changed their username.\n", id_citit);
                        }
                        if(press == 2){
                            edit_cont_parola(conturi);
                            printf("Password successfully changed!\n");
                            fprintf(fisier, "User with account id: %d changed their password.\n", id_citit);

                        }
                    }
                    if (chsacc == 2){
                        int id_fin_citit;
                        printf("Input the id of the financial account:\n");
                        citeste_numar_intreg(&id_fin_citit);

                        if(authentication_fin_acc(user1, nr_fin_acc, id_fin_citit,id_citit) == 1){
                            fprintf(fisier, "User with account id: %d logged in the financial account with id: %d.\n", id_citit, id_fin_citit);
                            raport_exp = 0;
                            int chsfin = 1;
                            while(chsfin != 0){
                                print_menu_user();
                                citeste_numar_intreg(&chsfin);
                                while(chsfin < 0 || chsfin > 5){
                                    printf("Invalid input. Please reinsert!\n");
                                    citeste_numar_intreg(&chsfin);
                                }
                                if(chsfin == 1){
                                    int butt;
                                    print_edit_fin();
                                    printf("Enter your input:\n");
                                    citeste_numar_intreg(&butt);
                                    while(butt < 1 || butt > 3){
                                        printf("Invalid input. Please reinsert!\n");
                                        printf("Enter your input:\n");
                                        citeste_numar_intreg(&butt);
                                    }
                                    if(butt == 1){
                                        edit_utilizator_nume(user1);
                                        fprintf(fisier, "User with account id: %d and financial account id: %d changed their last name.\n", id_citit, id_fin_citit);
                                        printf("Last name successfully changed!\n");
                                    }
                                    if(butt == 2){
                                        edit_utilizator_prenume(user1);
                                        printf("First name successfully changed!\n");
                                        fprintf(fisier, "User with account id: %d and financial account id: %d changed their first name.\n", id_citit, id_fin_citit);
                                    }
                                    if(butt == 3){
                                        edit_utilizator_parola(user1);
                                        printf("Password successfully changed!\n");
                                        fprintf(fisier, "User with account id: %d and financial account id: %d changed their password.\n", id_citit, id_fin_citit);
                                    }
                                }
                                if(chsfin == 2){
                                    sterge_utilizator(user1, &nr_fin_acc);
                                    afisare_utilizatori(user1,id_citit ,nr_fin_acc);
                                    fprintf(fisier, "User with account id: %d deleted the financial account with id: %d.\n", id_citit, id_fin_citit);
                                }
                                if(chsfin == 3){
                                    print_transaction_menu();
                                    citeste_numar_intreg(&chstrans);
                                    while(chstrans < 1 || chstrans > 4){
                                        printf("Invalid input. Please reinsert!\n");
                                        citeste_numar_intreg(&chstrans);
                                    }
                                    if(chstrans == 1 || chstrans == 2 || chstrans == 4){
                                        citeste_tranzactie(&tranzactii[nr_tranzactii], id_citit, id_fin_citit, chstrans);
                                        fprintf(fisier, "User with account id: %d and financial account id: %d made a transaction.\n", id_citit, id_fin_citit);
                                    }
                                    if(chstrans == 3){
                                        citeste_transfer(&tranzactii[nr_tranzactii],id_citit, id_fin_citit, chstrans);
                                        fprintf(fisier, "User with account id: %d and financial account id: %d made a transfer.\n", id_citit, id_fin_citit);

                                    }
                                    nr_tranzactii++;

                                }
                                if(chsfin == 4){
                                   float balance =  acc_balance(tranzactii, id_citit, id_fin_citit, nr_tranzactii);
                                    fprintf(fisier, "User with account id: %d and financial account id: %d checked their account balance.\n", id_citit, id_fin_citit);
                                    printf("Acc balance = %f\n", balance);
                                }
                                if(chsfin == 5){
                                    int chsraport;
                                    print_raports_menu();
                                    printf("Please input the raport you want to do:\n");
                                    citeste_numar_intreg(&chsraport);
                                    while(chsraport < 1 || chsraport > 4){
                                        printf("Invalid input. Please reinsert!\n");
                                        printf("Please input the raport you want to do:\n");
                                        citeste_numar_intreg(&chsraport);
                                    }
                                    if(chsraport == 1){
                                        raport_expense(tranzactii, id_citit, id_fin_citit, nr_tranzactii);
                                        fprintf(fisier, "User with account id: %d and financial account id: %d made an expense raport.\n", id_citit, id_fin_citit);
                                    }
                                    if(chsraport == 2){
                                        raport_income(tranzactii, id_citit, id_fin_citit, nr_tranzactii);
                                        fprintf(fisier, "User with account id: %d and financial account id: %d made an income raport.\n", id_citit, id_fin_citit);
                                    }
                                    if(chsraport == 3){
                                        afiseaza_tranzactii(tranzactii, id_citit, id_fin_citit, nr_tranzactii);
                                        fprintf(fisier, "User with account id: %d and financial account id: %d made an account statement.\n", id_citit, id_fin_citit);
                                    }
                                    if(chsraport == 4){
                                        afiseaza_transfer(tranzactii, id_citit, id_fin_citit, nr_tranzactii);
                                        fprintf(fisier, "User with account id: %d and financial account id: %d made an transaction register.\n", id_citit, id_fin_citit);
                                    }
                                }
                            }


                        }
                        else
                            printf("An error occurred!\n");
                    }
                    if (chsacc == 3){
                        int id_user;
                        printf("Please input the ID: \n");
                        citeste_numar_intreg(&id_user);
                        frecvuseri[id_user]++;
                        if(frecvuseri[id_user] == 1){
                        citeste_utilizator(&user1[nr_fin_acc], id_citit, id_user);
                        nr_fin_acc ++;
                        printf("The financial account was successfully added!\n");
                        fprintf(fisier, "User with account id: %d made a new financial account with id: %d\n", id_citit, id_user);
                        }
                        else
                            printf("An financial account with this id already exist!\n");
                    }
                    if(chsacc == 4)
                        afiseaza_fin_acc(user1, id_citit, nr_fin_acc);
                    if(chsacc == 5){
                        afiseaza_all_review(recenzie, nr_recenzii);
                        scrieReview(recenzie, &nr_recenzii, frecvcont);
                    }
                    if(chsacc == 6){
                        int id_recenzie;
                        printf("Please enter the id of the account which reviews you wish to see:\n");
                        scanf("%d", &id_recenzie);
                        afisare_review(recenzie, id_recenzie, nr_recenzii);
                    }
                }
            }

            else
                printf("An error occurred!\n");
        }
        if(input == 2){
            int id_cont;
            printf("Introduceti ID-ul: \n");
            citeste_numar_intreg(&id_cont);

            frecvcont[id_cont]++;
            if(frecvcont[id_cont] == 1){
                citeste_cont(&conturi[nr_conturi], id_cont);
                printf("The account was successfully added!\n");
                nr_conturi++;
                fprintf(fisier, "A new user with account id: %d has been added.\n", id_cont);

            }
            else
                printf("An account with this id already exists!\n");
        }
        if(input == 3){
            if(citeste_admin(parola_admin) == 1) {
                printf("Authentication successful!\n");
                int chsadmin = 1;
                while (chsadmin != 0) {
                    print_admin_menu();
                    printf("Choose the admin function:\n");
                    citeste_numar_intreg(&chsadmin);
                    while (chsadmin < 0 || chsadmin > 4) {
                        printf("Input invalid please reinsert!\n");
                        printf("Choose the admin function:\n");
                        citeste_numar_intreg(&chsadmin);
                    }

                    if (chsadmin == 1)
                        afisare_cont_admin(conturi, nr_conturi);
                    if (chsadmin == 2)
                        afisare_utilizatori_admin(user1, nr_fin_acc);
                    if (chsadmin == 3)
                        afiseaza_tranzactii_admin(tranzactii, nr_tranzactii);
                    if(chsadmin == 4)
                        afiseaza_all_review(recenzie, nr_recenzii);
                    if (chsadmin == 0)
                        break;
                }
            }
        }
        if(input == 4){
            scrieConturiInFisier(conturi, nr_conturi, numeFisier);
            scrieUseriInFisier(user1, nr_fin_acc, numeFisier2);
            scrieTRanzactiiInFisier(tranzactii, nr_tranzactii, numeFisier3);
            scrieConturiInFisierCSV(conturi, nr_conturi, "contCSV.txt");
            scrieTRanzactiiInFisierCSV(tranzactii, nr_tranzactii, "tranzacteieCSV.txt");
            scrieUseriInFisierCSV(user1, nr_fin_acc, "userCSV.txt");
            scrieReviewsinFisier(recenzie, nr_recenzii, numeFisier4);
            nr_fin_acc = citesteUseri(numeFisier2, user1, 255, frecvuseri);
            nr_conturi = citesteConturi(numeFisier, conturi, 255, frecvcont);
            nr_tranzactii = citesteTranzactii(numeFisier3, tranzactii, 255);
            nr_recenzii = citesteReviews(numeFisier4, recenzie, 255);
            printf("Data was saved successfully!\n");
        }
        if(input == 0){
            scrieConturiInFisier(conturi, nr_conturi, numeFisier);
            scrieUseriInFisier(user1, nr_fin_acc, numeFisier2);
            scrieTRanzactiiInFisier(tranzactii, nr_tranzactii, numeFisier3);
            scrieReviewsinFisier(recenzie, nr_recenzii, numeFisier4);
            scrieConturiInFisierCSV(conturi, nr_conturi, "contCSV.txt");
            scrieTRanzactiiInFisierCSV(tranzactii, nr_tranzactii, "tranzacteieCSV.txt");
            scrieUseriInFisierCSV(user1, nr_fin_acc, "userCSV.txt");
            break;
        }
    }
    fclose(fisier);
    return 0;
}
