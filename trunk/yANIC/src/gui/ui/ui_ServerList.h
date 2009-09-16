/********************************************************************************
** Form generated from reading ui file 'ServerList.ui'
**
** Created: Wed Sep 16 15:51:15 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SERVERLIST_H
#define UI_SERVERLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout_3;
    QLabel *userInfo;
    QLabel *nicknameLabel;
    QLineEdit *nicknameEdit;
    QLabel *secondChoiceLabel;
    QLineEdit *secondChoiceEdit;
    QLabel *thirdChoiceLabel;
    QLineEdit *thirdChoiceEdit;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *realNameLabel;
    QLineEdit *realNameEdit;
    QLabel *networks;
    QListWidget *networkList;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *editButton;
    QPushButton *sortButton;
    QFrame *line;
    QPushButton *closeButton;
    QPushButton *connectButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(318, 346);
        Form->setMinimumSize(QSize(318, 346));
        Form->setMaximumSize(QSize(318, 346));
        gridLayout_3 = new QGridLayout(Form);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        userInfo = new QLabel(Form);
        userInfo->setObjectName(QString::fromUtf8("userInfo"));

        gridLayout_3->addWidget(userInfo, 0, 0, 1, 3);

        nicknameLabel = new QLabel(Form);
        nicknameLabel->setObjectName(QString::fromUtf8("nicknameLabel"));

        gridLayout_3->addWidget(nicknameLabel, 1, 0, 1, 1);

        nicknameEdit = new QLineEdit(Form);
        nicknameEdit->setObjectName(QString::fromUtf8("nicknameEdit"));

        gridLayout_3->addWidget(nicknameEdit, 1, 1, 1, 2);

        secondChoiceLabel = new QLabel(Form);
        secondChoiceLabel->setObjectName(QString::fromUtf8("secondChoiceLabel"));

        gridLayout_3->addWidget(secondChoiceLabel, 2, 0, 1, 1);

        secondChoiceEdit = new QLineEdit(Form);
        secondChoiceEdit->setObjectName(QString::fromUtf8("secondChoiceEdit"));

        gridLayout_3->addWidget(secondChoiceEdit, 2, 1, 1, 2);

        thirdChoiceLabel = new QLabel(Form);
        thirdChoiceLabel->setObjectName(QString::fromUtf8("thirdChoiceLabel"));

        gridLayout_3->addWidget(thirdChoiceLabel, 3, 0, 1, 1);

        thirdChoiceEdit = new QLineEdit(Form);
        thirdChoiceEdit->setObjectName(QString::fromUtf8("thirdChoiceEdit"));

        gridLayout_3->addWidget(thirdChoiceEdit, 3, 1, 1, 2);

        usernameLabel = new QLabel(Form);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        gridLayout_3->addWidget(usernameLabel, 4, 0, 1, 1);

        usernameEdit = new QLineEdit(Form);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));

        gridLayout_3->addWidget(usernameEdit, 4, 1, 1, 2);

        realNameLabel = new QLabel(Form);
        realNameLabel->setObjectName(QString::fromUtf8("realNameLabel"));

        gridLayout_3->addWidget(realNameLabel, 5, 0, 1, 1);

        realNameEdit = new QLineEdit(Form);
        realNameEdit->setObjectName(QString::fromUtf8("realNameEdit"));

        gridLayout_3->addWidget(realNameEdit, 5, 1, 1, 2);

        networks = new QLabel(Form);
        networks->setObjectName(QString::fromUtf8("networks"));

        gridLayout_3->addWidget(networks, 6, 0, 1, 3);

        networkList = new QListWidget(Form);
        networkList->setObjectName(QString::fromUtf8("networkList"));

        gridLayout_3->addWidget(networkList, 7, 0, 4, 2);

        addButton = new QPushButton(Form);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout_3->addWidget(addButton, 7, 2, 1, 1);

        removeButton = new QPushButton(Form);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        gridLayout_3->addWidget(removeButton, 8, 2, 1, 1);

        editButton = new QPushButton(Form);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        gridLayout_3->addWidget(editButton, 9, 2, 1, 1);

        sortButton = new QPushButton(Form);
        sortButton->setObjectName(QString::fromUtf8("sortButton"));

        gridLayout_3->addWidget(sortButton, 10, 2, 1, 1);

        line = new QFrame(Form);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 11, 0, 1, 3);

        closeButton = new QPushButton(Form);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        gridLayout_3->addWidget(closeButton, 12, 0, 1, 1);

        connectButton = new QPushButton(Form);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        gridLayout_3->addWidget(connectButton, 12, 2, 1, 1);

#ifndef QT_NO_SHORTCUT
        nicknameLabel->setBuddy(nicknameEdit);
        secondChoiceLabel->setBuddy(secondChoiceEdit);
        thirdChoiceLabel->setBuddy(thirdChoiceEdit);
        usernameLabel->setBuddy(usernameEdit);
        realNameLabel->setBuddy(realNameEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(Form);
        QObject::connect(nicknameEdit, SIGNAL(returnPressed()), connectButton, SLOT(click()));
        QObject::connect(secondChoiceEdit, SIGNAL(returnPressed()), connectButton, SLOT(click()));
        QObject::connect(thirdChoiceEdit, SIGNAL(returnPressed()), connectButton, SLOT(click()));
        QObject::connect(usernameEdit, SIGNAL(returnPressed()), connectButton, SLOT(click()));
        QObject::connect(realNameEdit, SIGNAL(returnPressed()), connectButton, SLOT(click()));
        QObject::connect(closeButton, SIGNAL(clicked()), Form, SLOT(hide()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        userInfo->setText(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Informations utilisateur</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        nicknameLabel->setText(QApplication::translate("Form", "&Pseudonyme :", 0, QApplication::UnicodeUTF8));
        secondChoiceLabel->setText(QApplication::translate("Form", "Second choix :", 0, QApplication::UnicodeUTF8));
        thirdChoiceLabel->setText(QApplication::translate("Form", "Troisi\303\250me choix :", 0, QApplication::UnicodeUTF8));
        usernameLabel->setText(QApplication::translate("Form", "Nom d'&utilisateur :", 0, QApplication::UnicodeUTF8));
        realNameLabel->setText(QApplication::translate("Form", "Nom &r\303\251el :", 0, QApplication::UnicodeUTF8));
        networks->setText(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">R\303\251seaux</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("Form", "Ajouter", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("Form", "Enlever", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("Form", "Editer", 0, QApplication::UnicodeUTF8));
        sortButton->setText(QApplication::translate("Form", "Trier", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("Form", "Fermer", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("Form", "Connecter", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERLIST_H
