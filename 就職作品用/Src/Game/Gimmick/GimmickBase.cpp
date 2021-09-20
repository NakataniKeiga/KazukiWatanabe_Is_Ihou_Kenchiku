#include"GimmickBase.h"

VECTOR CGimmickBase::GetCenter()
{
	VECTOR vCenter = MV1GetPosition(m_iHndl);
	vCenter.y += 1.0f;
	return vCenter;
}