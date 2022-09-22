HEADERS += \
  colors.h \
  basic_object3d.h \
  cube.h \
  object3d.h \
  axis.h \
  tetrahedron.h \
  glwidget.h \
  window.h

SOURCES += \
  basic_object3d.cc \
  cube.cpp \
  object3d.cc \
  axis.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc

INCLUDEPATH += C:\Users\ablin\Desktop\Universidad\IG\Practicas\GL

#LIBS += -L/usr/X11R6/lib64 -lGL
LIBS += -lopengl32


CONFIG += c++11
QT += openglwidgets
