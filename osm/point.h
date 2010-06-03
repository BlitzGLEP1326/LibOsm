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

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <iomanip>

using namespace std;


/**
 * Classe abstraite commune aux TrkPt et Ville pour faire des mesures de
 * distance entre deux éléments.
 */
class Point
{
    private:
/// Rayon moyen de la Terre.
        static const double RAYON_TERRE;

    protected:
/// Latitude en degrés géographiques.
        double fLatitude;

/// Longitude en degrés géographiques.
        double fLongitude;

	public:
/**
 * \brief Constructeur de l'instance.
 *
 * Assure aussi la fonction de constructeur par défaut avec des coordonnées
 * nulles.
 * \param aLatitude Latitude en degrés.
 * \param aLongitude Longitude en degrés.
 */
		Point(const double& aLatitude = 0,
              const double& aLongitude = 0) :
            fLatitude(aLatitude),
            fLongitude(aLongitude)
        {}

/**
 * Constructeur de copie.
 * \param aPoint Point servant à initialiser l'instance courante.
 */
        Point(const Point& aPoint) :
            fLatitude(aPoint.fLatitude),
            fLongitude(aPoint.fLongitude)
        {}

/**
 * \brief Destructeur virtuel de l'instance.
 *
 * Sans action.
 */
        virtual ~Point(void) {}

/**
 * Opérateur d'affection.
 * \param aPoint Point à affecter à l'instance courante.
 * \return Une référence sur l'instance courante après affectation.
 */
        Point& operator=(const Point& aPoint);

/**
 * \brief Retourne la distance entre l'instance courante et le Point indiqué.
 *
 * Cette fonction assure un calcul de distance à la surface d'une sphère
 * représentant la Terre. \see Point::RAYON_TERRE.
 * \param aPoint Point avec lequel se fait la mesure de distance.
 * \return La distance en mètres.
 */
        double distance(const Point& aPoint) const;

/**
 * Indique sur l'instance et le point indiqué sont superposés ou même identiques.
 * \param aPoint Instance qui sert de comparaison.
 * \return true si les 2 instances sont superposées ou identiques, ou false sinon.
 */
        bool operator==(const Point& aPoint);

/**
 * Retourne la latitude en degrés.
 * \return La valeur de la latitude.
 */
        const double& latitude() const
        { return fLatitude; }

/**
 * Affecte la latitude et retourne une référence.
 * \param aLatitude laitude exprimée en degrés.
 * \return La valeur de la latitude.
 */
        const double& latitude(const double& aLatitude)
        { return fLatitude = aLatitude; }

/**
 * Retourne la longitude en degrés.
 * \return La valeur de la longitude.
 */
        const double& longitude() const
        { return fLongitude; }

/**
 * Affecte et retourne la longitude.
 @ \param aLongitude La valeur de la longitude exprimée en degrés décimaux.
 * \return La valeur de la longitude exprimée en degrés décimaux.
 */
        const double& longitude(const double& aLongitude)
        { return fLongitude = aLongitude; }

/**
 * \brief Retourne un Point correspondant à l'instance déplacée suivant la
 *        distance et la direction indiquées.
 *
 * Cette fonction assure un calcul de distance à la surface d'une sphère
 * représentant la Terre. \see Point::RAYON_TERRE.
 * \param aDistance Distance du déplacement en mètres.
 * \param aBearing Direction du déplacement en degrés.
 * \return Un nouveau point.
 */
        Point decaller(const double& aDistance,
                       const float& aBearing) const;

/**
 * \brief Retourne le bearing depuis l'instance vers le Point indiqué.
 *
 * Il s'agit de l'angle avec la direction du Nord géographique.
 * \param aPoint Point vers lequel le bearing est calculé.
 * \return La valeur du bearing en degrés décimaux.
 */
        float bearing(const Point& aPoint) const;

};

/**
 * \brief Opérateur d'injection d'une description d'un Point dans un flux de
 *        sortie.
 *
 * Cette méthode génère les coordonnées du Point courant sous la forme d'une
 * paire de coordonnées polaires en degrés décimaux, préfixés par l'identifiant
 * de la coordonnée, sur le modèle suivant :
 * \code lat: +/-dd.ddddd, lon: +/-dd.dddd
 * \param aStream Le flux de sortie dans lequel est injecté la description.
 * \param aPoint Le Point dont la description sera injectée.
 * \return Le flux de sortie après injection.
 */
inline ostream& operator<<(ostream& aStream, const Point& aPoint)
{
    return aStream << "lat: " << setprecision(10) << aPoint.latitude() << ", lon: " << aPoint.longitude();
}

#endif // POINT_H
