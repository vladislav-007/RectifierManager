
// RectifierManagerView.cpp : implementation of the CRectifierManagerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "RectifierManager.h"
#endif

#include "RectifierManagerDoc.h"
#include "RectifierManagerView.h"

#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRectifierManagerView

IMPLEMENT_DYNCREATE(CRectifierManagerView, CView)

BEGIN_MESSAGE_MAP(CRectifierManagerView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRectifierManagerView construction/destruction

CRectifierManagerView::CRectifierManagerView()
{
	// TODO: add construction code here

}

CRectifierManagerView::~CRectifierManagerView()
{
}

BOOL CRectifierManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}

// CRectifierManagerView drawing

void CRectifierManagerView::OnDraw(CDC* pDC)
{
	CRectifierManagerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CBitmap bmp; //Create a bitmao object
	BITMAP bmpStruct; //Bitmap information structure
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP1));
	bmp.GetObject(sizeof(bmpStruct), &bmpStruct); //fill the structure with useful data
	CDC memDC;
	memDC.CreateCompatibleDC(pDC); //create a memory DC compatible with pDC
	memDC.SelectObject(&bmp); //Select the bitmap into the DC
	pDC->BitBlt(0, 0, bmpStruct.bmWidth, bmpStruct.bmHeight, &memDC, 0, 0, SRCCOPY); // This is the heart of bitmap drawing



}

// CRectifierManagerView printing

BOOL CRectifierManagerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRectifierManagerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRectifierManagerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CRectifierManagerView diagnostics

#ifdef _DEBUG
void CRectifierManagerView::AssertValid() const
{
	CView::AssertValid();
}

void CRectifierManagerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRectifierManagerDoc* CRectifierManagerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRectifierManagerDoc)));
	return (CRectifierManagerDoc*)m_pDocument;
}
#endif //_DEBUG


// CRectifierManagerView message handlers
