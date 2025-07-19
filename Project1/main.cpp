#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// поведение при нажатии на клавиши
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {

	// Когда пользователь нажимает ESC, мы устанавливаем свойство WindowShouldClose в true, 
	// и приложение после этого закроется
	if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{	
	// инициализация GLFW
	glfwInit();
	
	// минимальная требуемая версия OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// установка профайла, для которого создаётся контекст
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	// выключение возможности изменения размера окна
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	// создание окна
	GLFWwindow* window = glfwCreateWindow(800, 600, "I learn OpenGL", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	// создание контекста
	glfwMakeContextCurrent(window);

	// инициализация GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}


	// передача размеров окна
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height); // [0, 0] - левый нижний угол окна
	
	glfwSetKeyCallback(window, key_callback);

	/*	
	 *ОСНОВНОЙ ИГРОВОЙ ЦИКЛ
	 */
	while (!glfwWindowShouldClose(window)) {
		//проверяем события и вызываем функцию обратного вызова
		glfwPollEvents();

		// команды отрисовки здесь
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// меняем буферы местами
		glfwSwapBuffers(window);
	}
	
	// выход из цикла и очистка ресурсов
	glfwTerminate();
	return 0;
}