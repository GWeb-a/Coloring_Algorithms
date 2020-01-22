#ifndef        GREEDY_H_
#define        GREEDY_H_

#include       "../graph/graph.h"

/*
 * \brief Vérifie si une couleur se situe dans un tableau de couleurs
 *
 * \param color : la couleur recherché
 * \param colors : T_Coloring : les couleurs des sommets liés
 * \param nb_vertex : int : le nombre de sommets du graph
 *
 * \return int : 1 la couleur est dans le tableau, 0 si elle ne l'est pas
 */
int         Is_Color_In_Array(int color, T_Coloring colors, int nb_vertex);

/*
 * \brief Retourne la plus petite couleur disponible pour un sommet donné
 *
 * \param colors : T_Coloring : les couleurs des sommets liés
 * \param nb_vertex : int : le nombre de sommets du graph
 *
 * \return int : la couleur trouvée
 */
int         Get_Min_Free_Color(T_Coloring colors, int nb_vertex);

/*
 * \brief Récupère un tableau de couleurs des sommets liés à un sommet donné
 *
 * \param graph : T_Graph * : le graph
 * \param coloring : T_Coloring : les couleurs du graph
 * \param colors : T_Coloring : les couleurs des sommets liés
 * \param vertex : int : l'indice du sommet que l'on souhaite colorer
 *
 * \return T_Coloring : les couleurs des sommets liés
 */
T_Coloring      Get_Linked_Colors(T_Graph *graph, T_Coloring coloring, T_Coloring colors, int vertex);

/*
 * \brief Boucle jusqu'à colorer tous les sommets du graph via l'algorithme
 * Glouton
 *
 * \param graph : T_Graph * : le graph
 * \param coloring : T_Coloring * : les couleurs
 *
 * \return : pas de valeur de retour
 */
void        Greedy_Coloring(T_Graph *graph, T_Coloring *coloring);

/*
 * \brief Initialise un tableau de couleurs et appelle l'algorithme de
 * coloration de glouton
 *
 * \param graph : T_Graph * : le graph
 *
 * \return T_Coloring : les couleurs générées par glouton
 */
T_Coloring      Greedy_Search(T_Graph *graph);

#endif          /* GREEDY_H_ */
