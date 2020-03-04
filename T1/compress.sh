#!/bin/bash

[[ ! $# -eq 2 ]] && { echo "usage:$0 \path\to\dir ThresholdSize" ; exit 0; }

for dir in $( du -t $2 */ ) ;
do
#[[ -d $dir ]] && {
echo $dir;
echo a;
#ls -s $dir

#}
done

