#ifndef        GRAPH_H_
#define        GRAPH_H_

#include       "../coloring/coloring.h"

typedef struct S_Graph {
  int nb_vertex;
  char **matrix;
  int *degrees;
}              T_Graph;

/*
* \brief Libère la mémoire allouée pour un graph
*
* \param graph : T_Graph * : le graph
*
* \return : pas de valeur de retour
*/
void 					free_graph(T_Graph *graph);

/*
* \brief Vérifie si une matrice est symétrique
*
* \param graph : T_Graph * : le graph contenant la matrice et sa taille
*
* \return int : 0 si la matrice est non symétrique, 1 si elle l'est
*/
int 					Check_Symetry(T_Graph *graph);

/*
* \brief Crée une matrice carée de nb_vertex lignes dans un graph
*
* \param nb_vertex : int : le nombre de sommets du graph à créer
*
* \return T_Graph * : le graph créé
*/
T_Graph 			*Create_Random_Symetric_Graph(int nb_vertex);

/*
 * \brief Vérifie si deux sommets sont liés
 *
 * \param matrix : char ** : la matrice adjacente
 * \param a : int : le premier sommet
 * \param b : int : le second sommet
 *
 * \return int : 0 s'il y a une erreur, 1 si tout est correct
 */
int 					 Are_Linked(char **matrix, int a, int b);

/*
 * \brief Vérifie si la coloration est correcte
 *
 * \param graph : T_Graph * : le graph
 * \param coloring : T_Coloring * : le tableau des couleurs des sommets du graph
 *
 * \return int : 0 s'il y a une erreur, 1 si tout est correct
 */
int            Is_Coloring_Correct(T_Graph *graph, T_Coloring *coloring);

/*
 * \brief Affiche la matrice d'un graph
 *
 * \param graph : T_Graph * : le graph
 *
 * \return : pas de valeur de retour
 */
void 					Print_Matrix(T_Graph *graph);

/*
 * \brief Affiche le graph
 *
 * \param graph : T_Graph * : le graph
 * \param coloring : T_Coloring * : le tableau des couleurs des sommets du graph
 *
 * \return : pas de valeur de retour
 */
void           Print_Graph(T_Graph* graph, T_Coloring *coloring);

/*
 * \brief Lis un fichier graph pour le traduire en structure de graph
 *
 * \param filename : char * : le nom du fichier à ouvrir
 *
 * \return T_Graph * : la structure de graph ayant été créée
 */
T_Graph 		   *Read_Graph_File(char *filename);

/*
 * \brief Crée un fichier graph
 *
 * \param graph : T_Graph * : le graph contenant la matrice à écrire dans le
 * fichier
 * \param path : char * : le nom du fichier dans lequel écrire
 *
 * \return : pas de valeur de retour
 */
void 				  Write_Graph(T_Graph *graph, char *path);

/*
 * \brief Supprime un arc entre deux sommets
 *
 * \param graph : T_Graph * : le graph
 * \param origin : int : la source de l'arc
 * \param end : int : la destination de l'arc
 *
 * \return : pas de valeur de retour
 */
void           Remove_Edge(T_Graph *graph, int origin, int end);

/*
 * \brief Ajoute un arc entre deux sommets
 *
 * \param graph : T_Graph * : le graph
 * \param origin : int : la source de l'arc
 * \param end : int : la destination de l'arc
 *
 * \return : pas de valeur de retour
 */
void           Add_Edge(T_Graph *graph, int origin, int end);

/*
 * \brief Crée un graph dit "vide"
 *
 * \param graph : T_Graph * : le graph à initialiser
 * \param nb_vertex : int : le nombre de sommets
 *
 * \return : pas de valeur de retour
 */
void           Init_Graph(T_Graph *graph, int nb_vertex);

/*
 * \brief Colorie un graph et affiche la matrice et la coloration
 *
 * \param graph : T_Graph * : le graph contenant la matrice
 * \param algo : int : le choix de l'algo à utiliser
 *
 * \return : pas de valeur de retour
 */
void 					SetFullGraph(T_Graph *graph, int algo);

#endif         /* GRAPH_H_ */
