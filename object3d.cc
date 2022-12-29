/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glBegin(GL_TRIANGLES);
    for(unsigned int i = 0; i < Triangles.size(); i++){
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._2]);
    }

    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for(unsigned int i = 0; i < Triangles.size(); i++){
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._2]);
    }
    glEnd();  
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);

    for(unsigned int i = 0; i < Triangles.size(); i++){
        if(i % 2 == 0)
            glColor3f(1.0, 1.0, 1.0);
        else
            glColor3f(0.0, 0.0, 0.0);

        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._2]);
    }
    glEnd();
}

void _object3D::calcular_normales()
{
    normCaras.resize(Triangles.size());

    for(unsigned int i = 0; i < Triangles.size(); i++){
        _vertex3f A = Vertices[Triangles[i]._1] - Vertices[Triangles[i]._0];
        _vertex3f B = Vertices[Triangles[i]._2] - Vertices[Triangles[i]._0];
        _vertex3f aux = A.cross_product(B);

        normCaras[i] = aux.normalize();
    }

    normVertices.resize(Vertices.size());

    for(unsigned int i = 0; i < Vertices.size(); i++){
        normVertices[i] = _vertex3f(0.0, 0.0, 0.0);
    }

    for(unsigned int i = 0; i < Triangles.size(); i++){
        normVertices[Triangles[i]._0] += normCaras[i];
        normVertices[Triangles[i]._1] += normCaras[i];
        normVertices[Triangles[i]._2] += normCaras[i];
    }

    for(unsigned int i = 0; i< Vertices.size(); i++){
        normVertices[i].normalize();
    }
    calcNormales = true;
}

void _object3D::iluminacion_flat(int mat)
{
    if(!calcNormales) calcular_normales();

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    glShadeModel(GL_FLAT);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    if(mat == 0){
        ambiente = _vertex4f(0.0,0.0,0.0,0.0);
        difusa = _vertex4f(0.0,0.0,0.0,0.0);
        especular = _vertex4f(1.0,0.5,0.0,1.0);
        brillo = 50.0;
    }

    if(mat == 1){
        ambiente = _vertex4f(0.0,0.0,0.0,0.0);
        difusa = _vertex4f(0.8, 0.8, 0.8, 0.5);
        especular = _vertex4f(0.0,0.0,0.0,0.0);
        brillo = 10.0;
    }

    if(mat == 2){
        ambiente = _vertex4f(1.0, 1.0, 1.0, 1.0);
        difusa = _vertex4f(1.0, 1.0, 1.0, 1.0);
        especular = _vertex4f(1.0, 1.0, 1.0, 1.0);
        brillo = 20.0;
    }

    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,(GLfloat *)&ambiente);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,(GLfloat *)&difusa);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,(GLfloat *)&especular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,(GLfloat *)&brillo);


    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);

    for(unsigned int i = 0;i < Triangles.size(); i++){
        glNormal3fv((GLfloat*)&normCaras[i]);
        glVertex3fv((GLfloat*)&Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat*)&Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat*)&Vertices[Triangles[i]._2]);
    }

    glEnd();
    glDisable(GL_LIGHTING);
}
void _object3D::iluminacion_smooth(int mat)
{
    if(!calcNormales) calcular_normales();

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    if(mat == 0){
        ambiente = _vertex4f(0.0,0.0,0.0,0.0);
        difusa = _vertex4f(0.0,0.0,0.0,0.0);
        especular = _vertex4f(1.0,0.5,0.0,1.0);
        brillo = 50.0;
    }

    if(mat == 1){
        ambiente = _vertex4f(0.0,0.0,0.0,0.0);
        difusa = _vertex4f(0.8, 0.8, 0.8, 0.5);
        especular = _vertex4f(0.0,0.0,0.0,0.0);
        brillo = 10.0;
    }

    if(mat == 2){
        ambiente = _vertex4f(1.0, 1.0, 1.0, 1.0);
        difusa = _vertex4f(1.0, 1.0, 1.0, 1.0);
        especular = _vertex4f(1.0, 1.0, 1.0, 1.0);
        brillo = 20.0;
    }

    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,(GLfloat *)&ambiente);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,(GLfloat *)&difusa);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,(GLfloat *)&especular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,(GLfloat *)&brillo);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);

    for(unsigned int i = 0;i < Triangles.size(); i++){
        glNormal3fv((GLfloat*)&normVertices[Triangles[i]._0]);
        glVertex3fv((GLfloat*)&Vertices[Triangles[i]._0]);
        glNormal3fv((GLfloat*)&normVertices[Triangles[i]._1]);
        glVertex3fv((GLfloat*)&Vertices[Triangles[i]._1]);
        glNormal3fv((GLfloat*)&normVertices[Triangles[i]._2]);
        glVertex3fv((GLfloat*)&Vertices[Triangles[i]._2]);
    }

    glEnd();
    glDisable(GL_LIGHTING);
}
