
// test2Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"

class Ctest2DlgAutoProxy;


// Ctest2Dlg 对话框
class Ctest2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Ctest2Dlg);
	friend class Ctest2DlgAutoProxy;

// 构造
public:
	Ctest2Dlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~Ctest2Dlg();

// 对话框数据
	enum { IDD = IDD_TEST2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	Ctest2DlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList4(NMHDR *pNMHDR, LRESULT *pResult);
	// 交易记录报表
	CListCtrl m_list_report;
	// 姓名
	CEdit m_name;
	// 蚕农编号
	CEdit m_id;
	// 身份证
	CEdit m_identity;
	// 农社
	CEdit m_company;
	afx_msg void OnBnClickedButton5();
	// 毛重
	CEdit m_gross_weight;
	// 皮重
	CEdit m_tare;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton1();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
