#! /bin/sh

node=`uname -n`
home_libs=~/libs/${node}

home_air=${home_libs}/air

./configure --prefix=${home_air}

if test -d ${home_air}; then
    rm -rf ${home_air}
fi

make install

make distclean
