#!/bin/bash

norminette -R CheckForbiddenSourceHeader

cc -Wall -Werror -Wextra *.c -o rush-01
EXEC=./rush-01

echo "===== Parsing ====="

echo "1. Aucun argument"
$EXEC

echo "2. Trop d'arguments"
$EXEC "4 3 2 1 2 2 1 3 2 2 3 1 1 2 2 2" test

echo "3. Argument vide"
$EXEC ""

echo "4. Seulement des espaces"
$EXEC "                               "

echo "5. 15 indices"
$EXEC "4 3 2 1 2 2 1 3 2 2 3 1 1 2 2"

echo "6. 17 indices"
$EXEC "4 3 2 1 2 2 1 3 2 2 3 1 1 2 2 2 1"

echo "7. Lettre"
$EXEC "4 3 2 a 2 2 1 3 2 2 3 1 1 2 2 2"

echo "8. Valeur = 0"
$EXEC "4 3 0 1 2 2 1 3 2 2 3 1 1 2 2 2"

echo "9. Valeur = 5"
$EXEC "4 3 5 1 2 2 1 3 2 2 3 1 1 2 2 2"

echo "10. Double espace"
$EXEC "4  3 2 1 2 2 1 3 2 2 3 1 1 2 2 2"

echo "11. Espace au début"
$EXEC " 4 3 2 1 2 2 1 3 2 2 3 1 1 2 2 2"

echo "12. Espace à la fin"
$EXEC "4 3 2 1 2 2 1 3 2 2 3 1 1 2 2 2 "

echo "13. Tabulations"
$EXEC $'4\t3\t2\t1\t2\t2\t1\t3\t2\t2\t3\t1\t1\t2\t2\t2'

echo "===== Solveur ====="

echo "14. Puzzle impossible"
$EXEC "4 4 4 4 4 4 4 4 1 1 1 1 1 1 1 1"

echo "15. Puzzle valide"
$EXEC "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

echo "===== Mémoire ====="

valgrind --leak-check=full --error-exitcode=42 \
$EXEC "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

rm rush-01
