
// DlgProxy.cpp : 实现文件
//

#include "stdafx.h"
#include "test2.h"
#include "DlgProxy.h"
#include "test2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest2DlgAutoProxy

IMPLEMENT_DYNCREATE(Ctest2DlgAutoProxy, CCmdTarget)

Ctest2DlgAutoProxy::Ctest2DlgAutoProxy()
{
	EnableAutomation();
	
	// 为使应用程序在自动化对象处于活动状态时一直保持 
	//	运行，构造函数调用 AfxOleLockApp。
	AfxOleLockApp();

	// 通过应用程序的主窗口指针
	//  来访问对话框。设置代理的内部指针
	//  指向对话框，并设置对话框的后向指针指向
	//  该代理。
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(Ctest2Dlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(Ctest2Dlg)))
		{
			m_pDialog = reinterpret_cast<Ctest2Dlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

Ctest2DlgAutoProxy::~Ctest2DlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void Ctest2DlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(Ctest2DlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Ctest2DlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_Itest2 的支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {52686648-AF15-42D2-A952-A278DB717F8A}
static const IID IID_Itest2 =
{ 0x52686648, 0xAF15, 0x42D2, { 0xA9, 0x52, 0xA2, 0x78, 0xDB, 0x71, 0x7F, 0x8A } };

BEGIN_INTERFACE_MAP(Ctest2DlgAutoProxy, CCmdTarget)
	INTERFACE_PART(Ctest2DlgAutoProxy, IID_Itest2, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 宏在此项目的 StdAfx.h 中定义
// {F05B6413-7720-475A-A9C2-6BFBAEFFE7F2}
IMPLEMENT_OLECREATE2(Ctest2DlgAutoProxy, "test2.Application", 0xf05b6413, 0x7720, 0x475a, 0xa9, 0xc2, 0x6b, 0xfb, 0xae, 0xff, 0xe7, 0xf2)


// Ctest2DlgAutoProxy 消息处理程序
