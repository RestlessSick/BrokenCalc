// header.h: включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта
//

#pragma once

#define MAX_LOADSTRING 100
#include "Resource.h"
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
// Файлы заголовков Windows
#include <windows.h>
// Файлы заголовков среды выполнения C
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <windowsx.h>
#include <string>
#include <thread>
#include <chrono>
#include <windows.graphics.directx.h>
#include <ddraw.h>
#include <sstream>
#include <fstream>

using namespace std::chrono_literals;
