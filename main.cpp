//Application de l'algorithme de Prim pour la determination de l'arbre recouvrant minimum (Minimum Spanning Tree - MST).
//La structure de données choisie pour représenter un graphe est une matrice d'adjacence.
#include <stdio.h>
#include <limits.h>
#include <Graphe.h>
#include <iostream>
using namespace std;

int main()
{
int nbNoeuds, typeGraphe;
cout << "Veuillez saisir le nombre de noeuds du graphe a creer"<< endl;
cin >> nbNoeuds;
while(cin.fail()) {
    cout << "Veuillez saisir un nombre entier !"<<endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> nbNoeuds;
}
//Il faut faire un test sur la valeur de nbNoeuds (entière ou pas) (!)
Graphe g(nbNoeuds);
g.afficherGraphe();

cout << "Voulez vous construire un graphe aleatoirememnt ? [1 : oui, 0 : non]"<< endl;
cin >> typeGraphe;
while(cin.fail()) {
    cout << "Veuillez saisir un nombre entier !"<<endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> typeGraphe;
}
if(typeGraphe==1) g.contruireGrapheAleatoire();
else g.contruireGraphe();

g.afficherGraphe();
if(g.verifierConvexite()==true) g.appliquerPrim();
else cout <<"\nLe graphe genere n'est pas convexe. L'algorithme ne s'applique pas";

    return 0;
}

