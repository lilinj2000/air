AUTOMAKE_OPTIONS = foreign

check_PROGRAMS = unittest

unittest_SOURCES = \
	MDataFileTest.cc \
	TimeStampDataFileTest.cc

unittest_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(GTEST_CPPFLAGS) \
		$(SOIL_CPPFLAGS)


unittest_LDADD = \
	$(GTEST_LIBADD) \
	../libs/libair.la \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD)


unittest_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = 


