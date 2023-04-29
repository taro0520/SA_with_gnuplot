run=30
iteration=1000
bit=100
temperature=1000
alpha=0.99
filename="test1.gp"

./SA $run $iteration $bit $temperature $alpha > $filename
gnuplot -persist $filename