
// DlgProxy.h: 头文件
//

#pragma once

class Ctest2Dlg;


// Ctest2DlgAutoProxy 命令目标

class Ctest2DlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(Ctest2DlgAutoProxy)

	Ctest2DlgAutoProxy();           // 动态创建所使用的受保护的构造函数

// 特性
public:
	Ctest2Dlg* m_pDialog;

// 操作
public:

// 重写
	public:
	virtual void OnFinalRelease();

// 实现
protected:
	virtual ~Ctest2DlgAutoProxy();

	// 生成的消息映射函数

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(Ctest2DlgAutoProxy)

	// 生成的 OLE 调度映射函数

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

