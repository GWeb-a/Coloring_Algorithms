#include    <stdio.h>
#include    <stdlib.h>
#include    "welsh_powell.h"

void        Copy_Int_Array(int *dest, int *src, int *index, int array_length) {
  for (int i = 0; i < array_length; i++) {
    dest[i] = src[i];
    index[i] = i;
  }
}

void         Bubble_Sort(int *array, int *index, int array_length) {
  int tmp;

  for(int i = array_length - 1; i > 0 ; i--) {
    for(int j = 1; j <= i; j++) {
      if(array[j - 1] > array[j]) {
        tmp = array[j - 1];
        array[j - 1] = array[j];
        array[j] = tmp;
        tmp = index[j - 1];
        index[j - 1] = index[j];
        index[j] = tmp;
      }
    }
  }
}

void        Color_Vertex(T_Coloring *coloring, int index, int color) {
  (*coloring)[index] = color;
}

int         Has_No_Linked_Vertex_With_Same_Color(int current_vertex, T_Coloring *coloring, T_Graph *graph, int color) {
  for (int i = 0; i < graph->nb_vertex; i++) {
    /* Si le sommet est lié au sommet que l'on souhaite colorer */
    if (Are_Linked(graph->matrix, current_vertex, i) && i != current_vertex) {
      if ((*coloring)[i] == color) {
        return 0;
      }
    }
  }
  return 1;
}

void        Color_Graph(T_Graph *graph, T_Coloring *coloring, int *index) {
  int color = 1;
  int nb_colored = 0;

  /* Tant que tous les éléments n'ont pas une couleur */
  while (nb_colored != graph->nb_vertex) {

    /* On boucle sur tous nos sommets */
    for (int i = graph->nb_vertex - 1; i >= 0; i--) {
      /* Si le sommet n'est pas déjà coloré */
      if (Get_Vertex_Color(*coloring, index[i]) == COLORLESS) {
        /* Si les sommets liés au sommet actuel n'ont pas la couleur que l'on
        souhaite attribuer au sommet actuel */
        if (Has_No_Linked_Vertex_With_Same_Color(index[i], coloring, graph, color)) {
          /* Alors on peut colorer le vertex */
          Color_Vertex(coloring, index[i], color);
          nb_colored++;
        }
      }
    }
    color++;
  }
}

void        Order_Degrees(T_Graph *graph, T_Coloring *coloring) {
  int *ordered = (int *)malloc(sizeof(int) * (graph->nb_vertex + 1));
  int *index = (int *)malloc(sizeof(int) * (graph->nb_vertex + 1));

  Copy_Int_Array(ordered, graph->degrees, index, graph->nb_vertex);
  Bubble_Sort(ordered, index, graph->nb_vertex);
  Color_Graph(graph, coloring, index);
  free(ordered);
  free(index);
}

T_Coloring  Welsh_Powell(T_Graph *graph) {
  T_Coloring color;
  Init_Coloring(&color, graph->nb_vertex);

  for (int i = 0; i < graph->nb_vertex; i++) {
		for (int j = i; j < graph->nb_vertex; j++) {
			if (graph->matrix[i][j] == '1') {
				graph->degrees[i]++;
        graph->degrees[j]++;
			}
		}
	}

  Order_Degrees(graph, &color);

  return color;
}
