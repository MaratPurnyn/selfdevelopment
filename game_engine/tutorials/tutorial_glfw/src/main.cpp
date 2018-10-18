//std libraries
#include <iostream>
//app libraries
#include "window.h"
#include "log.h"

int main()
{
    Log log;
    log.info("Start of Program");
   
    Window window("New Window", 800, 600);
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    while(!window.closed())
    {
        //log.info(std::to_string(window.getWidth()) + " x " + std::to_string(window.getHeight()));
#if 1
        window.clear();
        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
#else
        glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
        window.update();
    }

    return false;
}