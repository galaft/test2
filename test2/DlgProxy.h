
// DlgProxy.h: ͷ�ļ�
//

#pragma once

class Ctest2Dlg;


// Ctest2DlgAutoProxy ����Ŀ��

class Ctest2DlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(Ctest2DlgAutoProxy)

	Ctest2DlgAutoProxy();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��

// ����
public:
	Ctest2Dlg* m_pDialog;

// ����
public:

// ��д
	public:
	virtual void OnFinalRelease();

// ʵ��
protected:
	virtual ~Ctest2DlgAutoProxy();

	// ���ɵ���Ϣӳ�亯��

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(Ctest2DlgAutoProxy)

	// ���ɵ� OLE ����ӳ�亯��

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

