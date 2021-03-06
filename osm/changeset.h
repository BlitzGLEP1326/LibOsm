/*
    Copyright © 2010 par Marc Sibert

    This file is part of LIBOSM

    LIBOSM is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    LIBOSM is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with LIBOSM.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file
 * \author Marc Sibert
 */

// Class automatically generated by Dev-C++ New Class wizard

#ifndef CHANGESET_H
#define CHANGESET_H

#include "top.h" // inheriting class's header file

#include <ctime>
#include <string>
#include "datetimeiso8601.h"

using namespace std;

/**
 * Classe définissant un Changset tel que le décrit l'Api OSM.
 */
class Changeset : public Top {
protected:
/// Date de création du changeset.
     DateTimeISO8601 fCreatedAt;

/// Nombre de modifications successives.
     unsigned fNumChanges;

/// Date de cloture du changset si clos, NULL sinon.
     DateTimeISO8601 fClosedAt;

/// État du Changeset (ouvert ou clos).
     bool fOpen;

/// Longitude minimum (BBOX).
     double fMinLon;

/// Latitude minimum (BBOX).
     double fMinLat;

/// Longitude maximum (BBOX).
     double fMaxLon;

/// Latitude maximum (BBOX).
     double fMaxLat;

public:
     /**
      * Constructeur de l'instance faisant aussi office de constructeur par
      * défaut.
      */
     Changeset() :
          Top(0, "", 0),
          fCreatedAt(),
          fNumChanges(0),
          fClosedAt(),
          fOpen(false),
          fMinLon(0),
          fMinLat(0),
          fMaxLon(0),
          fMaxLat(0)
     {}

     /**
      * Destructeur de l'instance, sans action.
      */
     virtual ~Changeset() {}

     /**
      * \brief Ajoute un attribut à l'instance Changeset.
      *
      * L'attribut doit faire partie de la liste accepté par les ELements de
      * l'Api osm.
      * \param aKey Le nom de l'attribut.
      * \param aValue La valeur de l'attribut sous la forme d'une chaîne de
      *        caractères.
      */
     virtual void setAttribut(const string& aKey, const string& aValue);


     /// Nom de la classe utilisée par certaines méthodes templates de la
     /// classe ApiOsm.
     static const string NOM;

     /**
      * Injecte une description du Changeset au format XML de l'API Osm dans
      * un flux de sortie.
      * \param aStream Un flux de sortie.
      * \return Le flux de sortie après injection de la description de l'Element.
      */
     ostream& afficher(ostream& aStream) const;

     /**
      * Test et retourne l'égalité des différents champs de l'instance.
      * \param aChangeset Une référence sur le Changeset comparé à l'instance.
      * \return true si les 2 Elements sont égaux, false sinon.
      */
     bool operator==(const Changeset& aChangeset) const;

     /**
      * Retourne la date de création du Changeset.
      * \return Une relation sur le champ date.
      */
     const DateTimeISO8601& createdAt() const {
          return fCreatedAt;
     }

     /**
      * Retourne le nombre de changements successifs attributé à ce Changeset.
      * \return Un entier représentant le nombre de changements.
      */
     const unsigned& numChanges() const {
          return fNumChanges;
     }

     /**
      * Retourne la date de cloture du Changeset.
      * \return Une relation sur le champ date.
      */
     const DateTimeISO8601& closedAt() const {
          return fClosedAt;
     }

     /**
      * Retourne un indicateur sur l'état du Changeset.
      * \return Un booléen contenant <code>true</code> si le changeset est
      *         ouvert et <code>false</code> s'il est clos.
      */
     bool open() const {
          return fOpen;
     }

     /**
      * Retourne la Longitude minimum de la BBOX du changeset.
      * \return Un réel à double précision.
      */
     const double& minLon() const {
          return fMinLon;
     }

     /**
      * Retourne la Latitude minimum de la BBOX du changeset.
      * \return Un réel à double précision.
      */
     const double& minLat() const {
          return fMinLat;
     }

     /**
      * Retourne la Longitude maximum de la BBOX du changeset.
      * \return Un réel à double précision.
      */
     const double& maxLon() const {
          return fMaxLon;
     }

     /**
      * Retourne la Latitude maximum de la BBOX du changeset.
      * \return Un réel à double précision.
      */
     const double& maxLat() const {
          return fMaxLat;
     }
};

/**
 * Permet l'injection de la description d'une instance de Changeset dans un flux
 * de sortie. La présentation correspond à un flux XML.
 * \param aStream Un flux de sortie recevant la description.
 * \param aChangeset L'instance dont la description est produite.
 * \return Le flux de sortie après injection de la description.
 */
ostream& operator<<(ostream& aStream, const Changeset& aChangeset);

#endif // CHANGESET_H
