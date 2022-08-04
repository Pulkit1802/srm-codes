#!/usr/bin/bash
i=1
for i in mon tue wed thurs fri sat 
do
    if [ $i == fri ] || [ $i == sat ]
    then
        echo weekend: $i
    else
        echo weekday: $i
    fi
done