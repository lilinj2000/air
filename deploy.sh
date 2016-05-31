#! /bin/sh

home_libs=~/libs

home_air=${home_libs}/air

./configure --prefix=${home_air}

if test -d ${home_air}; then
    rm -rf ${home_air}
fi

make install

make distclean
