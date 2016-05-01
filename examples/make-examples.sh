#!/bin/bash
rm output/*
for i in `ls *.atd` ; do 
  ../atdtocpp $i ./output/${i}.cpp ./output/${i}.h
  ../atdparamconv $i ./output/${i}.ml
done;
