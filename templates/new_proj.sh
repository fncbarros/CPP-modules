new_folder=$1
name=$2
#from Erick:
name_upper="$(tr '[:lower:]' '[:upper:]' <<< ${name})"

mkdir $new_folder/inc/
cp Makefile Class.cpp $new_folder
cp ./inc/Class.hpp $new_folder/inc/
cd $new_folder
<< EOF >> main.cpp

#include "Class.hpp"

int main()
{
	return (0);
}

EOF

sed -i 's/Class/$name/g' Class.cpp
sed -i 's/Class/$name/g' inc/Class.hpp
sed -i 's/CLASS/$name_upper/g' inc/Class.hpp

