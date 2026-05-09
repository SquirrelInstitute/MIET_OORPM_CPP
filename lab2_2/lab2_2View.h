// lab2_2View.h : interface of the Clab22View class
//

#pragma once


class Clab22View : public CView
{
protected: // create from serialization only
	Clab22View() noexcept;
	DECLARE_DYNCREATE(Clab22View)

	// Attributes
public:
	Clab22Doc* GetDocument() const;

	// Operations
public:

	// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point); // нажатие ЛКМ
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);  // дижуха мышью
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point); // отжим ЛКМ
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point); // двойной клик ЛКМ

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// Implementation
public:
	virtual ~Clab22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Дескриптор курсора  
	HCURSOR m_HCross;
	// Флаг, определяющий нажата ли ЛКМ
	int m_Dragging;
	// Координаты курсора  в начале линии 
	CPoint m_Point1;
	// Координаты курсора  в конце линии
	CPoint m_Point2;

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in lab2_2View.cpp
inline Clab22Doc* Clab22View::GetDocument() const
{
	return reinterpret_cast<Clab22Doc*>(m_pDocument);
}
#endif