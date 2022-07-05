#pragma once


#define DEGREETORADIAN(t) ((t) * (float)M_PI / (float)180.0f)
#define RADIANTODEGREE(t) (((float)180.0f / (float)M_PI) * (t))


#define OBJ_ERR -1
#define OBJ_NOEVENT 0
#define OBJ_COLLISION 1



#define NO_COPY(className)	private :\
							className(const className& obj);\
							className* operator = (className* obj)\
							{return nullptr;}

//ΩÃ±€≈Ê ∆–≈œ
#define SINGLETONE(ClassName)	\
private:	\
NO_COPY(ClassName);\
ClassName(){}\
~ClassName(){}\
public:\
static ClassName* GetInst()\
{\
	if(m_pInst == NULL)\
		m_pInst = new ClassName;\
	return m_pInst;	\
}\
void DestroyInst()\
{\
	delete m_pInst;\
	m_pInst = nullptr;\
}\
private:\
static ClassName* m_pInst;
