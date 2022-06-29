new_folder=$1
name=$2
script_location="$(pwd)"
#from Erick:
name_upper="$(tr '[:lower:]' '[:upper:]' <<< ${name})"

mkdir $new_folder/inc/
mkdir $new_folder/src/
cp Makefile $new_folder
cp ./src/Class.cpp $new_folder/src/$name.cpp
cp ./inc/Class.hpp $new_folder/inc/$name.hpp
cd $new_folder

cat << eof >> src/main.cpp

#include "Class.hpp"

int main()
{
	return (0);
}

eof

sed -i '{s/Class/'$name'/g}' src/$name.cpp;
sed -i '{s/Class/'$name'/g}' src/main.cpp;
sed -i '{s/Class/'$name'/g}' inc/$name.hpp;
sed -i '{s/CLASS/'$name_upper'/g}' inc/$name.hpp;
sed -i '{s/#placeholder/'$name'/g}' Makefile

cd $script_location

echo $name >> ../.gitignore

##idea: prompt for exe name number of classes and name them individually
