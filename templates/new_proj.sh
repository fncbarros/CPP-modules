new_folder=$1
name=$2

mkdir $new_folder/inc/
cp Makefile Class.cpp $new_folder
cp ./inc/Class.hpp $new_folder/inc/
