
// CntrItem.cpp : implementation of the Clab23CntrItem class
//

#include "pch.h"
#include "framework.h"
#include "lab_2_3.h"

#include "lab_2_3Doc.h"
#include "lab_2_3View.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab23CntrItem implementation

IMPLEMENT_SERIAL(Clab23CntrItem, CRichEditCntrItem, 0)

Clab23CntrItem::Clab23CntrItem(REOBJECT* preo, Clab23Doc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: add one-time construction code here
}

Clab23CntrItem::~Clab23CntrItem()
{
	// TODO: add cleanup code here
}


// Clab23CntrItem diagnostics

#ifdef _DEBUG
void Clab23CntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void Clab23CntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

