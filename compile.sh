/*
 # Made by:
 # Gustavo Magallanes-Guijón <gustavo.magallanes.guijon@ciencias.unam.mx>
 # Instituto de Astronomia UNAM
 # Ciudad Universitaria
 # Ciudad de Mexico
 # Mexico
 # mar dic 22 22:43:09 CST 2020
*/

gcc -o friedmann friedmann.c -lm
./friedmann
gnuplot graphs.plt
