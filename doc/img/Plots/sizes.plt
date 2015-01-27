cd 'd:\psopp\sizes\report'
set terminal jpeg large font arial size 1200, 1800
set output "plot.jpg"
set multiplot layout 4, 1
set lmargin at screen 0.1
#set yrange[] reverse
set xlabel "Step count" offset 40,0,0
set ylabel "f(x)"
set title "Rosenbrock"
plot '03.dat' using 1:5 with line title "10 particles", '03.dat' using 1:4 with line title "20 particles", '03.dat' using 1:3 with line title "50 particles", '03.dat' using 1:2 with line title "100 particles"
set title "Sphere"
plot '02.dat' using 1:5 with line title "10 particles", '02.dat' using 1:4 with line title "20 particles", '02.dat' using 1:3 with line title "50 particles", '02.dat' using 1:2 with line title "100 particles"
set title "StyblinskiTang"
plot '01.dat' using 1:5 with line title "10 particles", '01.dat' using 1:4 with line title "20 particles", '01.dat' using 1:3 with line title "50 particles", '01.dat' using 1:2 with line title "100 particles"
set title "Ackley"
plot '00.dat' using 1:5 with line title "10 particles", '00.dat' using 1:4 with line title "20 particles", '00.dat' using 1:3 with line title "50 particles", '00.dat' using 1:2 with line title "100 particles"
unset multiplot
