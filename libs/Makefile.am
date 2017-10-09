AUTOMAKE_OPTIONS = foreign

lib_LTLIBRARIES = libair.la 
libair_la_SOURCES = MDataFile.cc \
		TimeStampDataFile.cc \
		CearData.cc

libair_la_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(RAPIDJSON_CPPFLAGS) \
		$(FMT_CPPFLAGS) \
		$(READERWRITERQUEUE_CPPFLAGS) \
		$(SPDLOG_CPPFLAGS)

libair_la_LIBADD = $(BOOST_LIBADD) \
		   $(SOIL_LIBADD) \
		   $(FMT_LIBADD)

libair_la_LDFLAGS = \
	-no-undefined -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE) \
	-release $(LT_RELEASE) 

# header files
noinst_HEADERS =


