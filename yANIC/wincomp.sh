#!/bin/sh
echo "** Compilation du programme pour windows **"
echo "Etape 1 - Génération du Makefile, vérifiez qu'un dossier win32 existe."
`qmake-qt4 -spec win32-x-g++ -o win32`
echo "Etape 2 - Compilation"
cd win32
make
echo "Etape 3 - Fabrication d'un zip de l'executable"
cd release/bin
zip yanic.zip *
cd ../../..
