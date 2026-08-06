#!/bin/bash

TIMEFORMAT='%U %S'

total_user=0
total_sys=0

for i in {1..10}
do
    t=$( { time ./bsq test2000 > /dev/null; } 2>&1 )

    user=$(echo "$t" | awk '{print $1}')
    sys=$(echo "$t" | awk '{print $2}')

    #echo "Lancement $i : user=${user}s system=${sys}s"

    total_user=$(awk "BEGIN {print $total_user + $user}")
    total_sys=$(awk "BEGIN {print $total_sys + $sys}")
done

echo "Moyenne user   : $(awk "BEGIN {print $total_user / 10}")s"
echo "Moyenne system : $(awk "BEGIN {print $total_sys / 10}")s"
