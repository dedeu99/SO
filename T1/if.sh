#!/bin/bash
if [ $# -le 0 ] ; then
echo "Sem parâmetros"
elif [ "$#" =="1" ] ; then
echo "Um parâmetro"
else
echo "Mais que um parâmetro"
fi
