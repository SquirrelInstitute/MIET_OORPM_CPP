#include <windows.h>

LRESULT WINAPI WindowProc(HWND hWnd, UINT message,
    WPARAM wParam, LPARAM lParam);

// Листинг WINAPP_1
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX WindowClass; // Структура для хранения атрибутов окна
    static LPCTSTR szAppName = L"WinApp"; // Определить класс окна
    HWND hWnd; // Дескриптор окна
    MSG msg; // Структура сообщения окна

    WindowClass.cbSize = sizeof(WNDCLASSEX); // Установить размер структуры

    // Перерисовать окно при изменении размера
    WindowClass.style = CS_HREDRAW | CS_VREDRAW;

    // Определить функцию - обработчик сообщений
    WindowClass.lpfnWndProc = WindowProc;

    WindowClass.cbClsExtra = 0; // Никаких дополнительных байт после структуры
    WindowClass.cbWndExtra = 0; // класса окна в экземпляре окна
    WindowClass.hInstance = hInstance; // Дескриптор экземпляра приложения

    // Установить пиктограмму приложения по умолчанию
    WindowClass.hIcon = LoadIcon(0, IDI_APPLICATION);

    // Установить стандартный курсор мыши в виде стрелки
    WindowClass.hCursor = LoadCursor(0, IDC_ARROW);

    // Установить серую кисть для рисования фона
    WindowClass.hbrBackground =
        static_cast<HBRUSH>(GetStockObject(GRAY_BRUSH));

    WindowClass.lpszMenuName = 0; // Нет меню
    WindowClass.lpszClassName = szAppName; // Установить имя класса
    WindowClass.hIconSm = 0; // Маленькая пиктограмма по умолчанию

    // Теперь зарегистрировать класс окна
    RegisterClassEx(&WindowClass);

    // Теперь можно создать окно
    hWnd = CreateWindow(
        szAppName, // Имя класса окна
        L"Окно Windows-приложения", // Заголовок окна
        WS_OVERLAPPEDWINDOW, // Стиль окна - перекрываемое
        CW_USEDEFAULT, // Позиция на экране по умолчанию
        CW_USEDEFAULT, // левого верхнего угла как х,у...
        CW_USEDEFAULT, // Размер окна по умолчанию - ширина...
        CW_USEDEFAULT, // ...и высота
        0, // Нет родительского окна
        0, // Нет меню
        hInstance, // Дескриптор экземпляра программы
        0 // Никаких данных для создания окна
    );

    ShowWindow(hWnd, nCmdShow); // Отобразить окно
    UpdateWindow(hWnd); // Заставить перерисовать клиентскую область окна

    // Цикл обработки сообщений
    while (GetMessage(&msg, 0, 0, 0) == TRUE) // Получить сообщение
    {
        TranslateMessage(&msg); // Трансляция сообщения
        DispatchMessage(&msg); // Диспетчеризация сообщения
    }

    return static_cast<int>(msg.wParam); // Конец, возврат в Windows
}

// Листинг WINAPP_2
LRESULT WINAPI WindowProc(HWND hWnd, UINT message,
    WPARAM wParam, LPARAM lParam)
{
    HDC hDC; // Дескриптор дисплейного контекста
    PAINTSTRUCT PaintSt; // Структура, определяющая область рисования
    RECT aRect; // Рабочий прямоугольник

    switch (message) // Обработка выбранных сообщений
    {
    case WM_PAINT: // Сообщение для перерисовки окна
        hDC = BeginPaint(hWnd, &PaintSt);// Подготовиться к перерисовке окна

        // Получить верхний левый и нижний правый углы клиентской области
        GetClientRect(hWnd, &aRect);

        SetBkMode(hDC, TRANSPARENT); // Установить режим отображения фона текста

        // Теперь отобразить текст в клиентской области окна
        DrawText(
            hDC, // Дескриптор контекста устройства
            L"Текст выводится при перерисовке окна",
            -1, // Признак строки, ограниченной null
            &aRect, // Прямоугольник, в котором выполняется рисование текста
            DT_SINGLELINE | // Формат текста - одна строка
            DT_CENTER | // - центрирование в строке
            DT_VCENTER); // - центрирование по высоте aRect

        EndPaint(hWnd, &PaintSt); // Завершить операцию перерисовки окна
        return 0;

    case WM_LBUTTONUP: // Отпускание левой кнопки мыши
        MessageBox(0, L"Нажатие ЛКМ прекращено", L"Мышь", MB_OK);
        return 0;

    case WM_DESTROY: // Окно уничтожается
        PostQuitMessage(0);
        return 0;

    default: // Любые другие сообщения программу
        // не интересуют, поэтому вызывается
        // обработка сообщения по умолчанию
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}