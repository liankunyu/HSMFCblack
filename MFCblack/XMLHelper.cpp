#include <stdio.h>
#include "tinyxml.h"
#include <iostream>
#include <cstring>
#include <string>
#include <windows.h>
#include <map>
#include "XMLHelper.h"
#include <sstream>
using namespace std;


opXML::opXML(string XmlFile)
{
	xmlfile = XmlFile;
	OpenFile();
}
opXML::~opXML()
{

}
	//获得应用程序路径
	 CString opXML::GetAppPath()
	 {//获取应用程序根目录
		 TCHAR modulePath[MAX_PATH];
		 GetModuleFileName(NULL, modulePath, MAX_PATH);
		 CString strModulePath(modulePath);
		 strModulePath = strModulePath.Left(strModulePath.ReverseFind(_T('\\')));
		 return strModulePath;
	 }

	 bool opXML::CreateXmlFile(string& szFileName)
	 {//创建xml文件,szFilePath为文件保存的路径,若创建成功返回true,否则false
		 try
		 {
			 //创建一个XML的文档对象。
			 TiXmlDocument *myDocument = new TiXmlDocument();
			 //创建一个根元素并连接。
			 TiXmlElement *RootElement = new TiXmlElement("Persons");
			 myDocument->LinkEndChild(RootElement);
			 //创建一个Person元素并连接。
			 TiXmlElement *PersonElement = new TiXmlElement("Person");
			 RootElement->LinkEndChild(PersonElement);
			 //设置Person元素的属性。
			 PersonElement->SetAttribute("ID", "1");
			 //创建name元素、age元素并连接。
			 TiXmlElement *NameElement = new TiXmlElement("name");
			 TiXmlElement *AgeElement = new TiXmlElement("age");
			 PersonElement->LinkEndChild(NameElement);
			 PersonElement->LinkEndChild(AgeElement);
			 //设置name元素和age元素的内容并连接。
			 TiXmlText *NameContent = new TiXmlText("周星星");
			 TiXmlText *AgeContent = new TiXmlText("22");
			 NameElement->LinkEndChild(NameContent);
			 AgeElement->LinkEndChild(AgeContent);
			 CString appPath = GetAppPath();
			 string seperator = "\\";
			 USES_CONVERSION;
			 string str = T2A(appPath);
			 string fullPath = str + seperator + szFileName;
			 myDocument->SaveFile(fullPath.c_str());//保存到文件
		 }
		 catch (string& e)
		 {
			 return false;
		 }
		 return true;
	 }

	 bool opXML::ReadXmlFile(string& szFileName)
	 {//读取Xml文件，并遍历
		 try
		 {
			 CString appPath = GetAppPath();
			 USES_CONVERSION;
			 string str = T2A(appPath);
			 string seperator = "\\";
			 string fullPath =str+ seperator + szFileName;
			 //创建一个XML的文档对象。
			 TiXmlDocument *myDocument = new TiXmlDocument(fullPath.c_str());
			 myDocument->LoadFile();
			 //获得根元素，即Persons。
			 TiXmlElement *RootElement = myDocument->RootElement();
			 //输出根元素名称，即输出Persons。
			 cout << RootElement->Value() << endl;
			 //获得第一个Person节点。
			 TiXmlElement *FirstPerson = RootElement->FirstChildElement();
			 //获得第一个Person的name节点和age节点和ID属性。
			 TiXmlElement *NameElement = FirstPerson->FirstChildElement();
			 TiXmlElement *AgeElement = NameElement->NextSiblingElement();
			 TiXmlAttribute *IDAttribute = FirstPerson->FirstAttribute();
			 
		 }
		 catch (string& e)
		 {
			 return false;
		 }
		 return true;
	 }
	 //打开XML文档
	 bool opXML::OpenFile()
	 {
		 try
		 {
			 // 定义一个TiXmlDocument类指针
			 pDoc = new TiXmlDocument(xmlfile.c_str());
			 if (NULL == pDoc)
			 {
				 return false;
			 }
			 bool s = pDoc->LoadFile();
			 return s;
		 }
		 catch (string& e)
		 {
			 return false;
		 }
	 }
	 //保存XML文档
	 bool opXML::SaveFile()
	 {
		 try
		 {
			 bool s=pDoc->SaveFile(xmlfile.c_str());
			 return true;
		 }
		 catch (string& e)
		 {
			 return false;
		 }
	 }
	 //修改单个节点值
	 bool opXML::ModifyNode(string strNodeName, string strText)
	 {
		 try
		 {
			 TiXmlElement *pRootEle = pDoc->RootElement();
			 if (NULL == pRootEle)
			 {
				 return false;
			 }
			 TiXmlElement *pNode = NULL;
			 GetNodePointerByName(pRootEle, strNodeName, pNode);
			 if (NULL != pNode)
			 {
				 pNode->Clear();// 首先清除所有文本    
								// 然后插入文本，保存文件    
				 TiXmlText *pValue = new TiXmlText(strText.c_str());
				 pNode->LinkEndChild(pValue);
				 return true;
			 }
			 else
				 return false;
		 }
		 catch (string& e)
		 {
			 return false;
		 }
		 return true;
	 }
	
	 //修改节点属性值
	 bool opXML::ModifyNode_Attribute(string strNodeName,map<string,string> &AttMap)
	 {
		 typedef pair <string,string> String_Pair;
		 TiXmlElement *pRootEle = pDoc->RootElement();
		 if (NULL == pRootEle)
		 {
			 return false;
		 }

		 TiXmlElement *pNode = NULL;
		 GetNodePointerByName(pRootEle, strNodeName, pNode);
		 if (NULL != pNode)
		 {
			 TiXmlAttribute* pAttr = NULL;
			 string strAttName = "";
			 string strAttValue ="";
			 for (pAttr = pNode->FirstAttribute(); pAttr; pAttr = pAttr->Next())
			 {
				 strAttName = pAttr->Name();
				 map<string,string>::iterator iter;
				 for (iter = AttMap.begin(); iter != AttMap.end(); iter++)
				 {
					 if (strAttName == iter->first)
					 {
						 pAttr->SetValue(iter->second.c_str());
					 } 
				 }
			 }
			 return true;
		 }
		 else
		 {
			 return false;
		 }
	 }
	 
	 //获取单个节点值
	 bool opXML::GetNodePointerByName(TiXmlElement* pRootEle,  string &strNodeName, TiXmlElement* &Node)
	 {
		 try 
		 {
			 // 假如等于根节点名，就退出    
			 if (strNodeName == pRootEle->Value())
			 {
				 Node = pRootEle;
				 return true;
			 }
			 TiXmlElement* pEle = pRootEle;
			 for (pEle = pRootEle->FirstChildElement(); pEle; pEle = pEle->NextSiblingElement())
			 {
				 //递归处理子节点，获取节点指针    
				 if (GetNodePointerByName(pEle, strNodeName, Node))
					 return true;
			 }
			 return false;
		 }
		
		 catch (string& e)
		 {
			 return false;
		 }
		 return true;
	 }
	 
	 //获取节点文本
	 bool opXML::QueryNode_Text(string strNodeName,const char* &strText)
	 {
		 try
		 {
			 TiXmlElement *pRootEle = pDoc->RootElement();
			 if (NULL == pRootEle)
			 {
				 return false;
			 }
			 TiXmlElement *pNode = NULL;
			 GetNodePointerByName(pRootEle, strNodeName, pNode);
			 if (NULL != pNode)
			 {
				 strText = pNode->GetText();
				 return true;
			 }
			 else
			 {
				 return false;
			 }
		 }
		 catch (string& e)
		 {
			 return false;
		 }
		 return true;
	 }

	 //获取节点单个属性值
	 bool opXML::QueryNodeAttribute( string strNodeName, string &strAttName,string &strAttValue)
	 {
		 try
		 {
			 
			 TiXmlElement *pRootEle = pDoc->RootElement();
			 if (NULL == pRootEle)
			 {
				 return false;
			 }
			 TiXmlElement *pNode = NULL;
			 GetNodePointerByName(pRootEle, strNodeName, pNode);
			 if (NULL != pNode)
			 {
				 TiXmlAttribute* pAttr = NULL;
				 pAttr = pNode->FirstAttribute();
				 strAttName = pAttr->Name();
				 strAttValue = pAttr->Value();
				 return true;
			 }
			 else
			 {
				 return false;
			 }
		 }
		 catch (string& e)
		 {
			 return false;
		 }
		 return true;
	 }
	 
	 //获取节点所有属性值
	 bool opXML::QueryNode_Attribute(string strNodeName,map<string,string> &AttMap)
	 {
		 try
		 {
			 // 定义一个TiXmlDocument类指针  
			 typedef std::pair <std::string, std::string> String_Pair;
			 TiXmlElement *pRootEle = pDoc->RootElement();
			 if (NULL == pRootEle)
			 {
				 return false;
			 }
			 TiXmlElement *pNode = NULL;
			 GetNodePointerByName(pRootEle, strNodeName, pNode);
			 if (NULL != pNode)
			 {
				 TiXmlAttribute* pAttr = NULL;
				 for (pAttr = pNode->FirstAttribute(); pAttr; pAttr = pAttr->Next())
				 {
					 std::string strAttName = pAttr->Name();
					 std::string strAttValue = pAttr->Value();
					 AttMap.insert(String_Pair(strAttName, strAttValue));
				 }
				 return true;
			 }
			 else
			 {
				 return false;
			 }
		 }
		 catch (string& e)
		 {
			 return false;
		 }
		 return true;
		 
	 }

	 //删除节点操作
	 bool opXML::DelNode(string strNodeName)
	 {
		 try
		 {
			 TiXmlElement *pRootEle = pDoc->RootElement();
			 if (NULL == pRootEle)
			 {
				 return false;
			 }
			 TiXmlElement *pNode = NULL;
			 GetNodePointerByName(pRootEle, strNodeName, pNode);
			 // 假如是根节点  
			 if (pRootEle == pNode)
			 {
				 if (pDoc->RemoveChild(pRootEle))
				 {
					 return true;
				 }
				 else
					 return false;
			 }
			 // 假如是其它节点  
			 if (NULL != pNode)
			 {
				 TiXmlNode *pParNode = pNode->Parent();
				 if (NULL == pParNode)
				 {
					 return false;
				 }

				 TiXmlElement* pParentEle = pParNode->ToElement();
				 if (NULL != pParentEle)
				 {
					 if (pParentEle->RemoveChild(pNode))
					 {
						 return true;
					 }
					 else
						 return false;
				 }
			 }
			 else
			 {
				 return false;
			 }
		 }
		 catch (string& e)
		 {
			 return false;
		 }
		 return true;
		
	 }

	 //增加节点
	 bool opXML::AddNode_Text(string strParNodeName,string strNodeName,string strText)
	 {
		 try
		 {
			 TiXmlElement *pRootEle = pDoc->RootElement();
			 if (NULL == pRootEle)
			 {
				 return false;
			 }
			 TiXmlElement *pNode = NULL;
			 GetNodePointerByName(pRootEle, strParNodeName, pNode);
			 if (NULL != pNode)
			 {
				 // 生成子节点：pNewNode  
				 TiXmlElement *pNewNode = new TiXmlElement(strNodeName.c_str());
				 if (NULL == pNewNode)
				 {
					 return false;
				 }
				 // 设置节点文本，然后插入节点  
				 TiXmlText *pNewValue = new TiXmlText(strText.c_str());
				 pNewNode->LinkEndChild(pNewValue);
				 pNode->InsertEndChild(*pNewNode);
				 return true;
			 }
			 else
				 return false;
		 }
		 catch (string& e)
		 {
			 return false;
		 }
		 return true;
	 }

	 //加密
	 void opXML::Encode(string &str)
	 {
		 char *pstr;
		 pstr = (char *)str.data();
		 int len = strlen(pstr);//获取长度
		 for (int i = 0; i < len; i++)
			 *(pstr + i) = *(pstr + i) ^ (i+8);
		 str = pstr;
	 }

	 //double转string
	 string opXML::numtoString(double x)
	 {
		 stringstream ss;
		 string sss;
		 ss << x;
		 ss >> sss;
		 return sss;

	 }




