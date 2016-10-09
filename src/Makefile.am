bin_PROGRAMS = cdc

cdc_LDFLAGS = $(LDFLAGS)
cdc_LDADD = $(GLIB_LIBS) $(GIO_LIBS) $(CDPFGL_LIBS)

#cdc_HEADERFILES =  cdc.h       

cdc_SOURCES =  cdc.c \
	       cdc.h \
	       options.c \
	       options.h 


AM_CPPFLAGS = $(GLIB_CFLAGS) $(GIO_CFLAGS) $(CDPFGL_CFLAGS)
