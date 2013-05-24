#############################################################################
# Makefile for building: cpad
# Generated by qmake (2.01a) (Qt 4.7.2) on: Tue May 21 17:34:17 2013
# Project:  cpad.pro
# Template: app
# Command: /home/user/ti-sdk-am335x-evm-05.04.01.00/linux-devkit/bin/qmake -spec ../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/linux-g++ -o Makefile cpad.pro
#############################################################################

####### Compiler, tools and options

CC            = $(OE_QMAKE_CC)
CXX           = $(OE_QMAKE_CXX)
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe $(OE_QMAKE_CFLAGS) -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe $(OE_QMAKE_CFLAGS) $(OE_QMAKE_CXXFLAGS) -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/linux-g++ -I. -I$(OE_QMAKE_INCDIR_QT)/QtCore -I$(OE_QMAKE_INCDIR_QT)/QtGui -I$(OE_QMAKE_INCDIR_QT) -I. -I. -I.
LINK          = $(OE_QMAKE_LINK)
LFLAGS        = $(OE_QMAKE_LDFLAGS) -Wl,-rpath-link,$(OE_QMAKE_LIBDIR_QT)
LIBS          = $(SUBLIBS)  -L$(OE_QMAKE_LIBDIR_QT) -lQtGuiE -lQtNetworkE -lQtCoreE -lpthread 
AR            = $(OE_QMAKE_AR) cqs
RANLIB        = 
QMAKE         = /home/user/ti-sdk-am335x-evm-05.04.01.00/linux-devkit/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = $(OE_QMAKE_STRIP)
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = centerwidget.cpp \
		codeeditor.cpp \
		findreplacearea.cpp \
		functionfoldarea.cpp \
		functionlistarea.cpp \
		linenumberarea.cpp \
		main.cpp \
		mainwindow.cpp \
		statusbar.cpp \
		syntaxhighlighter.cpp \
		textblockdata.cpp \
		recomposedialog.cpp \
		cpadpalette.cpp \
		autocomple.cpp \
		runcompile.cpp \
		compileconfig.cpp \
		memoryprivate.cpp \
		memorypublic.cpp \
		keyboard/keyboard.cpp moc_centerwidget.cpp \
		moc_codeeditor.cpp \
		moc_findreplacearea.cpp \
		moc_functionfoldarea.cpp \
		moc_functionlistarea.cpp \
		moc_mainwindow.cpp \
		moc_statusbar.cpp \
		moc_syntaxhighlighter.cpp \
		moc_recomposedialog.cpp \
		moc_cpadpalette.cpp \
		moc_autocomple.cpp \
		moc_runcompile.cpp \
		moc_compileconfig.cpp \
		moc_keyboard.cpp \
		qrc_resources.cpp
OBJECTS       = centerwidget.o \
		codeeditor.o \
		findreplacearea.o \
		functionfoldarea.o \
		functionlistarea.o \
		linenumberarea.o \
		main.o \
		mainwindow.o \
		statusbar.o \
		syntaxhighlighter.o \
		textblockdata.o \
		recomposedialog.o \
		cpadpalette.o \
		autocomple.o \
		runcompile.o \
		compileconfig.o \
		memoryprivate.o \
		memorypublic.o \
		keyboard.o \
		moc_centerwidget.o \
		moc_codeeditor.o \
		moc_findreplacearea.o \
		moc_functionfoldarea.o \
		moc_functionlistarea.o \
		moc_mainwindow.o \
		moc_statusbar.o \
		moc_syntaxhighlighter.o \
		moc_recomposedialog.o \
		moc_cpadpalette.o \
		moc_autocomple.o \
		moc_runcompile.o \
		moc_compileconfig.o \
		moc_keyboard.o \
		qrc_resources.o
DIST          = ../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/common/g++.conf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/common/unix.conf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/common/linux.conf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/qconfig.pri \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/qt_functions.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/qt_config.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/exclusive_builds.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/default_pre.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/release.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/default_post.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/warn_on.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/qt.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/unix/thread.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/moc.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/resources.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/uic.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/yacc.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/lex.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/include_source_dir.prf \
		cpad.pro
QMAKE_TARGET  = cpad
DESTDIR       = 
TARGET        = cpad

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_keyboard.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: cpad.pro  ../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/linux-g++/qmake.conf ../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/common/g++.conf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/common/unix.conf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/common/linux.conf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/qconfig.pri \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/qt_functions.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/qt_config.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/exclusive_builds.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/default_pre.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/release.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/default_post.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/warn_on.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/qt.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/unix/thread.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/moc.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/resources.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/uic.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/yacc.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/lex.prf \
		../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/include_source_dir.prf \
		/home/user/ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/lib/libQtGuiE.prl \
		/home/user/ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/lib/libQtNetworkE.prl \
		/home/user/ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/lib/libQtCoreE.prl
	$(QMAKE) -spec ../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/linux-g++ -o Makefile cpad.pro
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/common/g++.conf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/common/unix.conf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/common/linux.conf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/qconfig.pri:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/qt_functions.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/qt_config.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/exclusive_builds.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/default_pre.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/release.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/default_post.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/warn_on.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/qt.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/unix/thread.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/moc.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/resources.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/uic.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/yacc.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/lex.prf:
../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/features/include_source_dir.prf:
/home/user/ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/lib/libQtGuiE.prl:
/home/user/ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/lib/libQtNetworkE.prl:
/home/user/ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/lib/libQtCoreE.prl:
qmake:  FORCE
	@$(QMAKE) -spec ../../ti-sdk-am335x-evm-05.04.01.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/linux-g++ -o Makefile cpad.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/cpad1.0.0 || $(MKDIR) .tmp/cpad1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/cpad1.0.0/ && $(COPY_FILE) --parents centerwidget.h codeeditor.h findreplacearea.h functionfoldarea.h functionlistarea.h linenumberarea.h mainwindow.h statusbar.h syntaxhighlighter.h textblockdata.h recomposedialog.h cpadpalette.h autocomple.h runcompile.h compileconfig.h memorycenter.h memorystruct.h keyboard/ui_keyboard.h keyboard/keyboard.h .tmp/cpad1.0.0/ && $(COPY_FILE) --parents resources.qrc .tmp/cpad1.0.0/ && $(COPY_FILE) --parents centerwidget.cpp codeeditor.cpp findreplacearea.cpp functionfoldarea.cpp functionlistarea.cpp linenumberarea.cpp main.cpp mainwindow.cpp statusbar.cpp syntaxhighlighter.cpp textblockdata.cpp recomposedialog.cpp cpadpalette.cpp autocomple.cpp runcompile.cpp compileconfig.cpp memoryprivate.cpp memorypublic.cpp keyboard/keyboard.cpp .tmp/cpad1.0.0/ && $(COPY_FILE) --parents keyboard/keyboard.ui .tmp/cpad1.0.0/ && (cd `dirname .tmp/cpad1.0.0` && $(TAR) cpad1.0.0.tar cpad1.0.0 && $(COMPRESS) cpad1.0.0.tar) && $(MOVE) `dirname .tmp/cpad1.0.0`/cpad1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/cpad1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_centerwidget.cpp moc_codeeditor.cpp moc_findreplacearea.cpp moc_functionfoldarea.cpp moc_functionlistarea.cpp moc_mainwindow.cpp moc_statusbar.cpp moc_syntaxhighlighter.cpp moc_recomposedialog.cpp moc_cpadpalette.cpp moc_autocomple.cpp moc_runcompile.cpp moc_compileconfig.cpp moc_keyboard.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_centerwidget.cpp moc_codeeditor.cpp moc_findreplacearea.cpp moc_functionfoldarea.cpp moc_functionlistarea.cpp moc_mainwindow.cpp moc_statusbar.cpp moc_syntaxhighlighter.cpp moc_recomposedialog.cpp moc_cpadpalette.cpp moc_autocomple.cpp moc_runcompile.cpp moc_compileconfig.cpp moc_keyboard.cpp
moc_centerwidget.cpp: codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		syntaxhighlighter.h \
		centerwidget.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) centerwidget.h -o moc_centerwidget.cpp

moc_codeeditor.cpp: textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		codeeditor.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) codeeditor.h -o moc_codeeditor.cpp

moc_findreplacearea.cpp: codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		findreplacearea.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) findreplacearea.h -o moc_findreplacearea.cpp

moc_functionfoldarea.cpp: codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		functionfoldarea.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) functionfoldarea.h -o moc_functionfoldarea.cpp

moc_functionlistarea.cpp: codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		functionlistarea.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) functionlistarea.h -o moc_functionlistarea.cpp

moc_mainwindow.cpp: centerwidget.h \
		codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		syntaxhighlighter.h \
		functionlistarea.h \
		findreplacearea.h \
		statusbar.h \
		recomposedialog.h \
		autocomple.h \
		runcompile.h \
		compileconfig.h \
		mainwindow.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_statusbar.cpp: codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		statusbar.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) statusbar.h -o moc_statusbar.cpp

moc_syntaxhighlighter.cpp: syntaxhighlighter.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) syntaxhighlighter.h -o moc_syntaxhighlighter.cpp

moc_recomposedialog.cpp: codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		recomposedialog.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) recomposedialog.h -o moc_recomposedialog.cpp

moc_cpadpalette.cpp: cpadpalette.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) cpadpalette.h -o moc_cpadpalette.cpp

moc_autocomple.cpp: codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		autocomple.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) autocomple.h -o moc_autocomple.cpp

moc_runcompile.cpp: codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		compileconfig.h \
		runcompile.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) runcompile.h -o moc_runcompile.cpp

moc_compileconfig.cpp: compileconfig.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) compileconfig.h -o moc_compileconfig.cpp

moc_keyboard.cpp: keyboard/keyboard.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) keyboard/keyboard.h -o moc_keyboard.cpp

compiler_rcc_make_all: qrc_resources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resources.cpp
qrc_resources.cpp: resources.qrc \
		resources/open.png \
		resources/help.png \
		resources/replace.png \
		resources/redo.png \
		resources/donkey32.png \
		resources/build.png \
		resources/autocomple.png \
		resources/find.png \
		resources/functioncomment.png \
		resources/delete.png \
		resources/splash.png \
		resources/saveas.png \
		resources/paste.png \
		resources/color.png \
		resources/save.png \
		resources/recompose.png \
		resources/next.png \
		resources/recentfile.png \
		resources/undo.png \
		resources/selectall.png \
		resources/new.png \
		resources/copy.png \
		resources/cut.png \
		resources/font.png \
		resources/previous.png \
		resources/run.png \
		resources/quickcomment.png \
		resources/functionlist.png
	$(OE_QMAKE_RCC) -name resources resources.qrc -o qrc_resources.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_keyboard.h
compiler_uic_clean:
	-$(DEL_FILE) ui_keyboard.h
ui_keyboard.h: keyboard/keyboard.ui
	$(OE_QMAKE_UIC) keyboard/keyboard.ui -o ui_keyboard.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

centerwidget.o: centerwidget.cpp centerwidget.h \
		codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		syntaxhighlighter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o centerwidget.o centerwidget.cpp

codeeditor.o: codeeditor.cpp codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		linenumberarea.h \
		functionfoldarea.h \
		runcompile.h \
		compileconfig.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o codeeditor.o codeeditor.cpp

findreplacearea.o: findreplacearea.cpp findreplacearea.h \
		codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o findreplacearea.o findreplacearea.cpp

functionfoldarea.o: functionfoldarea.cpp functionfoldarea.h \
		codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o functionfoldarea.o functionfoldarea.cpp

functionlistarea.o: functionlistarea.cpp functionlistarea.h \
		codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o functionlistarea.o functionlistarea.cpp

linenumberarea.o: linenumberarea.cpp linenumberarea.h \
		codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o linenumberarea.o linenumberarea.cpp

main.o: main.cpp mainwindow.h \
		centerwidget.h \
		codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		syntaxhighlighter.h \
		functionlistarea.h \
		findreplacearea.h \
		statusbar.h \
		recomposedialog.h \
		autocomple.h \
		runcompile.h \
		compileconfig.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		centerwidget.h \
		codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		syntaxhighlighter.h \
		functionlistarea.h \
		findreplacearea.h \
		statusbar.h \
		recomposedialog.h \
		autocomple.h \
		runcompile.h \
		compileconfig.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

statusbar.o: statusbar.cpp statusbar.h \
		codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o statusbar.o statusbar.cpp

syntaxhighlighter.o: syntaxhighlighter.cpp syntaxhighlighter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o syntaxhighlighter.o syntaxhighlighter.cpp

textblockdata.o: textblockdata.cpp textblockdata.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o textblockdata.o textblockdata.cpp

recomposedialog.o: recomposedialog.cpp recomposedialog.h \
		codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o recomposedialog.o recomposedialog.cpp

cpadpalette.o: cpadpalette.cpp cpadpalette.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cpadpalette.o cpadpalette.cpp

autocomple.o: autocomple.cpp autocomple.h \
		codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o autocomple.o autocomple.cpp

runcompile.o: runcompile.cpp runcompile.h \
		codeeditor.h \
		textblockdata.h \
		memorycenter.h \
		memorystruct.h \
		cpadpalette.h \
		compileconfig.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o runcompile.o runcompile.cpp

compileconfig.o: compileconfig.cpp compileconfig.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o compileconfig.o compileconfig.cpp

memoryprivate.o: memoryprivate.cpp memorycenter.h \
		memorystruct.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o memoryprivate.o memoryprivate.cpp

memorypublic.o: memorypublic.cpp memorycenter.h \
		memorystruct.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o memorypublic.o memorypublic.cpp

keyboard.o: keyboard/keyboard.cpp keyboard/keyboard.h \
		keyboard/ui_keyboard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o keyboard.o keyboard/keyboard.cpp

moc_centerwidget.o: moc_centerwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_centerwidget.o moc_centerwidget.cpp

moc_codeeditor.o: moc_codeeditor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_codeeditor.o moc_codeeditor.cpp

moc_findreplacearea.o: moc_findreplacearea.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_findreplacearea.o moc_findreplacearea.cpp

moc_functionfoldarea.o: moc_functionfoldarea.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_functionfoldarea.o moc_functionfoldarea.cpp

moc_functionlistarea.o: moc_functionlistarea.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_functionlistarea.o moc_functionlistarea.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_statusbar.o: moc_statusbar.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_statusbar.o moc_statusbar.cpp

moc_syntaxhighlighter.o: moc_syntaxhighlighter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_syntaxhighlighter.o moc_syntaxhighlighter.cpp

moc_recomposedialog.o: moc_recomposedialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_recomposedialog.o moc_recomposedialog.cpp

moc_cpadpalette.o: moc_cpadpalette.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_cpadpalette.o moc_cpadpalette.cpp

moc_autocomple.o: moc_autocomple.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_autocomple.o moc_autocomple.cpp

moc_runcompile.o: moc_runcompile.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_runcompile.o moc_runcompile.cpp

moc_compileconfig.o: moc_compileconfig.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_compileconfig.o moc_compileconfig.cpp

moc_keyboard.o: moc_keyboard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_keyboard.o moc_keyboard.cpp

qrc_resources.o: qrc_resources.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_resources.o qrc_resources.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/home/root/ || $(MKDIR) $(INSTALL_ROOT)/home/root/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/home/root/$(QMAKE_TARGET)"
	-$(STRIP) "$(INSTALL_ROOT)/home/root/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/home/root/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/home/root/ 


install:  install_target  FORCE

uninstall: uninstall_target   FORCE

FORCE:

