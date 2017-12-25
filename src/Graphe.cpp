#include "Graphe.h"
#include "iostream"
//Utilisation de INT_MAX
#include <limits.h>
//Utilisation de la fonction Rand
#include <stdlib.h>

using namespace std;

Graphe::Graphe(int nbNoeuds)
{
    //On initialise le nombre de noeuds du graphe avec la valeur saisie par l'utilisateur
    nombreNoeuds=nbNoeuds;
    //Initiliser le graphe (ie) la matrice d'adjacence
    this->matriceAjacence=new int*[nombreNoeuds];
    for(int i=0;i<nombreNoeuds;i++){
                   this->matriceAjacence[i]= new int[nombreNoeuds];
        for(int j=0;j<nombreNoeuds;j++){
            matriceAjacence[i][j]=0;

        }
    }

}

Graphe::~Graphe()
{
    //Liberer la mémoire supprimer la matrice d'adjacence
}


void Graphe::afficherGraphe(){
    //Afficher la matrice d'adjacence
    cout<<"Matrice d'adjacence du graphe :"<< endl;
    cout<<"       ";
    for (int col=0;col<nombreNoeuds;col++) cout<<col<<"  ";
    cout<<endl<<endl;
     for(int i=0; i<nombreNoeuds;i++){
        cout<<i<<"   |";
        for(int j=0;j<nombreNoeuds;j++){
            if(this->matriceAjacence[i][j]<nombreNoeuds){
                cout<<"  "<<matriceAjacence[i][j];
            }else  cout<<" "<<this->matriceAjacence[i][j];
        }
        cout<< endl;
    }

}

void Graphe::preparerMatrice(){
    //Mettre des poids infinis sur les sommets non connectes
    for(int i=0; i<nombreNoeuds;i++){
        for(int j=0;j<nombreNoeuds;j++){
            if(this->matriceAjacence[i][j]==0){
                matriceAjacence[i][j]=INT_MAX;
            }
        }
    }

}

void Graphe::appliquerPrim(){

    cout<<"\nAlgorithme de Prim applique a la matrice d'adjacence :"<< endl;

    bool appartientMST[nombreNoeuds];
    int poidsMST[nombreNoeuds];

    appartientMST[0]=true;//Le premier noeuds appartient au MST
    for(int i=1;i<nombreNoeuds;i++) appartientMST[i]=false;//Les autres noeuds non pas encore été ajoutés au MST

    poidsMST[0]=0;

    cout<<"Appartient au MST : ";
    for(int i=0;i<nombreNoeuds;i++) {if(appartientMST[i]==true) cout <<" "<<i;}


    preparerMatrice();

    for(int k=1; k<nombreNoeuds;k++){
        int x=0,y=0;
        for(int i=0;i<nombreNoeuds;i++){
            for(int j=0; j<nombreNoeuds;j++){
                    //Dans la préparation de la matrice on donne un poids MAX_INT aux cases ayant un poids nul dans la matrice
                if(appartientMST[i] && !appartientMST[j] &&
                   matriceAjacence[i][j]<matriceAjacence[x][y] && matriceAjacence[i][j]>0)
                {
                    x=i; y=j;
                }
            }


        }

        cout<<"\nPoids minimum de l'arete de liaison : ("<<x<<","<<y<<") : "<<matriceAjacence[x][y]<<endl;
        //poidsMST[y]=x;

        poidsMST[y]=matriceAjacence[x][y];
        appartientMST[y]=true;

        cout<<"\nNoeuds appartenant au MST : ";
        for(int i=0;i<nombreNoeuds;i++) {if(appartientMST[i]==true) cout <<" "<<i;}

    }
    int poids=0;
    for(int i=1;i<nombreNoeuds;i++){
            poids=poidsMST[i]+poids;
        cout<<"\nEnsemble des poids : "<<poidsMST[i];
    }
    cout<<"\nPoids total de l'arbre : "<<poids;

}







void Graphe::contruireGraphe(){
    //L'utilisateur construit son graphe en saisissant les noeuds et les poids de chaque arc
    //Etant donné que le graphe n'est pas bidirectionnel le poids du chemin de A->B est égal au poids de B->A, cette propriété conduit à une matrice symétrique

    cout<<"\nConstruction du graphe :"<< endl;

    for(int i=0;i<nombreNoeuds;i++){
        for(int j=i;j<nombreNoeuds;j++){
            if(i!=j){
                int noeudsConnectes[nombreNoeuds];
                cout<<"Le noeud "<<j<<" est connecte au noeud "<< i<<" [Oui : 1 || Non : 0] ? ";
                cin>>noeudsConnectes[j];
                //cout<<endl;
                if(noeudsConnectes[j]==1){
                    cout<<"Veuillez saisir le poids de l'arete qui lie "<<i<<" a "<<j<<" : ";
                    cin>>matriceAjacence[i][j];
                    matriceAjacence[j][i]=matriceAjacence[i][j];
                    cout<<endl;
                }

            }

        }
    }

}

//v1 =


void Graphe::contruireGrapheAleatoire(){
    cout<<"\nConstruction du graphe aleatoirement:"<< endl;
    for(int i=0;i<nombreNoeuds;i++){
        for(int j=i;j<nombreNoeuds;j++){
            if(i!=j){
                matriceAjacence[i][j]=rand() % 20;
                matriceAjacence[j][i]=matriceAjacence[i][j];
            }

        }
    }

}


bool Graphe::verifierConvexite(){
    bool convexe=true;
    for(int i=0;i<nombreNoeuds;i++){
        int nbZero=0;
        for(int j=0;j<nombreNoeuds;j++){
            if(matriceAjacence[i][j]==0){
                nbZero++;
            }
        }
        if(nbZero==nombreNoeuds) convexe=false;
    }

    return convexe;
}

