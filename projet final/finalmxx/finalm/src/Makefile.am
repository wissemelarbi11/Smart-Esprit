## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = finalm

finalm_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	treeview1.c treeview1.h \
	fonctionseif.c fonctionseif.h \
	fonctionaz.c fonctionaz.h \
	fonction.c fonction.h \
	utilisateur.c utilisateur.h \
	capteur.c capteur.h \
	fonctionahmadac.c fonctionahmadac.h 

finalm_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

