
// DlgProxy.cpp : ʵ���ļ�
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
	
	// ΪʹӦ�ó������Զ��������ڻ״̬ʱһֱ���� 
	//	���У����캯������ AfxOleLockApp��
	AfxOleLockApp();

	// ͨ��Ӧ�ó����������ָ��
	//  �����ʶԻ������ô�����ڲ�ָ��
	//  ָ��Ի��򣬲����öԻ���ĺ���ָ��ָ��
	//  �ô���
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
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	// 	������������ AfxOleUnlockApp��
	//  ���������������⣬�⻹���������Ի���
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void Ctest2DlgAutoProxy::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(Ctest2DlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Ctest2DlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ע��: ��������˶� IID_Itest2 ��֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {52686648-AF15-42D2-A952-A278DB717F8A}
static const IID IID_Itest2 =
{ 0x52686648, 0xAF15, 0x42D2, { 0xA9, 0x52, 0xA2, 0x78, 0xDB, 0x71, 0x7F, 0x8A } };

BEGIN_INTERFACE_MAP(Ctest2DlgAutoProxy, CCmdTarget)
	INTERFACE_PART(Ctest2DlgAutoProxy, IID_Itest2, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ���ڴ���Ŀ�� StdAfx.h �ж���
// {F05B6413-7720-475A-A9C2-6BFBAEFFE7F2}
IMPLEMENT_OLECREATE2(Ctest2DlgAutoProxy, "test2.Application", 0xf05b6413, 0x7720, 0x475a, 0xa9, 0xc2, 0x6b, 0xfb, 0xae, 0xff, 0xe7, 0xf2)


// Ctest2DlgAutoProxy ��Ϣ�������
