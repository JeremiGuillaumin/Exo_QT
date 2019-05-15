#ifndef ADRESSEIPV4_H
#define ADRESSEIPV4_H
#include <QtMath>

class AdresseIPv4
{
public:
    AdresseIPv4(quint8 _adresse[], quint8 _suffixe);
    void ObtenirAdresseReseau(quint8 _adresseReseau[]);
    void ObtenirPremierAdresse(quint8 _premiereAdresse[]);
    void ObtenirDerniereAdresse(quint8 _derniereAdresse[]);
    void ObtenirAdresseDiffusion(quint8 _adresseDiffusion[]);

private:
    void CalculerMasque();
    quint8 adresse[4];
    quint8 masque[4];
    quint8 suffixe;
};

#endif // ADRESSEIPV4_H
