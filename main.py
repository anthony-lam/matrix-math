from display import *
from draw import *
from matrix import *

screen = new_screen()
color = [ 0, 255, 0 ]
matrix = new_matrix()

matrix[0][0] = 4

 
draw_lines( matrix, screen, color )
display(screen)
