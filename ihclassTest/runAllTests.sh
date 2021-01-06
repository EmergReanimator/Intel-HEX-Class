#!/usr/bin/env bash

files=`ls ./hex/*.[hH][eE][xX]` 

for inp in $files; do
	out="${inp##*/}"
	bin="out/${out%.[^.]*}.bin"
	txt="out/${out%.[^.]*}.txt"
	echo "... Running ./intelhextest "$inp" "$bin""
	./intelhextest "$inp" "$bin" 1>"$txt"
	echo -e "... Done.\n"
done
