#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// ��������� ��� ������� �� �������
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {

	// ����� ������������ �������� ESC, �� ������������� �������� WindowShouldClose � true, 
	// � ���������� ����� ����� ���������
	if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{	
	// ������������� GLFW
	glfwInit();
	
	// ����������� ��������� ������ OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// ��������� ��������, ��� �������� �������� ��������
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	// ���������� ����������� ��������� ������� ����
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	// �������� ����
	GLFWwindow* window = glfwCreateWindow(800, 600, "I learn OpenGL", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	// �������� ���������
	glfwMakeContextCurrent(window);

	// ������������� GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}


	// �������� �������� ����
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height); // [0, 0] - ����� ������ ���� ����
	
	glfwSetKeyCallback(window, key_callback);

	/*	
	 *�������� ������� ����
	 */
	while (!glfwWindowShouldClose(window)) {
		//��������� ������� � �������� ������� ��������� ������
		glfwPollEvents();

		// ������� ��������� �����
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// ������ ������ �������
		glfwSwapBuffers(window);
	}
	
	// ����� �� ����� � ������� ��������
	glfwTerminate();
	return 0;
}