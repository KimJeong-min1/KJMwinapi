// JMengine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
// 나의 첫번째 프로젝트
// 노트북 커밋 테스트
// 커밋 테스트
#include "framework.h"
#include "JMengine.h"
#include "..\\KJMengine_SOURCE\JMapplication.h"

jm::Application application;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance); //윈도우 객체
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, //프로그램의 인스턴스 핸들
                                                // 여러개의 윈도우가 실행이되도 이 핸들로인해 서로 다른걸 구분한다.
                     _In_opt_ HINSTANCE hPrevInstance, // 바로 앞에 실행된 현재 프로그램의 인스턴스 핸들,
                                                       // 없을 경우는 NULL이 되며 WIN32에서는 항상 NULL이다.
                                                       // 호환성을 위해서만 존재하는 인수이므로 신경쓰지 않아도 된다.
                     _In_ LPWSTR    lpCmdLine, // 명령행으로 입력된 프로그램 인수이다. 도스의 argv인수에 해당한다.
                     _In_ int       nCmdShow) // 프로그램이 실행될 형태이며 최소화, 보통모양등이 전달된다.
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
    
    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING); //창의 제목
    LoadStringW(hInstance, IDC_JMENGINE, szWindowClass, MAX_LOADSTRING); //창의 제목 대문자
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_JMENGINE));

    MSG msg;

    // 기본 메시지 루프입니다:
    // 윈도우는 메세지기반으로 실행이된다
    
    // GetMessage(&msg, nullptr, 0, 0)
    // 프로세스에서 발생한 메세지를 메세지 큐에서 가져오는 함수
    // 메세지큐에 아무것도 없다면 아무 메세지도 가져오지 않게된다.

    // PeekMessage : 메세지큐에 메세지 유무에 상관없이 함수가 리턴된다.
    //               리턴 값이 true인경우 메세지가 있고 false인경우는 메세지가 없다라고 가르켜준다.
        
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            // 메세지가 없을 경우 여기서 처리
            // 게임 로직이 들어가면 된다.

            application.Run();
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance) //윈도우 정보 세팅
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW; //윈도우가 어떤 형태를 가질 것인지 지정하는 멤버
    wcex.lpfnWndProc    = WndProc; //윈도우의 메시지 처리 함수를 지정한다.
    wcex.cbClsExtra     = 0; //일종의 예약 영역이다. 특수한 목적에 사용되는 여분의 공간
    wcex.cbWndExtra     = 0; //일종의 예약 영역이다. 특수한 목적에 사용되는 여분의 공간
    wcex.hInstance      = hInstance; //윈도우 클래스를 사용하는 프로그램의 번호 값은 Winmain의 인수다.
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_JMENGINE)); //윈도우가 최소화 되었을경우 출력될 아이콘
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW); //윈도우가 사용할 마우스커서
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1); //윈도우 배경 색상을 지정한다
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_JMENGINE); //이 프로그램이 사용할 메뉴를 지정한다. 사용하지않을 경우 멤버에 NULL대입
    wcex.lpszClassName  = szWindowClass; //윈도우 클래스의 이름을 정의한다. 윈도우 클래스의 이름은 보통 실행파일의 이름과 일치한다.
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)); // 창 이름옆에 작은 아이콘을 지정

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.
   // 윈도우에 관한 모든 정보를 메모리에 만든 후 윈도우 핸들을 리턴 값으로 넘겨준다.
   // 어디까지나 메모리상에서만 있을 뿐 아직까지 화면에 출력되지는 않았다.
   HWND hWnd = CreateWindowW(
       szWindowClass, //생성하고자하는 윈도우의 클래스를 지정하는 문자열
       szTitle, //윈도우의 타이틀 바에 나타날 문자열
       WS_OVERLAPPEDWINDOW, //만들고자 하는 윈도우의 형태를 지정하는 인수
       CW_USEDEFAULT, 0, 1600, 900, //윈도우의 크기와 위치를 지정하며 픽셀 단위를 사용한다.
       nullptr, //부모 윈도우가 있을 경우 부모 윈도우의 핸들을 지정해준다. 부모 윈도우가 없을 경우 NULL
       nullptr, //윈도우에서 사용할 메뉴의 핸들을 지정한다.wndclass에서 지정한 메뉴를 그대로 사용할려면 NULL 
       hInstance, //윈도우를 만드는 주체, 프로그램의 핸들을 지정한다.
       nullptr); // CREATESTRUCT라는 구조체의 번지이며 특수한 목적에 사용된다. 보통은 NULL

   application.Initialize(hWnd);

   if (!hWnd)
   {
      return FALSE;
   }
   //윈도우를 화면에 보여주는 함수
   ShowWindow(hWnd //화면으로 출력하고자하는 윈도우의 핸들
       , nCmdShow); // 윈도우를 화면에 출력하는 방법을 지정한다. 
   UpdateWindow(hWnd); // 윈도우를 업데이트를 해주는 함수 

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) // 윈도우 내의 행동(이벤트)을
{                                                                               // 확인하는 함수
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT: // 윈도우창의 도움말의 정보창을 누르면 실행이된다.
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT: // 윈도우창의 파일의 끝내기 버튼을 누르면 실행이된다.
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

            // 그림을 그릴수 있어야한다.
            //HBRUSH redbrush = CreateSolidBrush(RGB(120, 0, 0)); // 도형의 안의 색깔을 담당하는 기능
            //HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, redbrush); // 색깔적용을 해주는 기능

            //HPEN bluepen = CreatePen(PS_SOLID, 5, RGB(0, 120, 0));
            //HPEN oldpen = (HPEN)SelectObject(hdc, bluepen);
            //Rectangle(hdc, 100, 100, 300, 300); // 사각형
            //Ellipse(hdc, 500, 500, 600, 600); // 원
            //Ellipse(hdc, 300, 300, 100, 100);

            //(HBRUSH)SelectObject(hdc, oldbrush); // 색깔을다시 원래대로 돌려놓는 기능
            //DeleteObject(redbrush); // 색깔을 다시 원래대로 돌려놓는 기능
            //(HPEN)SelectObject(hdc, oldpen);
            //DeleteObject(bluepen);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0); // 윈도우창의 닫기버튼을 누르면 실행이된다.
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG: // 윈도우창의 도움말의 정보를 누르면 실행이된다
        return (INT_PTR)TRUE;

    case WM_COMMAND: // 윈도우창의 도움말의 정보를 누르고 확인이나 닫기버튼을 누르면 실행이된다
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
