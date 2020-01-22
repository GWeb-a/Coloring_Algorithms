#include    <stdio.h>
#include    <stdlib.h>
#include    "greedy.h"
#include    "../coloring/coloring.h"
#include    "../welsh_powell/welsh_powell.h"

int         Is_Color_In_Array(int color, T_Coloring colors, int nb_vertex) {
  for (int i = 0; i < nb_vertex; i++) {
    if (colors[i] == color)
      return 1;
  }

  return 0;
}

int         Get_Min_Free_Color(T_Coloring colors, int nb_vertex) {
  int color = 1;

  while (color < nb_vertex) {
    if (!Is_Color_In_Array(color, colors, nb_vertex)) {
      return color;
    }
    color++;
  }
  return color;
}

T_Coloring  Get_Linked_Colors(T_Graph *graph, T_Coloring coloring, T_Coloring colors, int vertex) {
  int c = 0;

  for (int i = 0; i < graph->nb_vertex; i++) {
    if (Are_Linked(graph->matrix, i, vertex) && i != vertex && coloring[i] != -1) {
      colors[c] = coloring[i];
      c++;
    }
  }
  return colors;
}

void        Greedy_Coloring(T_Graph *graph, T_Coloring *coloring) {
  (*coloring)[0] = 1;
  /* On boucle sur tous nos sommets */
  for (int i = 0; i < graph->nb_vertex; i++) {
    T_Coloring colors;
    Init_Coloring(&colors, graph->nb_vertex);
    /* Tant qu'on ne peut pas colorer à cause des sommets adjacents */
    colors = Get_Linked_Colors(graph, *coloring, colors, i);
    Color_Vertex(coloring, i, Get_Min_Free_Color(colors, graph->nb_vertex));
    free(colors);
  }
}

T_Coloring  Greedy_Search(T_Graph *graph) {
  T_Coloring coloring;

  Init_Coloring(&coloring, graph->nb_vertex);
  Greedy_Coloring(graph, &coloring);

  return coloring;
}
