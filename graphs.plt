 #
 # Made by:
 # Gustavo Magallanes-Guijón <gustavo.magallanes.guijon@ciencias.unam.mx>
 # Instituto de Astronomia UNAM
 # Ciudad Universitaria
 # Ciudad de Mexico
 # Mexico
 # mar dic 22 22:43:09 CST 2020
 #

set terminal png
set output 'friedman.png'

set title "Friedman Equation's Solutions"
set grid

#set style data linespoints
set style data lines

set xlabel "Time (Gy)"
set ylabel "a(t)"
set xrange[13:14]
set yrange[1:12]

plot "friedman_all.dat" u 2:1 title "{/Symbol W}_m (0.25)+ {/Symbol W}_r (8.2e-5)+ {/Symbol W_L} (0.75) + {/Symbol W}_K = 1" , \
"friedman_m.dat" u 2:1 title "{/Symbol W}_m (0.25)",	\
"friedman_l.dat" u 2:1 title "{/Symbol W_L} (0.75)"#,	\
"friedman_m_l.dat" u 2:1 title "{/Symbol W}_m (0.25) + {/Symbol W_L} (0.75)"

#"friedman_r.dat" u 2:1 title "{/Symbol W}_r (8.2e-5)"#,  \
#plot "friedman_all.dat" u 2:1 title "{/Symbol W}_m + {/Symbol W}_r + {/Symbol W_L} + {/Symbol W}_K" , \
#"friedman_k.dat" u 2:1 title "{/Symbol W_K}",	\
