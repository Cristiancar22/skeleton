HEADERS += \
  chess_board.h \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  file_ply_stl.h \
  hierarchicalObject.h \
  luz.h \
  object3d.h \
  axis.h \
  objetoPly.h \
  revolucion.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  texture.h \
  window.h

SOURCES += \
  basic_object3d.cc \
  chess_board.cpp \
  cone.cpp \
  cube.cpp \
  cylinder.cpp \
  file_ply_stl.cc \
  hierarchicalObject.cpp \
  luz.cpp \
  object3d.cc \
  axis.cc \
  objetoPly.cpp \
  revolucion.cpp \
  sphere.cpp \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  texture.cpp \
  window.cc


INCLUDEPATH += C:\MinGW\

#LIBS += -L/usr/X11R6/lib64 -lGL

LIBS += -lfreeglut

LIBS += -lopengl32
LIBS += -luser32 -lgdi32


CONFIG += c++11
QT += openglwidgets
