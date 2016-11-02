AUTOMAKE_OPTIONS = foreign

lib_LTLIBRARIES = libair.la 
libair_la_SOURCES = MDataFile.cc TimeStampDataFile.cc
libair_la_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(RAPIDJSON_CPPFLAGS) \
		$(JSON_CPPFLAGS)

libair_la_LIBADD = $(BOOST_LIBADD) \
		   $(SOIL_LIBADD) \
	  	   $(JSON_LIBADD)

libair_la_LDFLAGS = \
	-no-undefined -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE) \
	-release $(LT_RELEASE) 

# header files
noinst_HEADERS = AirLog.hh 


