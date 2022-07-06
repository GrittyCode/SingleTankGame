#include "stdfx.h"
#include "CCollisionManager.h"

CCollisionManager* CCollisionManager::m_pInst = nullptr;

void CCollisionManager::Init()
{
	m_objectList = CObjectManager::GetInst()->GetPointObjMap();
}

void CCollisionManager::LateUpdate(OBJ::OBJ_TYPE sourceKey, OBJ::OBJ_TYPE destKey)
{
	isCollision = false;

	list<CObject*>* source_list = CObjectManager::GetInst()->GetMapKey(sourceKey);
	if (source_list->empty()) return;
	list<CObject*>* dest_list = CObjectManager::GetInst()->GetMapKey(destKey);
	if (dest_list->empty()) return;

	for (list<CObject*>::iterator it = source_list->begin(); it != source_list->end(); ++it)
	{
		for (list<CObject*>::iterator it2 = dest_list->begin(); it2 != dest_list->end(); ++it2)
		{
			//BoxCollider2D�� �����Ѵٸ�,
			//���� ������Ʈ�� BoxCollide2D�� �����Ѵٸ�
			map<wstring, Component*>::iterator col_it = (*it)->GetComponentList()->find(L"BoxCollide2D"); //object A�� boxcollide�� ���� ���
			if (col_it != (*it)->GetComponentList()->end())
			{
				//���� ������Ʈ�� BoxCollide2D, CircleCollide2D ��
				map<wstring, Component*>::iterator comp_col_it = (*it2)->GetComponentList()->find(L"BoxCollide2D"); //object B�� boxcollide�� ���� ���
				if (comp_col_it != (*it2)->GetComponentList()->end()) //BoxCollider2D�� �����Ѵٸ�,
				{
					BoxCollider2D* boxA = dynamic_cast<BoxCollider2D*>((*col_it).second);
					BoxCollider2D* boxB = dynamic_cast<BoxCollider2D*>((*comp_col_it).second);

					m_aRect = { (LONG)(boxA->ReturnMyVecPos().x - boxA->GetXSize()), (LONG)(boxA->ReturnMyVecPos().y - boxA->GetYSize()),
								(LONG)(boxA->ReturnMyVecPos().x + boxA->GetXSize()), (LONG)(boxA->ReturnMyVecPos().y  + boxA->GetYSize()) };

					m_bRect = { (LONG)(boxB->ReturnMyVecPos().x - boxB->GetXSize()), (LONG)(boxB->ReturnMyVecPos().y - boxB->GetYSize()),
						(LONG)(boxB->ReturnMyVecPos().x + boxB->GetXSize()), (LONG)(boxB->ReturnMyVecPos().y + boxB->GetYSize()) };

					isCollision = CollisionWithBox(m_aRect, m_bRect);

					if (isCollision)
					{
						//�浹 ó��
  						(*it)->SetObjState(OBJ_COLLISION);
						(*it2)->SetObjState(OBJ_COLLISION);
					}
				}
			}
		}
	}
}

bool CCollisionManager::CollisionWithBox(RECT& rc1, RECT rc2)
{
	if (rc1.right > rc2.left && rc1.left < rc2.right && rc1.top < rc2.bottom && rc1.bottom > rc2.top)
	{
		return true;
	}

	return false;
}

