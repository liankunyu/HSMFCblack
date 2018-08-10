#include <stdio.h>
#include "tinyxml.h"
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <windows.h>
#include <atlstr.h>
using namespace std;

class opXML
{
public:
	TiXmlDocument *pDoc;
	string xmlfile;
	opXML(string XmlFile);
	virtual ~opXML();
	CString GetAppPath();
	bool CreateXmlFile(string& filePath);
	bool ReadXmlFile(string& szFileName);
	bool GetNodePointerByName(TiXmlElement* pRootEle, string &strNodeName, TiXmlElement* &Node);
	bool OpenFile();
	bool SaveFile();
	bool ModifyNode(string strNodeName, string strText);
	bool QueryNode_Text(string strNodeName,const char* &strText);
	bool QueryNodeAttribute(string strNodeName, string &strAttName, string &strAttValue);
	bool QueryNode_Attribute(string strNodeName,map<string, string> &AttMap);
	bool DelNode(string strNodeName);
	bool AddNode_Text(string strParNodeName, string strNodeName, string strText);
	bool ModifyNode_Attribute(string strNodeName,map<string,string> &AttMap);
    void Encode(string &str);
	static string numtoString(double x);
};

