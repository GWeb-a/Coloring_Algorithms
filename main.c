#include    <stdio.h>
#include    <stdlib.h>
#include 		<string.h>
#include    "graph/graph.h"
#include    "coloring/coloring.h"
#include 		"welsh_powell/welsh_powell.h"

void 				NoParamMain() {
	T_Graph *graph;
	int algo;
	int rows;
	char endline;

	printf("De quelle taille souhaitez-vous créer la matrice ? (9999 max) : ");
	if (scanf("%d%c", &rows, &endline) != 2 || endline != '\n' || rows > 9999)
		fprintf(stderr, "Vous devez renseigner un nombre valide.\n");
	else {
		printf("Quel algorithme de coloration souhaitez-vous utilisez ? (0 pour Welsh/Powell, 1 pour Glouton) : ");
		if (scanf("%d%c", &algo, &endline) != 2 || endline != '\n' || (algo != 0 && algo != 1))
			fprintf(stderr, "Vous devez renseigner un nombre valide.\n");
		else {
			graph = Create_Random_Symetric_Graph(rows);
			SetFullGraph(graph, algo);
			Write_Graph(graph, "graph/samples/test.graph");
			printf("Création d'un fichier nommé test.graph dans le dossier graph/samples/\n");
			free_graph(graph);
		}
	}
}

int 				ParamMain(char **av) {
	T_Graph *graph;
	int algo;


	if (strcmp(av[2], "-w") == 0)
		algo = 0;
	else if (strcmp(av[2], "-g") == 0)
		algo = 1;
	else {
		fprintf(stderr, "L'option %s n'existe pas.\n", av[2]);
		return 1;
	}

	if ((graph = Read_Graph_File(av[1]))) {
		SetFullGraph(graph, algo);
		free_graph(graph);
	}
	else
		fprintf(stderr, "Impossible d'ouvrir le fichier %s\n", av[1]);

	return 0;
}

int         main(int ac, char **av) {
	if (ac == 3)
		return ParamMain(av);
	else if (ac == 1)
		NoParamMain();
	else
		fprintf(stderr, "Il n'existe que deux façons pour lancer ce programme.\n\n1) Aucun argument : Les paramètres vous seront alors demandés.\n2) Deux argument : Veuillez renseigner un nom de fichier matrice à lire, suivi de -w pour utiliser l'algorithme de Welsh et Powell, ou -g pour l'algorithme Glouton.\n");

  return 0;
}
