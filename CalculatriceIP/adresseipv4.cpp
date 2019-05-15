/**
  *@file adresseipv4.cpp
  *@brief Définition de la classe Adresseipv4
  *@version 1.0
  *@date 14 mai 2019
  *@author jguillaumin
*/


#include "adresseipv4.h"

/**
 * @brief AdresseIPv4::AdresseIPv4
 * @details Constructeur de la classe
 * @param _adresse Tableau d'octet contient l'adresse IP
 * @param _suffixe Tableau contient le masque de réseau
 */
AdresseIPv4::AdresseIPv4(quint8 _adresse[], quint8 _suffixe)
{
    suffixe = _suffixe;
//    adresse[0]= _adresse[0];
//    adresse[1]= _adresse[1];
//    adresse[2]= _adresse[2];
//    adresse[3]= _adresse[3];

    for(int n=0; n<4; n++)
    {
        adresse[n] = _adresse[n];
    }

    CalculerMasque();

}

/**
 * @brief AdresseIPv4::ObtenirAdresseReseau
 * @param _adresseReseau
 */
void AdresseIPv4::ObtenirAdresseReseau(quint8 _adresseReseau[])
{
//    _adresseReseau[0] = adresse[0] & masque[0];
//    _adresseReseau[1] = adresse[1] & masque[1];
//    _adresseReseau[2] = adresse[2] & masque[2];
//    _adresseReseau[3] = adresse[3] & masque[3];

    for(int n=0; n<4; n++)
    {
        _adresseReseau[n] = adresse[n] & masque[n];
    }
}
/**
 * @brief AdresseIPv4::ObtenirPremierAdresse
 * @param _premiereAdresse
 */
void AdresseIPv4::ObtenirPremierAdresse(quint8 _premiereAdresse[])
{
//    _premiereAdresse[0] = adresse[0] & masque[0];
//    _premiereAdresse[1] = adresse[1] & masque[1];
//    _premiereAdresse[2] = adresse[2] & masque[2];
//    _premiereAdresse[3] = (adresse[3] & masque[3])+1;

    for(int n=0; n <3 ; n++)
    {
        _premiereAdresse[n] = adresse[n] & masque[n];
    }
    _premiereAdresse[3] = (adresse[3] & masque[3])+1;
}
/**
 * @brief AdresseIPv4::ObtenirDerniereAdresse
 * @param _derniereAdresse
 */
void AdresseIPv4::ObtenirDerniereAdresse(quint8 _derniereAdresse[])
{
//    _derniereAdresse[0] = adresse[0] | ~masque[0];
//    _derniereAdresse[1] = adresse[1] | ~masque[1];
//    _derniereAdresse[2] = adresse[2] | ~masque[2];
//    _derniereAdresse[3] =(adresse[3] | ~masque[3])-1;

    for(int n=0; n<3; n++)
    {
        _derniereAdresse[n] = adresse[n] | ~masque[n];
    }
    _derniereAdresse[3] =(adresse[3] | ~masque[3])-1;
}
/**
 * @brief AdresseIPv4::ObtenirAdresseDiffusion
 * @param _adresseDiffusion
 */
void AdresseIPv4::ObtenirAdresseDiffusion(quint8 _adresseDiffusion[])
{
//    _adresseDiffusion[0] = adresse[0] | ~masque[0];
//    _adresseDiffusion[1] = adresse[1] | ~masque[1];
//    _adresseDiffusion[2] = adresse[2] | ~masque[2];
//    _adresseDiffusion[3] = adresse[3] | ~masque[3];

    for(int n=0 ; n<4 ; n++)
    {
        _adresseDiffusion[n] = adresse[n] | ~masque[n];
    }
}
/**
 * @brief AdresseIPv4::CalculerMasque
 */
void AdresseIPv4::CalculerMasque()
{
    int n;
    masque[0]=0;
    masque[1]=0;
    masque[2]=0;
    masque[3]=0;

    for(n=0; n<suffixe; n++)
    {
        masque[n/8] += static_cast<quint8>  (qPow(2,(7-(n %8))));
    }
}


