
// MFCblackDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCblack.h"
#include "MFCblackDlg.h"
#include "afxdialogex.h"
#include "XMLHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCblackDlg 对话框



CMFCblackDlg::CMFCblackDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCBLACK_DIALOG, pParent)
	, m_cstr1(_T(""))
	, m_cstr2(_T(""))
	, m_cstr3(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_HSICON);
}

void CMFCblackDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_cstr1);
	DDX_Text(pDX, IDC_EDIT2, m_cstr2);
	DDX_Text(pDX, IDC_EDIT3, m_cstr3);
}

BEGIN_MESSAGE_MAP(CMFCblackDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//	ON_BN_CLICKED(IDOK, &CMFCblackDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCblackDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCblackDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCblackDlg 消息处理程序

BOOL CMFCblackDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CString sycs;
	const char* number;
	opXML  opx2("configurationfile.xml");
	opx2.QueryNode_Text("bzeng2", number);
	Remainder = atoi(number);
	sycs = number;
	if (Remainder<=0)
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	}
	GetDlgItem(IDC_STATIC11)->SetWindowText(sycs);
	UpdateData(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCblackDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCblackDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCblackDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CMFCblackDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString str,sycs;//剩余次数
	CString str1 = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //随机数组
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	if (str.Trim().GetLength() != 8)
	{
		MessageBox(L"长度错误！");
		return;
	}
	for (int i = 2; i < 8; i++)       //数字转字母
	{
		if (str.Trim().GetAt(i) == CSnum[0])
		{
			tm[i] = 0;
			temp[i] = CSstr[0];
		}
		if (str.Trim().GetAt(i) == CSnum[1])
		{
			tm[i] = 1;
			temp[i] = CSstr[1];
		}
		if (str.Trim().GetAt(i) == CSnum[2])
		{
			tm[i] = 2;
			temp[i] = CSstr[2];
		}
		if (str.Trim().GetAt(i) == CSnum[3])
		{
			tm[i] = 3;
			temp[i] = CSstr[3];
		}
		if (str.Trim().GetAt(i) == CSnum[4])
		{
			tm[i] = 4;
			temp[i] = CSstr[4];
		}
		if (str.Trim().GetAt(i) == CSnum[5])
		{
			tm[i] = 5;
			temp[i] = CSstr[5];
		}
		if (str.Trim().GetAt(i) == CSnum[6])
		{
			tm[i] = 6;
			temp[i] = CSstr[6];
		}
		if (str.Trim().GetAt(i) == CSnum[7])
		{
			tm[i] = 7;
			temp[i] = CSstr[7];
		}
		if (str.Trim().GetAt(i) == CSnum[8])
		{
			tm[i] = 8;
			temp[i] = CSstr[8];
		}
		if (str.Trim().GetAt(i) == CSnum[9])
		{
			tm[i] = 9;
			temp[i] = CSstr[9];
		}
	}

	int nYear, nMonth, nDay;
	nYear = 2000 + tm[2] * 10 + tm[3];
	nMonth = tm[4] * 10 + tm[5];
	nDay = tm[6] * 10 + tm[7];
	COleDateTime m_dt;
	if (m_dt.SetDate(nYear, nMonth, nDay) == 0) //判断时间是否正确，防止16月这样的情况出现
	{
		tem[0] = str1.GetAt(rand() % 26);//rand范围是0-25
		tem[1] = str1.GetAt(rand() % 26);
		tem[2] = str1.GetAt(rand() % 26);
		tem[3] = str1.GetAt(rand() % 26);
		tem[5] = str1.GetAt(rand() % 26);
		for (int i = 1; i < 9; i++)
		{
			tem[2 * i] = str1.GetAt(rand() % 26);
		}
		tem[18] = str1.GetAt(rand() % 26);
		tem[19] = str1.GetAt(rand() % 26);
		for (int i = 3; i < 9; i++)
		{
			tem[2 * i + 1] = temp[i - 1];
		}
	}
	else
	{
		MessageBox(L"   TimeError！");
		return;
	}
	GetDlgItem(IDC_EDIT4)->GetWindowText(str);
	if (str.Trim().GetLength() != 8)
	{
		MessageBox(L"长度错误！");
		return;
	}
	for (int i = 0; i < 8; i++)       //用户编号改写成字符串
	{
		if (str.Trim().GetAt(i) == CSnum[0])
		{
			tem[2 * i + 2] = Sstr[0];
		}
		if (str.Trim().GetAt(i) == CSnum[1])
		{
			tem[2 * i + 2] = Sstr[1];
		}
		if (str.Trim().GetAt(i) == CSnum[2])
		{
			tem[2 * i + 2] = Sstr[2];
		}
		if (str.Trim().GetAt(i) == CSnum[3])
		{
			tem[2 * i + 2] = Sstr[3];
		}
		if (str.Trim().GetAt(i) == CSnum[4])
		{
			tem[2 * i + 2] = Sstr[4];
		}
		if (str.Trim().GetAt(i) == CSnum[5])
		{
			tem[2 * i + 2] = Sstr[5];
		}
		if (str.Trim().GetAt(i) == CSnum[6])
		{
			tem[2 * i + 2] = Sstr[6];
		}
		if (str.Trim().GetAt(i) == CSnum[7])
		{
			tem[2 * i + 2] = Sstr[7];
		}
		if (str.Trim().GetAt(i) == CSnum[8])
		{
			tem[2 * i + 2] = Sstr[8];
		}
		if (str.Trim().GetAt(i) == CSnum[9])
		{
			tem[2 * i + 2] = Sstr[9];
		}
	}
	m_cstr2 = L"";
	for (int i = 0; i < 20; i++)
	{
		m_cstr2 += tem[i];
		if ((i+1)%5==0)
		{
			m_cstr2 += L" ";
		}
	}
	//反编码，查看格式正确与否
	/*GetDlgItem(IDC_EDIT2)->GetWindowText(str);*/
	for (int i = 3; i < 9; i++)
	{
		if (tem[2 * i + 1] == CSstr[0])
		{
			temp[i] = CSnum[0];
		}
		if (tem[2 * i + 1] == CSstr[1])
		{
			temp[i] = CSnum[1];
		}
		if (tem[2 * i + 1] == CSstr[2])
		{
			temp[i] = CSnum[2];
		}
		if (tem[2 * i + 1] == CSstr[3])
		{
			temp[i] = CSnum[3];
		}
		if (tem[2 * i + 1] == CSstr[4])
		{
			temp[i] = CSnum[4];
		}
		if (tem[2 * i + 1] == CSstr[5])
		{
			temp[i] = CSnum[5];
		}
		if (tem[2 * i + 1] == CSstr[6])
		{
			temp[i] = CSnum[6];
		}
		if (tem[2 * i + 1] == CSstr[7])
		{
			temp[i] = CSnum[7];
		}
		if (tem[2 * i + 1] == CSstr[8])
		{
			temp[i] = CSnum[8];
		}
		if (tem[2 * i + 1] == CSstr[9])
		{
			temp[i] = CSnum[9];
		}
	}
	m_cstr3 = L"";
	m_cstr3 += L"2";
	m_cstr3 += L"0";
	m_cstr3 += temp[3];
	m_cstr3 += temp[4];
	m_cstr3 += L"-";
	m_cstr3 += temp[5];
	m_cstr3 += temp[6];
	m_cstr3 += L"-";
	m_cstr3 += temp[7];
	m_cstr3 += temp[8];

	for (int i = 0; i < 8; i++)
	{
		if (tem[2 * i + 2] == Sstr[0])
		{
			temp[i] = CSnum[0];
		}
		if (tem[2 * i + 2] == Sstr[1])
		{
			temp[i] = CSnum[1];
		}
		if (tem[2 * i + 2] == Sstr[2])
		{
			temp[i] = CSnum[2];
		}
		if (tem[2 * i + 2] == Sstr[3])
		{
			temp[i] = CSnum[3];
		}
		if (tem[2 * i + 2] == Sstr[4])
		{
			temp[i] = CSnum[4];
		}
		if (tem[2 * i + 2] == Sstr[5])
		{
			temp[i] = CSnum[5];
		}
		if (tem[2 * i + 2] == Sstr[6])
		{
			temp[i] = CSnum[6];
		}
		if (tem[2 * i + 2] == Sstr[7])
		{
			temp[i] = CSnum[7];
		}
		if (tem[2 * i + 2] == Sstr[8])
		{
			temp[i] = CSnum[8];
		}
		if (tem[2 * i + 2] == Sstr[9])
		{
			temp[i] = CSnum[9];
		}
	}
	m_cstr3 += L" ";
	m_cstr3 += temp[0];
	m_cstr3 += temp[1];
	m_cstr3 += temp[2];
	m_cstr3 += temp[3];
	m_cstr3 += temp[4];
	m_cstr3 += temp[5];
	m_cstr3 += temp[6];
	m_cstr3 += temp[7];

	//更新剩余使用次数
	if (Remainder > 0)
	{
		Remainder -= 1;
		opXML  opx("configurationfile.xml");
		string m_str = opx.numtoString(Remainder);
		sycs.Format(_T("%d"), Remainder);
		opx.ModifyNode("bzeng2", m_str);
		opx.SaveFile();
		GetDlgItem(IDC_STATIC11)->SetWindowText(sycs);
	}
	else
	{
		opXML  opx("configurationfile.xml");
		string m_str = opx.numtoString(0);
		opx.ModifyNode("sycs", m_str);
		opx.SaveFile();
	}
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CMFCblackDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Remainder>0)
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}
