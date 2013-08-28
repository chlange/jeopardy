#!/bin/bash

# Replace control characters with compatible characters
# Version 0.1

# replace new lines with [b] and spaces with
# replace three spaces with html non breaking spaces
# replace two spaces with html non breaking spaces
# replace "<" with html encoded "<"
# replace tab with html encoded spaces

# both parameter defined
if [ $# -eq 2 ]; then
	if [ -f $1 ]
	then
		if [ $2 == "y" ]
		then
			sed -i -e ':a;N;$!ba;s/\n/[b]/g' -e 's/   /[s][s][s]/g' -e 's/   //g' -e 's/  /[s][s]/g' -e 's/  //g' -e 's/</\&lt;/g' -e 's/<//g' -e 's/	/[s][s][s]/g' -e 's/\[b\] /\[b\][s][s][s]/g' $1
		else
			sed -e ':a;N;$!ba;s/\n/[b]/g' -e 's/   /[s][s][s]/g' -e 's/   //g' -e 's/  /[s][s]/g' -e 's/  //g' -e 's/</\&lt;/g' -e 's/<//g' -e 's/	/[s][s][s]/g' -e 's/\[b\] /\[b\][s][s][s]/g' $1
		fi
	else
		echo "File doesnt exist"
	fi
# just first parameter defined
# output to console
elif [ $# -eq 1 ]; then
	if [ -f $1 ]
	then
		sed -e ':a;N;$!ba;s/\n/[b]/g' -e 's/   /[s][s][s]/g' -e 's/   //g' -e 's/  /[s][s]/g' -e 's/  //g' -e 's/</\&lt;/g' -e 's/<//g' -e 's/	/[s][s][s]/g' -e 's/\[b\] /\[b\][s][s][s]/g' $1
	else
		echo "File doesnt exist"
	fi
else
	echo -e "Usage: $0 filename overwriteFile(y/n)"
	echo -e ""
	echo -e "Parameter"
	echo -e "   filename: File to convert"
	echo -e "   overwriteFile: Overwrite file directly (y) or write to console (default)"
fi
