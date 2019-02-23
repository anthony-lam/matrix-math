#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

	screen s;
	color c;
	color g;
	c.red = 255;
	g.green = 255;

	clear_screen(s);

	struct matrix * edges = new_matrix(4, 4);
	struct matrix * grid = new_matrix(4, 4);

	add_edge(edges, 200, 200, 0, 200, 300, 0);
	add_edge(edges, 200, 300, 0, 300, 300, 0);
	add_edge(edges, 300, 300, 0, 300, 200, 0);
	add_edge(edges, 300, 200, 0, 200, 200, 0);


	add_edge(edges, 250, 350, 0, 150, 250, 0);
	add_edge(edges, 150, 250, 0, 250, 150, 0);
	add_edge(edges, 250, 150, 0, 350, 250, 0);
	add_edge(edges, 350, 250, 0, 250, 350, 0);

	add_edge(edges, 150, 150, 0, 350, 150, 0);
	add_edge(edges, 350, 150, 0, 350, 350, 0);
	add_edge(edges, 350, 350, 0, 150, 350, 0);
	add_edge(edges, 150, 350, 0, 150, 150, 0);

	add_edge(edges, 250, 50, 0, 450, 250, 0);
	add_edge(edges, 250, 50, 0, 50, 250, 0);
	add_edge(edges, 50, 250, 0, 250, 450, 0);
	add_edge(edges, 250, 450, 0, 450, 250, 0);

	for(int r =1; r<10 ; r++){
		add_edge(grid, r*50, 0, 0, r*50, 500, 0);
		add_edge(grid,0, r*50, 0, 500,r*50, 0);
	}


	struct matrix * iden = new_matrix(4, 4);
	ident(iden);
	printf("4 by 4 identity matrix:\n");
	print_matrix(iden);
	printf("\n");
	printf("edges:\n");
	print_matrix(edges);
	printf("\n");
	printf("Multiply by identity\n");
  	matrix_mult(iden, edges); // Should have no effect
  	printf("\n");
  	printf("Printing first matrix...\n");
  	print_matrix(edges);
  	printf("Printing second matrix...\n");
  	print_matrix(grid);
  	draw_lines(edges, s, c);
  	printf("Multiply first and second\n");
  	matrix_mult(edges,grid);
  	printf("Printing second\n");
  	print_matrix(grid);
  	free_matrix( edges );
  	free_matrix( grid );
  	display(s);
	save_extension(s, "lines.png");
  }
