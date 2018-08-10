
// MFCblackDlg.h : 头文件
//

#pragma once


// CMFCblackDlg 对话框
class CMFCblackDlg : public CDialogEx
{
// 构造
public:
	CMFCblackDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCBLACK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int tm[10] = { 0,0,0,0,0,0,0,0,0,0 };
	CString tem[30] = {L"0"};
	CString temp[10] = {L"0"};
	CString CSnum[20] = { L"0",L"1",L"2",L"3",L"4",L"5", L"6", L"7", L"8", L"9" }; //数字
	CString Sstr[20] = { L"C",L"N",L"M",L"H",L"U",L"X", L"L", L"S", L"R", L"J" };  //客户编号对应的字母
	CString CSstr[20] = { L"L",L"K",L"Y",L"B",L"I",L"E", L"V", L"O", L"T", L"Q" }; //日期对应的字母
	afx_msg void OnBnClickedButton1();
	CString m_cstr1;
	CString m_cstr2;
	afx_msg void OnBnClickedButton2();
	CString m_cstr3;
	int Remainder;
};
