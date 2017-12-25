#ifndef GRAPHE_H
#define GRAPHE_H

#include <limits.h>


class Graphe
{
    private :
    int nombreNoeuds;
    int** matriceAjacence;
    int min = INT_MAX;
    public:
        Graphe(int nombreNoeuds=5);
        virtual ~Graphe();
        void afficherGraphe();/*Affichage du Graphe sous forme de matrice d'adjacence*/
        void contruireGraphe();/*Construction des poids du graphe a partir de données saisies par l'utilisateur*/
        void contruireGrapheAleatoire();/*Fonction pour construire un graphe avec des poids aleatoires*/
        bool verifierConvexite();/*Verification de la convexite du graphe (ie) tous les noeuds sont liés, sinon le MST n'existera pas*/
        void preparerMatrice();/*Fonction pour mettre des poids infinis sur les aretes de deux sommets non connectes (ie) ayant un poids zero sur la matrice*/
        void appliquerPrim();/*Fonction pour appliquer l'algorithme de Prim qui permet de trouver la MST*/

};


#endif // GRAPHE_H
