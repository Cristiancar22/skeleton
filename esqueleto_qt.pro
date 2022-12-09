HEADERS += \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  file_ply_stl.h \
  object3d.h \
  axis.h \
  objetoPly.h \
  revolucion.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  window.h

SOURCES += \
  basic_object3d.cc \
  cone.cpp \
  cube.cpp \
  cylinder.cpp \
  file_ply_stl.cc \
  object3d.cc \
  axis.cc \
  objetoPly.cpp \
  revolucion.cpp \
  sphere.cpp \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc

INCLUDEPATH += C:\Users\ablin\OneDrive\Escritorio\GL

#LIBS += -L/usr/X11R6/lib64 -lGL
LIBS += -lopengl32


CONFIG += c++11
QT += openglwidgets
