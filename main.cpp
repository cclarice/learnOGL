/*  *** *** *** *** *** *** *** *** *** *** */
/** Created by Danil Petrov on 25.11.2021. **/
/*  *** *** *** *** *** *** *** *** *** *** */

#include "main.h"

/**
 * Функция инициализации нового окна
 * @void Ничего не принимает
 * @return 0 Если нет ошибок
 */

int
	init(tOGL *app) {

	// Инициализируем GLFW библиотеку
	if (!glfwInit()) {
		std::cerr << "Не удалось инициализировать GLFW" << std::endl;
		return (app->exitcode = -1);
	}

	// Инициализируем GLFW окно
	app->window->window = glfwCreateWindow
		(1280, 720, "OpenGL", app->monitor->monitor, nullptr);
	if (app->window->window == nullptr) {
		std::cerr << "Не удалось инициализировать GLFW window" << std::endl;
		glfwTerminate();
		return (app->exitcode = -2);
	}
	glfwMakeContextCurrent(app->window->window);
	glfwSwapInterval(1);
	glfwShowWindow(app->window->window);

	glfwDefaultWindowHints();

	return 0;
}

int
	preInit(tOGL *app) {
	app->window		= (tOGLWindow	*)malloc(sizeof(tOGLWindow	));
	app->monitor	= (tOGLMonitor	*)malloc(sizeof(tOGLMonitor	));
	app->options	= (tOGLOptions	*)malloc(sizeof(tOGLOptions ));
	if (app->window	 ||
		app->monitor ||
		app->options) {
		return (app->exitcode = 64);
	}
	parseArguments(app->options);
	return (app->exitcode = 0);
}

/**
 * 	Main
 *
 * 	@param	argCount
 * 	@param 	argValue
 */

int
	main(int argCount, char *argValue[]) {
	tOGL app;

	preInit(&app);

	if (init(&app)) {
		return app.exitcode;
	} else {
		std::cout << "Приложение синициализировано!" << std::endl;
	}

  // Важно! Не эквивалентно glEnable(GL_DEPTH_TEST | GL_DOUBLEBUFFER)
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_DOUBLEBUFFER);
  glDepthFunc(GL_LESS);

  glClearColor(0.25, 0.25, 0.25, 1);

  float fov = 106.0f;
  glm::mat4 m = glm::perspective(fov, 16.0f / 9.0f, 1.0f, 10.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixf(glm::value_ptr(m));

  // Получаем данные об основном экране
  GLFWmonitor* monitor = glfwGetPrimaryMonitor(); // Получаем указатель на первый монитор
  int monitorXPos, monitorYPos, monitorWidth, monitorHeight;
  glfwGetMonitorWorkarea(monitor, &monitorXPos, &monitorYPos, &monitorWidth, &monitorHeight);
  if (monitor == nullptr) {
	  std::cerr << "Failed to open GLFW window" << std::endl;
	  glfwTerminate();
	  return -1;
  } else {
	  std::cout << "MPX: " << monitorXPos
	  			<< ", MPY:" << monitorYPos
				<< ", MSX:" << monitorWidth
				<< ", MSY:" << monitorHeight << '\n';
  }
  glfwSetWindowPos(window, 0, 0);

  while(glfwWindowShouldClose(window) == GL_FALSE) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor4f(1, 1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex3f( 1,  1, -2);
    glVertex3f(-1, -1, -2);
    glVertex3f(-1,  1, -2);
    glEnd();

	// Получаем нажатую клавишу
	if (glfwGetKey(window, GLFW_KEY_A)) {
		std::cout << "Key A is Pressed";
	}

	// Выход из программы
	if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
		break;
	}
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}