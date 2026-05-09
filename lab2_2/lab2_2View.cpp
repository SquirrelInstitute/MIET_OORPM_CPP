// lab2_2View.cpp : implementation of the Clab22View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "lab2_2.h"
#endif

#include "lab2_2Doc.h"
#include "lab2_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab22View

IMPLEMENT_DYNCREATE(Clab22View, CView)

BEGIN_MESSAGE_MAP(Clab22View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()   //доавленные команды
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()   // двойной клик ЛКМ
END_MESSAGE_MAP()

// Clab22View construction/destruction

Clab22View::Clab22View() noexcept
	: m_Dragging(0)
	, m_Point1(0)
	, m_Point2(0)
{
	// TODO: add construction code here
	m_HCross = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
}

Clab22View::~Clab22View()
{
}

BOOL Clab22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Clab22View drawing

void Clab22View::OnDraw(CDC* /*pDC*/)
{
	Clab22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Clab22View printing

BOOL Clab22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Clab22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Clab22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Clab22View diagnostics

#ifdef _DEBUG
void Clab22View::AssertValid() const
{
	CView::AssertValid();
}

void Clab22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab22Doc* Clab22View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab22Doc)));
	return (Clab22Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab22View message handlers

void Clab22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_Point1 = point; // Запомнить позицию
	m_Point2 = point; // курсора
	SetCapture(); // Перехватывать все сообщения мыши
	m_Dragging = 1; // Нажата левая кнопка мыши
	CView::OnLButtonDown(nFlags, point);
}

void Clab22View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	SetCursor(m_HCross); // Курсор имеет вид перекрестия
	if (m_Dragging)
	{ // Нажата левая кнопка мыши
		CClientDC ClientDC(this); // Создать объект контекста устройства
		ClientDC.SetROP2(R2_NOT); // Задать инверсный режим рисования
		ClientDC.MoveTo(m_Point1); // Переместить перо в точку 1
		ClientDC.LineTo(m_Point2); // Нарисовать прямую линию в точку 2
		ClientDC.MoveTo(m_Point1); // Переместить перо в точку 1
		ClientDC.LineTo(point); // Нарисовать прямую линию в точку, где
		m_Point2 = point; // находится курсор, и сделать ее точкой 2
	}
	CView::OnMouseMove(nFlags, point);
}

void Clab22View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_Dragging)
	{
		m_Dragging = 0; // Левая кнопка мыши отпущена
		ReleaseCapture(); // Не перехватывать сообщения мыши
		CClientDC ClientDC(this); // Создать объект контекста устройства
		ClientDC.SetROP2(R2_NOT); // Задать инверсный режим рисования
		ClientDC.MoveTo(m_Point1); // Переместить перо в точку 1
		ClientDC.LineTo(m_Point2); // Нарисовать прямую линию в точку 2
		ClientDC.SetROP2(R2_COPYPEN); // Задать рисование цветом пера
		ClientDC.MoveTo(m_Point1); // Нарисовать прямую линию в точку, где
		ClientDC.LineTo(point); // находится курсор, и сделать ее точкой 2
	}
	CView::OnLButtonUp(nFlags, point);
}

void Clab22View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	::MessageBox(0, L"Двойное нажатие ЛКМ", L"Мышь", MB_OK);
	CView::OnLButtonDblClk(nFlags, point);
}