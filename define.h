#pragma once



#define M_PI 3.141592
#define DEGREETORADIAN(t) (t) / 180.0 * M_PI
#define RADIANTODEGREE(t) (M_PI / 180.0f) * (t)


#define OBJ_ERR -1
#define OBJ_NOEVENT 0
#define OBJ_DEAD 1



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
