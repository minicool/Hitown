#pragma once

#include "GSocket.h"

typedef struct _GHND_DATA
{
void*						pfnOnIocpOper;
void*						pfnOnIocpError;
SOCKET						Socket;
_GHND_DATA*					pNext;
_GHND_DATA*					pPrior;
GHND_TYPE					htType;
GHND_STATE					hsState;
DWORD						dwAddrFimily;
DWORD						dwAddr;
DWORD						dwPort;
DWORD						dwTickCountAcitve;
void*						pOwner;
void*						pData;
}GHND_DATA, *PGHND_DATA;

typedef	BOOL(*PFN_ON_GHND_CREATE)(PGHND_DATA pHndData);
typedef	void(*PFN_ON_GHND_DESTROY)(PGHND_DATA pHndData);

PGHND_DATA GHndDat_Alloc(void);
void GHndDat_Free(PGHND_DATA pHndData);

extern BOOL bGHndDataIsActive;
void GHndDat_Create(PFN_ON_GHND_CREATE pfnOnCreate);
void GHndDat_Destroy(PFN_ON_GHND_DESTROY pfnOnDestroy);


