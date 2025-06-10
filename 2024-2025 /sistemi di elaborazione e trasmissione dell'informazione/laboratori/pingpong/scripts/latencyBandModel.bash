#! /bin/bash
# Expect protocol name as first parameter (tcp or udp)

# Define input and output file names
ThroughFile="../data/$1_throughput.dat";
PngName="../data/LB$1.png";

#getting the first and the last line of the file
HeadLine=($(head $ThroughFile --lines=1))
TailLine=($(tail $ThroughFile --lines=1))

#getting the information from the first and the last line
FirstN=${HeadLine[0]}
LastN=${TailLine[0]}

# TO BE DONE START

# Estrai throughput (T(N1) e T(N2)) dalla prima e ultima riga
T1=${HeadLine[1]}  # Throughput per N1
T2=${TailLine[1]}  # Throughput per N2

# Calcola delay: D(N) = N / T(N)
D1=$(echo "scale=9; $FirstN / $T1" | bc)
D2=$(echo "scale=9; $LastN / $T2" | bc)

# Calcola B e L0
Band=$(echo "scale=9; ($LastN - $FirstN) / ($D2 - $D1)" | bc)
Latency=$(echo "scale=9; ($D1 * $LastN - $D2 * $FirstN) / ($LastN - $FirstN)" | bc)

# TO BE DONE END


# Plotting the results
gnuplot <<-eNDgNUPLOTcOMMAND
  set term png size 900, 700
  set output "${PngName}"
  set logscale x 2
  set logscale y 10
  set xlabel "msg size (B)"
  set ylabel "throughput (KB/s)"
  set xrange[$FirstN:$LastN]
  lbmodel(x)= x / ($Latency + (x/$Band))

# TO BE DONE START

# Definizione e tracciamento del modello banda-latenza
  plot "${ThroughFile}" using 1:2 title "Misurato Throughput" with linespoints, \
       lbmodel(x) title "Modello Banda-Latenza con L=${Latency} e B=${Band}" with linespoints

# TO BE DONE END

  clear

eNDgNUPLOTcOMMAND
