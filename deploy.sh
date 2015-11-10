#! /bin/sh

home_libs=~/libs

if test -d /llj/libs ; then
   home_libs=/llj/libs
fi

home_air=${home_libs}/air

./configure --prefix=${home_air}

if test -d ${home_air}; then
    rm -rf ${home_air}
fi

make install

make distclean
