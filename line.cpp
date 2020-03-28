#include <gl/glew.h>
#include<math.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

class line {
	public :	
		line(int sx, int sy, int ex, int ey) {
			this->sx = sx;
			this->sy = sy;
			this->ex = ex;
			this->ey = ey;
		}
		void draw() {
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
			while (!glfwWindowShouldClose(window)) {
				if ((ex >= sx) && (ey >= sy))
				{
					if (ex - sx > ey - sy)
					{
						int k = ey > sy ? 1 : -1;
						int dx = ex - sx;
						int dy = abs(ey - sy);
						int d = 2 * dy - dx;
						int Est = 2 * dy;
						int NorEst = 2 * (dy - dx);
						int x = sx;
						int y = sy;
						glColor3f(0.0, 0.0, 0.0);
						glPointSize(2.0);
						glBegin(GL_POINTS);
						glVertex2i(x, 500 - y);
						glEnd();
						while (x < ex)
						{
							if (d <= 0)
								d += Est;
							else
							{
								d += NorEst;
								y += k;
							}
							x += 1;
							glColor3f(0.0, 0.0, 0.0);
							glPointSize(2.0);
							glBegin(GL_POINTS);
							glVertex2i(x, 500 - y);
							glEnd();
						}
					}
					else
					{
						int k = ex > sx ? 1 : -1;
						int dx = abs(ex - sx);
						int dy = ey - sy;
						int d = 2 * dx - dy;
						int Est = 2 * dx;
						int NorEst = 2 * (dx - dy);
						int x = sx;
						int y = sy;
						glColor3f(0.0, 0.0, 0.0);
						glPointSize(2.0);
						glBegin(GL_POINTS);
						glVertex2i(x, 500 - y);
						glEnd();
						while (y < ey)
						{
							if (d <= 0)
								d += Est;
							else
							{
								d += NorEst;
								x += k;
							}
							y += 1;
							glColor3f(0.0, 0.0, 0.0);
							glPointSize(2.0);
							glBegin(GL_POINTS);
							glVertex2i(x, 500 - y);
							glEnd();
						}
					}
				}
				else if ((ex >= sx) && (ey < sy))
				{
					if (ex - sx > sy - ey)
					{
						int k = ey > sy ? 1 : -1;
						int dx = ex - sx;
						int dy = abs(ey - sy);
						int d = 2 * dy - dx;
						int Est = 2 * dy;
						int NorEst = 2 * (dy - dx);
						int x = sx;
						int y = sy;
						glColor3f(0.0, 0.0, 0.0);
						glPointSize(2.0);
						glBegin(GL_POINTS);
						glVertex2i(x, 500 - y);
						glEnd();
						while (x < ex)
						{
							if (d <= 0)
								d += Est;
							else
							{
								d += NorEst;
								y += k;
							}
							x += 1;
							glColor3f(0.0, 0.0, 0.0);
							glPointSize(2.0);
							glBegin(GL_POINTS);
							glVertex2i(x, 500 - y);
							glEnd();
						}
					}
					else
					{
						int temp = sx;
						sx = ex;
						ex = temp;
						temp = ey;
						ey = sy;
						sy = temp;
						int k = ex > sx ? 1 : -1;
						int dx = abs(ex - sx);
						int dy = ey - sy;
						int d = 2 * dx - dy;
						int Est = 2 * dx;
						int NorEst = 2 * (dx - dy);
						int x = sx;
						int y = sy;
						glColor3f(0.0, 0.0, 0.0);
						glPointSize(2.0);
						glBegin(GL_POINTS);
						glVertex2i(x, 500 - y);
						glEnd();
						while (y < ey)
						{
							if (d <= 0)
								d += Est;
							else
							{
								d += NorEst;
								x += k;
							}
							y += 1;
							glColor3f(0.0, 0.0, 0.0);
							glPointSize(2.0);
							glBegin(GL_POINTS);
							glVertex2i(x, 500 - y);
							glEnd();
						}
					}
				}
				else
				{
					sy += ey;
					ey = sy - ey;
					sy -= ey;

					sx += ex;
					ex = sx - ex;
					sx -= ex;
					draw();
				}
			}
		}

	private :
		int sx, sy, ex, ey; //the start and end coordinates of the line we want to draw
};