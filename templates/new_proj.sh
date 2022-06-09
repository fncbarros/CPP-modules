new_folder=$1
name=$2
#from Erick:
name_upper="$(tr '[:lower:]' '[:upper:]' <<< ${name})"

mkdir $new_folder/inc/
cp Makefile $new_folder
cp Class.cpp $new_folder/$name.cpp
cp ./inc/Class.hpp $new_folder/inc/$name.hpp
cd $new_folder
<< EOF >> main.cpp \
\
#include "Class.hpp"\
\
int main()\
{\
	return (0);\
}\
\
EOF

sed -i '{s/Class/'$name'/g}' $name.cpp
sed -i '{s/Class/'$name'/g}' inc/$name.hpp
sed -i '{s/CLASS/'$name_upper'/g}' inc/$name.hpp

cd --

echo $name >> ../.gitignore

##idea: prompt for exe name number of classes and name them individually