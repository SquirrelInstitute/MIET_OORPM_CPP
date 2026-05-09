
// CntrItem.h : interface of the Clab23CntrItem class
//

#pragma once

class Clab23Doc;
class Clab23View;

class Clab23CntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(Clab23CntrItem)

// Constructors
public:
	Clab23CntrItem(REOBJECT* preo = nullptr, Clab23Doc* pContainer = nullptr);
		// Note: pContainer is allowed to be null to enable IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-null document pointer

// Attributes
public:
	Clab23Doc* GetDocument()
		{ return reinterpret_cast<Clab23Doc*>(CRichEditCntrItem::GetDocument()); }
	Clab23View* GetActiveView()
		{ return reinterpret_cast<Clab23View*>(CRichEditCntrItem::GetActiveView()); }

// Implementation
public:
	~Clab23CntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

