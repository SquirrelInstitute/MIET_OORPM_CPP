
// lab_2_3View.h : interface of the Clab23View class
//

#pragma once

class Clab23CntrItem;

class Clab23View : public CRichEditView
{
protected: // create from serialization only
	Clab23View() noexcept;
	DECLARE_DYNCREATE(Clab23View)

// Attributes
public:
	Clab23Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Clab23View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnDestroy();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in lab_2_3View.cpp
inline Clab23Doc* Clab23View::GetDocument() const
   { return reinterpret_cast<Clab23Doc*>(m_pDocument); }
#endif

