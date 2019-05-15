#include "calculatriceip.h"
#include "ui_calculatriceip.h"
#include "adresseipv4.h"
#include <QtMath>
#include <QMessageBox>

/**
 * @brief CalculatriceIP::CalculatriceIP
 * @details constructeur de la Classe CalculatriceIP
 * @param parent
 */

CalculatriceIP::CalculatriceIP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalculatriceIP)
{
    ui->setupUi(this);
    int suffixe ;
    quint64 nbMaxSousReseaux;
    quint8 masque[4]={0,0,0,0};
    QString leMasque;
    for(suffixe = 0 ; suffixe < 30 ; suffixe++)
    {
        nbMaxSousReseaux = static_cast<quint64> (qPow(2, 32-suffixe-1));
        masque[suffixe / 8] += static_cast<quint8>  (qPow(2,(7-(suffixe % 8))));
        leMasque.clear();
        for(int indice = 0 ; indice < 4; indice++)
        {
            leMasque = leMasque + QString::number(masque[indice]);
            if(indice <3)
            {
                leMasque = leMasque + ".";
            }
        }
        ui->comboBox_masque->addItem(leMasque);
        ui->comboBox_suffixe->addItem(QString::number(suffixe+1));
        ui->comboBox_sous_reseau_max->addItem(QString::number(nbMaxSousReseaux));
        ui->comboBox_max_ip->addItem(QString::number(nbMaxSousReseaux - 2));

    }
    QValidator *validator = new QIntValidator(0, 255, this);
    ui->lineEdit_adresse1->setValidator(validator);
    ui->lineEdit_adresse2->setValidator(validator);
    ui->lineEdit_adresse3->setValidator(validator);
    ui->lineEdit_adresse4->setValidator(validator);
    connect(ui->lineEdit_adresse1,&QLineEdit::textChanged,this,&CalculatriceIP::on_pushButtonCalculer_clicked);
    connect(ui->lineEdit_adresse2,&QLineEdit::textChanged,this,&CalculatriceIP::on_pushButtonCalculer_clicked);
    connect(ui->lineEdit_adresse3,&QLineEdit::textChanged,this,&CalculatriceIP::on_pushButtonCalculer_clicked);
    connect(ui->lineEdit_adresse4,&QLineEdit::textChanged,this,&CalculatriceIP::on_pushButtonCalculer_clicked);
}
CalculatriceIP::~CalculatriceIP()
{
    delete ui;
}
void CalculatriceIP::on_pushButtonCalculer_clicked()
{
quint8 adresse[4];
adresse[0] = ui->lineEdit_adresse1->text().toInt();
adresse[1] = ui->lineEdit_adresse2->text().toInt();
adresse[2] = ui->lineEdit_adresse3->text().toInt();
adresse[3] = ui->lineEdit_adresse4->text().toInt();

int suffixe;
suffixe = ui->comboBox_suffixe->currentText().toInt();
AdresseIPv4 uneAdresse(adresse, suffixe);
QString texte1, texte2;
uneAdresse.ObtenirAdresseReseau(adresse);
texte1 = ConvertirTabOctetEnQString(adresse);
ui->lineEdit_adr_reseau->setText(texte1);

uneAdresse.ObtenirPremierAdresse(adresse);
texte1 = ConvertirTabOctetEnQString(adresse);

uneAdresse.ObtenirDerniereAdresse(adresse);
texte2 = ConvertirTabOctetEnQString(adresse);
ui->lineEdit_adr_ip->setText(texte1 + "-" + texte2);

uneAdresse.ObtenirAdresseDiffusion(adresse);
texte1 = ConvertirTabOctetEnQString(adresse);
ui->lineEdit_adr_diffusion->setText(texte1);

}

QString CalculatriceIP::ConvertirTabOctetEnQString(const quint8 tabOctet[])
{
    QString adresse;
    for(int indice = 0;indice<4; indice ++)
    {
        adresse = adresse + QString::number(tabOctet[indice]);
        if(indice <3)
        {
            adresse = adresse +  ".";
        }
    }
    return adresse;
}

void CalculatriceIP::on_pushButtonPropos_clicked()
{
    QMessageBox aPropos;
    aPropos.setText("Calculatrice IPv4\n LE CREN JOHAN \n Jeudi 28 février 2019");
    aPropos.exec();
}
