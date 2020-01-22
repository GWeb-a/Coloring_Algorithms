#ifndef        COLORING_H_
#define        COLORING_H_

#define        COLORLESS -1

typedef int *   T_Coloring;

/*
 * \brief Retourne la plus grande couleur d'un graph
 *
 * \param coloring : T_Coloring : la liste des couleurs du graph
 * \param nb_vertex : int : le sommet dont on souhaite connaître la couleur
 *
 * \return int : la plus grande couleur du graph
 */
int             Get_Max_Color(T_Coloring coloring, int nb_vertex);

/*
 * \brief Lis un fichier coloration pour le traduire en structure de coloration
 *
 * \param filename : char * : le nom du fichier à ouvrir
 *
 * \return T_Coloring * : la structure de coloration ayant été créée
 */
T_Coloring 	    *Read_Coloring_File(char *filename);

/*
 * \brief Retourne la couleur d'un sommet
 *
 * \param coloring : T_Coloring : la liste des couleurs du graph
 * \param vertex : int : le sommet dont on souhaite connaître la couleur
 *
 * \return int : la couleur du sommet
 */
int             Get_Vertex_Color(T_Coloring coloring, int vertex);

/*
 * \brief Libère en mémoire la liste des couleurs du graph
 *
 * \param coloring : T_Coloring * : la liste des couleurs du graph
 *
 * \return : pas de valeur de retour
 */
void            Destroy_Coloring(T_Coloring *coloring);

/*
 * \brief Crée un tableau de couleurs dit "vide"
 *
 * \param graph : T_Coloring * : le tableau de couleurs à initialiser
 * \param nb_vertex : int : le nombre de sommets du graph associé
 *
 * \return : pas de valeur de retour
 */
void            Init_Coloring(T_Coloring *coloring, int nb_vertex);

#endif          /* COLORING_H_ */
