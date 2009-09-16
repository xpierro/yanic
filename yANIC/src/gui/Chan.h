/**
 * \file Chan.h
 * \brief Header de Chan.cpp
 * \author Pierre Collignon
 * \version 0.1
 *
 * Déclaration de la classe Chan permettant la gestion d'un canal IRC.
 *
 */

#ifndef CHAN_H
#define CHAN_H

#include <QListWidget>
#include <string.h>
#include "NickList.h"
#include "Nickname.h"
#include "../tools/Exceptions.h"
#include "AbstractCentralWidget.h"

/*!
 * \class Chan
 * \brief Représentation d'un channel.
 * Classe décrivant un chan de discussion, avec une liste de pseudo.
 */
class Chan : public AbstractCentralWidget {
	Q_OBJECT

private :
	NickList *nickList;
    QString topic;
    QString name;

public :
    /*!
     * \brief Constructeur
     * \param name Description du canal.
     * \param parent Widget parent.
     */
    Chan(const QString& name,QWidget *parent);

    //REQUETES

    /*!
     * \brief Renvoie la liste de pseudo.
     */
    NickList * getNickList(void);

    /*!
     * \brief Renvoie le topic.
     */
    QString getTopic(void);

    QString getName(void);

    // COMMANDES

    /*!
     * \brief Modifie le topic du chan.
     * \param topic Le topic.
     */
    void setTopic(QString topic);

    /*!
     * \brief Ajoute un pseudo à la liste.
     * \param nick Le pseudo à rajouter.
     */
    void addNickname(Nickname nick);

    /*!
     * \brief Enlève un pseudo de la liste.
     * \param nick Le pseudo à enlever.
     */
    void removeNickname(const Nickname& nick);

    /*!
     * Change le mode d'un utilisateur.
     * \param nick Le pseudo impacté.
     * \param mode Le mode à appliquer.
     */
    void changeMode(Nickname nick, const QString& mode);

    // OUTILS

    /*!
     * \brief Outil permettant de déterminer si une chaine est
     *        un nom de canal.
     * \param name Le nom à analyser.
     * \returns Vrai si le nom est un nom valide de canal.
     */
    static bool isNameChan(const QString& name);

signals :
    /*!
     * Si le topic est changé
     */
    void topicChanged(void);
};
#endif
