/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"


using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
    switch(Keyevent->key()){
    case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
    case Qt::Key_2:Object=OBJECT_CUBE;break;
    case Qt::Key_3:Object=OBJECT_CONE;break;
    case Qt::Key_4:Object=OBJECT_CYLINDER;break;
    case Qt::Key_5:Object=OBJECT_SPHERE;break;
    case Qt::Key_6:Object=OBJECT_PLY;break;
    case Qt::Key_7:Object=OBJECT_HIERARCHICAL;break;
    case Qt::Key_8:Object=OBJECT_CHESSBOARD;break;

    case Qt::Key_P:Draw_point=!Draw_point;break;
    case Qt::Key_L:Draw_line=!Draw_line;break;
    case Qt::Key_F:Draw_fill=!Draw_fill;break;

    case Qt::Key_F2:Draw_chess=!Draw_chess;break;
    case Qt::Key_F3:Draw_flat_light=!Draw_flat_light;break;
    case Qt::Key_F4:Draw_smooth_light=!Draw_smooth_light;break;

    //Primer grado de libertad (Ruedas)
    case Qt::Key_Q:Robot.ruedas.animacion = true;update();break;
    case Qt::Key_W:Robot.ruedas.animacion = false;update();break;

    //Velocidad del primer grado de libertad (Ruedas)
    case Qt::Key_E:Robot.ruedas.varGiro += 0.2;update();break;
    case Qt::Key_R:Robot.ruedas.varGiro -= 0.2;update();break;

    //Segundo grado de libertad (Brazos)
    case Qt::Key_S:Robot.brazos.animacion = true;update();break;
    case Qt::Key_D:Robot.brazos.animacion = false;update();break;

    //Velocidad del segundo grado de libertad (Ruedas)
    case Qt::Key_T:Robot.brazos.varGiro += 0.2;update();break;
    case Qt::Key_Y:Robot.brazos.varGiro -= 0.2;update();break;

    //Tercer grado de libertad (Cabeza)
    case Qt::Key_Z:Robot.cabeza.animacion = true;update();break;
    case Qt::Key_X:Robot.cabeza.animacion = false;update();break;

    //Velocidad del tercer grado de libertad (Cabeza)
    case Qt::Key_U:Robot.cabeza.varGiro += 0.2;update();break;
    case Qt::Key_I:Robot.cabeza.varGiro -= 0.2;update();break;

    //Activar/Desactivar la primera luz
    case Qt::Key_J:if (Luz1.activada)Luz1.activada = false;else Luz1.activada=true;break;

    //Activar/Desactivar la segunda luz
    case Qt::Key_K:if (Luz2.activada)Luz2.activada = false;else Luz2.activada=true;break;

    //Cambiar el tipo de material(Hay tres tipos)
    case Qt::Key_M:mat++;if(mat==3) mat = 0;break;

    //Activar texturas
    case Qt::Key_F5:texturas=!texturas;break;


    //
    //Cambiar el tipo de material(Hay tres tipos)
    case Qt::Key_A:if (animacion) animacion = false; else animacion = true;break;
    case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
    case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
    case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
    case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
    case Qt::Key_PageUp:Observer_distance*=1.2;break;
    case Qt::Key_PageDown:Observer_distance/=1.2;break;
  }

  update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_CONE:Cone.draw_point();break;
    case OBJECT_CYLINDER:Cylinder.draw_point();break;
    case OBJECT_SPHERE:Sphere.draw_point(); break;
    case OBJECT_PLY:objetoPly.draw_point();break;
    case OBJECT_HIERARCHICAL:Robot.draw_point();break;
    case OBJECT_CHESSBOARD:ChessBoard.draw_point();break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(3);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_CONE:Cone.draw_line();break;
    case OBJECT_CYLINDER:Cylinder.draw_line();break;
    case OBJECT_SPHERE:Sphere.draw_line(); break;
    case OBJECT_PLY:objetoPly.draw_line();break;
    case OBJECT_HIERARCHICAL:Robot.draw_line();break;
    case OBJECT_CHESSBOARD:ChessBoard.draw_line();break;
    default:break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
    case OBJECT_CUBE:Cube.draw_fill();break;
    case OBJECT_CONE:Cone.draw_fill();break;
    case OBJECT_CYLINDER:Cylinder.draw_fill();break;
    case OBJECT_SPHERE:Sphere.draw_fill(); break;
    case OBJECT_PLY:objetoPly.draw_fill();break;
    case OBJECT_HIERARCHICAL:Robot.draw_fill();break;
    case OBJECT_CHESSBOARD:ChessBoard.draw_fill();break;
    default:break;
    }
  }

  if (Draw_chess){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_CONE:Cone.draw_chess();break;
    case OBJECT_CYLINDER:Cylinder.draw_chess();break;
    case OBJECT_SPHERE:Sphere.draw_chess(); break;
    case OBJECT_PLY:objetoPly.draw_chess();break;
    case OBJECT_HIERARCHICAL:Robot.draw_chess();break;
    case OBJECT_CHESSBOARD:ChessBoard.draw_chess();break;
    default:break;
    }
  }

  if (Draw_flat_light){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.iluminacion_flat(mat);break;
    case OBJECT_CUBE:Cube.iluminacion_flat(mat);break;
    case OBJECT_CONE:Cone.iluminacion_flat(mat);break;
    case OBJECT_CYLINDER:Cylinder.iluminacion_flat(mat);break;
    case OBJECT_SPHERE:Sphere.iluminacion_flat(mat); break;
    case OBJECT_PLY:objetoPly.iluminacion_flat(mat);break;
    case OBJECT_HIERARCHICAL:Robot.iluminacion_flat(mat);break;
    case OBJECT_CHESSBOARD:ChessBoard.iluminacion_flat(mat);break;
    default:break;
    }
  }
  if (Draw_smooth_light){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.iluminacion_smooth(mat);break;
    case OBJECT_CUBE:Cube.iluminacion_smooth(mat);break;
    case OBJECT_CONE:Cone.iluminacion_smooth(mat);break;
    case OBJECT_CYLINDER:Cylinder.iluminacion_smooth(mat);break;
    case OBJECT_SPHERE:Sphere.iluminacion_smooth(mat); break;
    case OBJECT_PLY:objetoPly.iluminacion_smooth(mat);break;
    case OBJECT_HIERARCHICAL:Robot.iluminacion_smooth(mat);break;
    case OBJECT_CHESSBOARD:ChessBoard.iluminacion_smooth(mat);break;
    default:break;
      }
}
}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();

  glutSetCursor(GLUT_CURSOR_INHERIT);
  if (Luz1.activada) Luz1.activar();
  else Luz1.desactivar();
  if (Luz2.activada) Luz2.activar();
  else Luz2.desactivar();

  change_projection();
  change_observer();
  draw_objects();

  if(texturas){
      switch(Object){
        case OBJECT_CHESSBOARD:ChessBoard.draw_textures();break;
        default:break;
      }

      update();
    }

  if(animacion) update();


}



/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;
  Draw_chess=false;

}


void _gl_widget::pick()
{
  makeCurrent();

  // Frame Buffer Object to do the off-screen rendering
  GLuint FBO;
  glGenFramebuffers(1,&FBO);
  glBindFramebuffer(GL_FRAMEBUFFER,FBO);

  int Window_width =  glutGet(GLUT_WINDOW_WIDTH);
  int Window_height = glutGet(GLUT_WINDOW_HEIGHT);

  // Texture for drawing
  GLuint Color_texture;
  glGenTextures(1,&Color_texture);
  glBindTexture(GL_TEXTURE_2D,Color_texture);
  // RGBA8
  glTexStorage2D(GL_TEXTURE_2D,1,GL_RGBA8, Window_width,Window_height);
  // this implies that there is not mip mapping
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

  // Texure for computing the depth
  GLuint Depth_texture;
  glGenTextures(1,&Depth_texture);
  glBindTexture(GL_TEXTURE_2D,Depth_texture);
  // Float
  glTexStorage2D(GL_TEXTURE_2D,1,GL_DEPTH_COMPONENT24, Window_width,Window_height);

  // Attatchment of the textures to the FBO
  glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,Color_texture,0);
  glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,Depth_texture,0);

  // OpenGL will draw to these buffers (only one in this case)
  static const GLenum Draw_buffers[]={GL_COLOR_ATTACHMENT0};
  glDrawBuffers(1,Draw_buffers);

  /*************************/

  // dibujar escena para seleccion

  /*************************/

  // get the pixel
  int Color;
  int Selection_position_x = glutGet(GLUT_WINDOW_X);
  int Selection_position_y = glutGet(GLUT_WINDOW_Y);

  glReadBuffer(GL_FRONT);
  glPixelStorei(GL_PACK_ALIGNMENT,1);
  glReadPixels(Selection_position_x,Selection_position_y,1,1,GL_RGBA,GL_UNSIGNED_BYTE,&Color);

  /*************************/

  // convertir de RGB a identificador

  // actualizar el identificador de la parte seleccionada en el objeto

  /*************************/

  glDeleteTextures(1,&Color_texture);
  glDeleteTextures(1,&Depth_texture);
  glDeleteFramebuffers(1,&FBO);
  // the normal framebuffer takes the control of drawing
  glBindFramebuffer(GL_DRAW_FRAMEBUFFER,defaultFramebufferObject());
}
