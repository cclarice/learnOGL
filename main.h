/*  *** *** *** *** *** *** *** *** *** *** */
/** Created by Danil Petrov on 25.11.2021. **/
/*  *** *** *** *** *** *** *** *** *** *** */

#ifndef RED_TRIANGLE_MAIN_H
#define RED_TRIANGLE_MAIN_H

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include <cstdlib>

/**
 * 	@typedef tOGLMonitor
 * 	@struct sOGLMonitor
 * 	Структура информации об мониторе
 *
 * 	@param monitor
 * 		Указатель на монитор
 * 	@param width
 * 		Ширина монитора
 * 	@param height
 * 		Высота монитора
 * 	@param posX
 * 		Позиция монитора по оси X
 * 	@param posY
 * 		Позиция монитора по оси Y
 */

typedef struct	sOGLMonitor {
	GLFWmonitor *monitor;
	int         width;
	int         height;
	int         posX;
	int         posY;
}				tOGLMonitor;

typedef struct	sOGLWindow {
	GLFWwindow	*window;
	int 		width;
	int			height;
	int 		posX;
	int 		posY;
}				tOGLWindow;

typedef struct	sOGLOptions {
	int			argCount;
	char		**argValue;
	int 		windowWidth;
	int 		windowHeight;
	int 		windowPosX;
	int 		windowPosY;
	float 		fov;
}               tOGLOptions;

/**
 *	Структура приложения
 *	@param window
 *			Указатель на структуру окна приложения
 *			@relates tOGLWindow
 *	@param exitcode
 *			Переменная хранящая номер выхода программы
 *			 0 -> ОК
 *			-1 -> Не удалось инициализировать GLFW
 *			-2 -> Не удалось получить информацию об мониторе
 *			-2 -> Не удалось инициализировать GLFW window
 *			64 -> Ошибка аллокации памяти
 */

typedef struct	sOGL {
	tOGLWindow	*window;
	tOGLMonitor *monitor;
	tOGLOptions *options;
	int			exitcode;
}				tOGL;

int
	parseArguments(tOGLOptions *options);

#endif RED_TRIANGLE_MAIN_H
