#pragma once
class CObject
{
private:
	CObject(const CObject& obj);
	CObject* operator = (CObject* obj)
	{return nullptr; }
	CObject() {}
	~CObject() {}
public:
	static CObject* GetInst()
{
if (m_pInst == NULL)
m_pInst = new CObject;
return m_pInst;	
}
void DestroyInst()
{
delete m_pInst; 
m_pInst = nullptr; 
}
private:
	static CObject* m_pInst;
};

	