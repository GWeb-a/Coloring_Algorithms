#include      <stdlib.h>
#include      <stdio.h>
#include      "../graph/graph.h"

int           Get_Max_Color(T_Coloring coloring, int nb_vertex) {
  int max_color = 1;

  for (int i = 0; i < nb_vertex;i++) {
    if (coloring[i] > max_color) {
      max_color = coloring[i];
    }
  }
  return max_color;
}

int           Is_Coloring_Correct(T_Graph *graph, T_Coloring *coloring) {
  for (int i = 0; i < graph->nb_vertex; i++) {
    for (int j = i; j < graph->nb_vertex; j++) {
      if (graph->matrix[i][j] == '1' && (*coloring)[i] == (*coloring)[j] && i != j) {
        return 0;
      }
    }
  }
  return 1;
}

T_Coloring 	  *Read_Coloring_File(char *filename) {
	T_Coloring *coloring = (T_Coloring *)malloc(sizeof(T_Coloring));
	FILE *file = NULL;
	int rows;

	file = fopen(filename, "r");
	if (file != NULL) {
		/* Get nb rows */
		fscanf(file, "%d", &rows);
		fgetc(file);
		Init_Coloring(coloring, rows);
		for (int i = 0; i < rows; i++) {
			int tmp = fgetc(file);
			(*coloring)[i] = tmp - 48;
		}
		fclose(file);
	}
	else
		return NULL;

	return coloring;
}

int           Get_Vertex_Color(T_Coloring coloring, int vertex) {
  return coloring[vertex];
}

void          Destroy_Coloring(T_Coloring *coloring) {
  free(*coloring);
  *coloring = NULL;
}

void          Init_Coloring(T_Coloring *coloring, int nb_vertex) {
  *coloring = (T_Coloring)malloc(sizeof(int) * (nb_vertex + 1));

  for (int i = 0; i < nb_vertex; i++) {
    (*coloring)[i] = COLORLESS;
  }
}
