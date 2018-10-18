#pragma once
//3rd party libraries
#define GLEW_STATIC //to use the glew library statically
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

//std libraries
#include <iostream>

class Window 
{ 
    private:
        //variables
        int m_Width, m_Height;
        const char *m_Title;
        GLFWwindow *m_Window;
        //functions
        bool init();
    public:
        //functions
        Window(const char *title, int width, int height);
        ~Window();
        inline int getWidth() const {return m_Width;};
        inline int getHeight() const {return m_Height;};
        void setWidth(int width);
        void setHeight(int height);
        void clear() const;
        void update();
        bool closed() const;
};