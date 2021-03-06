
// RectifierManagerView.h : interface of the CRectifierManagerView class
//

#pragma once


class CRectifierManagerView : public CView
{
protected: // create from serialization only
	CRectifierManagerView();
	DECLARE_DYNCREATE(CRectifierManagerView)

// Attributes
public:
	CRectifierManagerDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CRectifierManagerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RectifierManagerView.cpp
inline CRectifierManagerDoc* CRectifierManagerView::GetDocument() const
   { return reinterpret_cast<CRectifierManagerDoc*>(m_pDocument); }
#endif

