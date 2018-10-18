//my libraries
#include "window.h"

void windowResize(GLFWwindow *window, int width, int height);

Window::Window( const char *title, int width, int height)
{
    m_Title = title;
    m_Width = width;
    m_Height = height;
    init();
}
Window::~Window(){
    glfwTerminate();
}
bool Window::init()
{
    if(!glfwInit())
    {
        std::cout << "Failed to init GLFW!" << std::endl;
        return false;
    }

    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
    if(!m_Window)
    {
        glfwTerminate();
        std::cout << "Failed to create GLFW window!" << std::endl;
        return false;
    }
    glfwMakeContextCurrent(m_Window);  
    glfwSetWindowSizeCallback(m_Window, windowResize);

    if(glewInit() != GLEW_OK)
    {
        std::cout << "Could not initialize Glew!" << std::endl;
        return false;
    }

    std::cout << "OpenGL!" << glGetString(GL_VERSION) << std::endl;
    return true;
}

void Window::setWidth(int width)
{
    this->m_Width = width;
}

void Window::setHeight(int height)
{
    this->m_Height = height;
}

void Window::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Window::update()
{
    glfwPollEvents();
    glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
    
    glfwSwapBuffers(m_Window);
}

bool Window::closed() const
{
    return glfwWindowShouldClose(m_Window) == 1;
}

void windowResize(GLFWwindow *window, int width, int height)
{
    glViewport(0,0,width,height);
}