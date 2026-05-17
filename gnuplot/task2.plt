set terminal pdfcairo
set output "task2.pdf"

set title 'Студенты 2-го курса'
set ylabel 'Кол-во'
set yrange [0:*]

set style data histograms
set style fill solid 0.9 border -1
set boxwidth 1 relative
set grid

plot 'histo_data.txt' using 2:xtic(1) lc rgb "green" title 'Результаты'