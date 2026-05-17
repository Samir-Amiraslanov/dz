set terminal pdfcairo
set output "task1.pdf"


set title 'График по расчетным данным'
set xlabel 'Ось X'
set ylabel 'Ось Y'
set grid

 

plot 'data.txt' using 1:2 with linespoints lw 2 pt 7 lc rgb "red" title 'Расчетные значения'