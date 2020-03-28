#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "T.h"
float dsaw = 0.f, dy2 = 0.f;
float x = 0.f, y = 0.f, zx1 = 1, zy1 = 1 ;
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (key == GLFW_KEY_E)
        dsaw += 0.08f;
    if (key == GLFW_KEY_Q)
        dsaw -= 0.08f;
    if (key == GLFW_KEY_Z)
        dy2 += 0.08f;
    if (key == GLFW_KEY_X)
        dy2 -= 0.08f;
    if (key == GLFW_KEY_D)
        x += 0.05f;
    if (key == GLFW_KEY_W)
        y += 0.05f;
    if (key == GLFW_KEY_A)
        x -= 0.05f;
    if (key == GLFW_KEY_S)
        y -= 0.05f;
    if (key == GLFW_KEY_KP_ADD)
    {
        zy1 += 0.1f;
        zx1 += 0.1f;
    }
    if (key == GLFW_KEY_KP_SUBTRACT)
    {
        zy1 -= 0.1f;
        zx1 -= 0.1f;
    }
    if (key == GLFW_KEY_BACKSPACE)
    {
        dsaw = x = y = 0;
        zx1 = zy1 = 1;
    }

}

void T::draw()
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glScalef(zx1, zy1, 0);
        glRotatef(dsaw * 50.f,0.f, dy2 * 1.f, 1.f);
        glTranslatef(x, y, 0);
        glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
        glColor3f(1.0f, 0.0f, 0.0f);     // Red
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);     // Green
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3f(1.0f, -1.0f, 1.0f);

        // Right
        glColor3f(1.0f, 0.0f, 0.0f);     // Red
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3f(1.0f, -1.0f, 1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);     // Green
        glVertex3f(1.0f, -1.0f, -1.0f);

        // Back
        glColor3f(1.0f, 0.0f, 0.0f);     // Red
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);     // Green
        glVertex3f(1.0f, -1.0f, -1.0f);
        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3f(-1.0f, -1.0f, -1.0f);

        // Left
        glColor3f(1.0f, 0.0f, 0.0f);       // Red
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f);       // Blue
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);       // Green
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glEnd();
        glfwSwapBuffers(window);
         glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
