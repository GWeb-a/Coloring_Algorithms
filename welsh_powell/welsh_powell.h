#ifndef        WELSH_POWELL_H_
#define        WELSH_POWELL_H_

#include       "../graph/graph.h"

/*
 * \brief Copie un tableau d'entiers dans un autre
 *
 * \param dest : int * : le tableau dans lequel on souhaite copier les données
 * \param src : int * : la tableau dont on veut copier le contenu
 * \param index : int * : la tableau qui va récupérer les index
 * \param array_length : int : la taille du tableau à copier
 *
 * \return : pas de valeur de retour
 */
void            Copy_Int_Array(int *dest, int *src, int *index, int array_length);

/*
 * \brief Trie les tableaux array et index en fonction de l'ordre du tableau
 * array
 *
 * \param array : int * : le tableau à trier
 * \param index : int * : le tableau des index équivalent à trier
 * \param array_length : int : la taille du tableau array (et index)
 *
 * \return : pas de valeur de retour
 */
void            Bubble_Sort(int *array, int *index, int array_length);

/*
 * \brief Colorie un sommet
 *
 * \param coloring : T_Coloring * : les couleurs
 * \param index : int : l'index du sommet à colorer
 * \param color : int : la couleur
 *
 * \return : pas de valeur de retour
 */
void            Color_Vertex(T_Coloring *coloring, int index, int color);

/*
 * \brief Vérifie si un sommet possède des sommets adjacents d'une couleur
 * recherchée
 *
 * \param current_vertex : int : le sommet que l'on souhaite colorer
 * \param coloring : T_Coloring * : les couleurs
 * \param graph : T_Graph * : le graph
 * \param color : int : la couleur que l'on souhaite attribuer au sommet
 *
 * \return int : 1 s'il n'y a pas de lien avec des sommets de cette couleur,
 * 0 dans l'autre cas
 */
int             Has_No_Linked_Vertex_With_Same_Color(int current_vertex, T_Coloring *coloring, T_Graph *graph, int color);

/*
 * \brief Boucle jusqu'à colorer tous les sommets du graph via l'algorithme
 * de Welsh et Powell
 *
 * \param graph : T_Graph * : le graph
 * \param coloring : T_Coloring * : les couleurs
 * \param ordered : int * : un tableau des degrés des sommets dans l'ordre
 * \param index : int * : le tableau des index des sommets correspondant au
 * tableau ordered
 *
 * \return : pas de valeur de retour
 */
void            Color_Graph(T_Graph *graph, T_Coloring *coloring, int *index);

/*
 * \brief Trie les sommets en fonction de leur degré
 *
 * \param graph : T_Graph * : le graph
 * \param coloring : T_Coloring * : les couleurs
 *
 * \return : pas de valeur de retour
 */
void            Order_Degrees(T_Graph *graph, T_Coloring *coloring);

/*
 * \brief Effectue l'algorithme de Welsh Powell pour colorer le graph
 *
 * \param graph : T_Graph * : le graph
 * \param coloring : T_Coloring * : les couleurs
 *
 * \return : T_Coloring : les couleurs établies par l'algorithme
 */
T_Coloring      Welsh_Powell(T_Graph *graph);

#endif          /* WELSH_POWELL_H_ */
