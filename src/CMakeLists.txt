#Включение экспорта всех символов для создания динамической библиотеки
#в операционной системе Windows
 set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
#создание динамической библиотеки с именем Search_lib
add_library(
            Saerch_lib SHARED
            Search.cpp 
            Search.hpp)
