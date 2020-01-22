#include      <stdlib.h>
#include 		  <stdio.h>
#include 			<string.h>
#include			<time.h>
#include      "graph.h"
#include 			"../welsh_powell/welsh_powell.h"
#include 			"../greedy/greedy.h"

void 					free_graph(T_Graph *graph) {
	for (int i = 0; i < graph->nb_vertex; i++) {
		free(graph->matrix[i]);
	}
	free(graph->matrix);
	free(graph->degrees);
}

int 					Check_Symetry(T_Graph *graph) {
	for (int i = 0; i < graph->nb_vertex; i++) {
		for (int j = 0; j < graph->nb_vertex; j++) {
			if (graph->matrix[i][j] != graph->matrix[j][i])
				return 0;
		}
	}
	return 1;
}

T_Graph 			*Create_Random_Symetric_Graph(int nb_vertex) {
	T_Graph *graph = (T_Graph *)malloc(sizeof(T_Graph));
	int value;

	Init_Graph(graph, nb_vertex);
	srand(time(NULL));

	for (int i = 0; i < nb_vertex; i++) {
		for (int j = i; j < nb_vertex; j++) {
			value = rand() % 2 + 48;
			graph->matrix[i][j] = value;
			graph->matrix[j][i] = value;
		}
	}

	return graph;
}

int 					Are_Linked(char **matrix, int a, int b) {
	if (matrix[a][b] == '1')
		return 1;
	if (matrix[b][a] == '1')
		return 1;
	return 0;
}

void 					Print_Matrix(T_Graph *graph) {
	printf("-------- Matrice du Graph --------\n\n");
	for (int i = 0; i < graph->nb_vertex; i++) {
		for (int j = 0; j < graph->nb_vertex; j++) {
			printf("%c ", graph->matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void          Print_Graph(T_Graph* graph, T_Coloring *coloring) {
	printf("-------- Liens et couleurs du Graph --------\n\n");
	for (int i = 0; i < graph->nb_vertex; i++) {
		for (int j = i; j < graph->nb_vertex; j++) {
			if (graph->matrix[i][j] == '1') {
				printf("%d(%d) <--> %d(%d)\n", i, (*coloring)[i], j, (*coloring)[j]);
			}
		}
	}
	printf("\n");
}

T_Graph 		  *Read_Graph_File(char *filename) {
	FILE *file = NULL;
	int rows;
	T_Graph *graph = (T_Graph *)malloc(sizeof(T_Graph));

  file = fopen(filename, "r");
	if (file != NULL) {
		/* Get nb rows */
		fscanf(file, "%d", &rows);
		fgetc(file);
		Init_Graph(graph, rows);
		for (int i = 0; i < graph->nb_vertex; i++) {
			for (int j = 0; j < graph->nb_vertex; j++) {
				graph->matrix[i][j] = fgetc(file);
			}
			fgetc(file);
		}
		fclose(file);
	}
	else
		return NULL;

	return graph;
}

void 				  Write_Graph(T_Graph *graph, char *path) {
	FILE *file = NULL;
	char buffer[6];

	file = fopen(path, "w");
	if (file != NULL) {
		sprintf(buffer, "%d", graph->nb_vertex);
		fputs(buffer, file);
		fputc('\n', file);
		for (int i = 0; i < graph->nb_vertex; i++) {
			for (int j = 0; j < graph->nb_vertex; j++) {
				fputc(graph->matrix[i][j], file);
			}
			fputc('\n', file);
		}
		fclose(file);
	}
}

void          Remove_Edge(T_Graph *graph, int origin, int end) {
  graph->matrix[origin][end] = 0;
  graph->matrix[end][origin] = 0;
}

void          Add_Edge(T_Graph *graph, int origin, int end) {
  graph->matrix[origin][end] = 1;
  graph->matrix[end][origin] = 1;
}

void          Init_Graph(T_Graph *graph, int nb_vertex) {
	graph->nb_vertex = nb_vertex;
	graph->matrix = (char **)malloc(sizeof(char *) * (nb_vertex + 1));
	graph->degrees = (int *)malloc(sizeof(int) * (nb_vertex + 1));
	for (int i = 0; i < nb_vertex; i++) {
		graph->matrix[i] = (char *)malloc(sizeof(char) * (nb_vertex + 1));
		for (int j = 0; j < nb_vertex; j++) {
			graph->matrix[i][j] = '0';
		}
		graph->degrees[i] = 0;
	}
}

void 					SetFullGraph(T_Graph *graph, int algo) {
	T_Coloring coloring;

	if (algo == 1)
	 	coloring = Greedy_Search(graph);
	else
		coloring = Welsh_Powell(graph);

	Print_Matrix(graph);
	if (Is_Coloring_Correct(graph, &coloring) == 1) {
		if (algo == 1)
			printf("La coloration de Glouton a été effectuée avec succès et a généré %d couleurs.\n\n", Get_Max_Color(coloring, graph->nb_vertex));
		else
			printf("La coloration de Welsh et Powell a été effectuée avec succès et a généré %d couleurs.\n\n", Get_Max_Color(coloring, graph->nb_vertex));
	}
	else {
		fprintf(stderr, "La coloration de Welsh et Powell a échoué et entraîné une mauvaise coloration.\n");
	}
	free(coloring);
}
