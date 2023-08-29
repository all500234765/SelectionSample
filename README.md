# Selection Sample
Unigine Selection Sample from OpenAir 2023

![image](https://github.com/all500234765/SelectionSample/assets/8898684/c36b7c26-8ae1-47e7-a892-bf2e32d93c04)

# Описание RU
Простой пример того как игровой программист может применить графику для решения своих задач под конкретный проект.
Основная идея заключается в том, что есть вещи, на которые не совсем обязательно выделять графического программиста, либо же знать что-то очень сложное.
Инструментарий называется 3D графика и он очень обширен.
И если дать инструментарий игровому программисту он сможет справиться, albeit все же понадобится попрактиковаться и разобраться в нем, но таков путь, никуда от этого не деться (:

# Description EN
Simple example of how a game programmer can use 3D graphics to solve problems for specific project's needs.
The main idea is the fact that you don't have to be a graphics programmer to solve this things.
The tool used here is called 3D graphics and it's wast.
If you give this tool to the game programmer he could, albeit still have to practice and get the main gist of it, but that's the way (:

# Build
0. Убедиться что Visual Studio и Windows SDK 10 установлены
1. Зарегистрироваться на [developer.unigine.com](https://developer.unigine.com/)
2. Скачать [Unigine SDK Browser 2](https://developer.unigine.com/en/downloads/sdk_browser_v2_start_here)
3. Скачать Unigine SDK 2.17.0.1 Community
4. Создать проект
 - SDK: UNIGINE 2 Community (2.17.0.1)
 - API + IDE: C++ (Visual Studio 2015+)
 - Precision: Float
5. Скачать zip исходников с github
6. Распаковать с заменой файлов
7. SDK Browser -> Open Code IDE и докинуть новые *.h и *.cpp из source/ в проект
8. Собрать проект и запустить
9. Загрузиться в мир SelectionSample коммандой "world_load SelectionSample" в консоль.

# Почему-то не работает!!
1. Загляните в редактор и проверьте что в мире SelectionSample перед шаром виден плейн
2. Если плейн не виден тогда - кликните на плейн в World Nodes, затем перетащите plane.mesh из Asset Browser в поле Mesh в окне Parameters
3. Перезапустите проект
