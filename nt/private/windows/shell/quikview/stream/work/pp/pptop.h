#include "platform.h"

#ifdef WINDOWS

#define VWPTR __far
#define VW_ENTRYSC
#define VW_ENTRYMOD	__export __far __pascal
#define VW_LOCALSC
#define VW_LOCALMOD	__near __cdecl
#define VW_SEPARATE_DATA

#endif /*WINDOWS*/

#ifdef MAC

#define VWPTR 
#define VW_ENTRYSC
#define VW_ENTRYMOD
#define VW_LOCALSC
#define VW_LOCALMOD
#define VW_SEPARATE_DATA

#endif /*MAC*/

	/*
	|	Include XIO defines, structures and macros
	|
	|	Note: VXIO.H is VSCTOP specific and may use any
	|	of the VwStream #defines in vsp_???.h

#include "vxio.h"
	*/

#include "sccfi.h"
#include "sodefs.h"

	/*
	|	Include viewer's data types and typedef HPROC
	*/

#include VwInclude

typedef struct PROCtag
	{
	VwStreamDynamicType	VwData;
	SORTNS					SoRtns;
	DWORD						User1;
	DWORD						User2;
	CHAR						Path[80];
//	VXIO						XioData;
	} NEAR * HPROC;

#include "vwdefs.h"

	/*
	|	Do functions prototypes for Vw functions
	*/

extern	FILTER_DESC	VwStreamIdName[];

#ifdef VwStreamStaticType
extern	VwStreamStaticType VwStreamStaticName;
#endif

#ifdef VwStreamOpenFunc
#undef VwStreamOpenFunc
#define VwStreamOpenFunc			VwStreamOpen
VW_ENTRYSC SHORT VW_ENTRYMOD	VwStreamOpenFunc(SOFILE, SHORT, BYTE VWPTR *, SOFILTERINFO VWPTR * ,HPROC);
#endif

#ifdef VwStreamCloseFunc

#undef VwStreamCloseFunc
#define VwStreamCloseFunc		VwStreamClose
VW_ENTRYSC VOID VW_ENTRYMOD	VwStreamCloseFunc(SOFILE, HPROC);

#else

#undef VwStreamCloseFunc
#define VwStreamCloseFunc		VwStreamClose
VW_ENTRYSC VOID VW_ENTRYMOD	VwStreamCloseFunc(SOFILE, HPROC);
VW_ENTRYSC VOID VW_ENTRYMOD VwStreamCloseFunc(hFile,hProc)
SOFILE			hFile;
HPROC			hProc;
{
}

#endif

#ifdef VwStreamSectionFunc
#undef VwStreamSectionFunc
#define VwStreamSectionFunc			VwStreamSection
VW_ENTRYSC SHORT VW_ENTRYMOD	VwStreamSectionFunc(SOFILE, HPROC);
#endif

#ifdef VwStreamReadFunc		
#undef VwStreamReadFunc		
#define VwStreamReadFunc		VwStreamRead
VW_ENTRYSC SHORT VW_ENTRYMOD	VwStreamReadFunc(SOFILE, HPROC);
#endif

#ifdef VwStreamReadRecordFunc

#undef VwStreamReadRecordFunc
#define VwStreamReadRecordFunc	VwStreamReadRecord
VW_ENTRYSC VOID VW_ENTRYMOD		VwStreamReadRecordFunc(SOFILE, DWORD, HPROC);

#else

#define VwStreamReadRecordFunc	VwStreamReadRecord
VW_ENTRYSC VOID VW_ENTRYMOD		VwStreamReadRecordFunc(SOFILE, DWORD, HPROC);
VW_ENTRYSC VOID VW_ENTRYMOD VwStreamReadRecordFunc(hFile,dwData,hProc)
SOFILE	hFile;
DWORD	dwData;
HPROC	hProc;
{
}

#endif

#ifdef VwDoSpecialFunc

#undef VwDoSpecialFunc
#define VwDoSpecialFunc			VwDoSpecial
VW_ENTRYSC VOID VW_ENTRYMOD	VwDoSpecialFunc(SOFILE,DWORD,DWORD,DWORD,DWORD,DWORD,HPROC);

#else

#define VwDoSpecialFunc			VwDoSpecial
VW_ENTRYSC VOID VW_ENTRYMOD	VwDoSpecialFunc(SOFILE,DWORD,DWORD,DWORD,DWORD,DWORD,HPROC);
VW_ENTRYSC VOID VW_ENTRYMOD 	VwDoSpecialFunc(hFile, dw1,dw2,dw3,dw4,dw5,hProc)
SOFILE		hFile;
DWORD		dw1;
DWORD		dw2;
DWORD		dw3;
DWORD		dw4;
DWORD		dw5;
HPROC		hProc;
{
}
#endif

#ifdef VwStreamTellFunc			
#undef VwStreamTellFunc			
#define VwStreamTellFunc		VwStreamTell
VW_ENTRYSC SHORT VW_ENTRYMOD	VwStreamTellFunc(SOFILE, HPROC);
#endif

#ifdef VwStreamSeekFunc			
#undef VwStreamSeekFunc			
#define VwStreamSeekFunc		VwStreamSeek
VW_ENTRYSC SHORT VW_ENTRYMOD	VwStreamSeekFunc(SOFILE, HPROC);
#endif

#ifdef VwGetInfoFunc	
#undef VwGetInfoFunc	
#define VwGetInfoFunc		VwGetInfo
VW_ENTRYSC BOOL VW_ENTRYMOD	VwGetInfoFunc(VOID VWPTR *, WORD, HPROC);
#endif

#ifdef VwGetRtnsFunc	
#undef VwGetRtnsFunc	
#define VwGetRtnsFunc		VwGetRtns
VW_ENTRYSC VOID VW_ENTRYMOD VwGetRtnsFunc(VWRTNS VWPTR *, WORD);
#endif

#ifdef VwGetDataFunc	
#undef VwGetDataFunc	
#define VwGetDataFunc		VwGetData
VW_ENTRYSC VOID VW_ENTRYMOD	VwGetDataFunc(VwStreamSaveType VWPTR *, HPROC);
#endif

#ifdef VwSetDataFunc	
#undef VwSetDataFunc	
#define VwSetDataFunc		VwSetData
VW_ENTRYSC VOID VW_ENTRYMOD	VwSetDataFunc(VwStreamSaveType VWPTR *, HPROC);
#endif

#ifdef VwStreamSectionType

#ifdef VwGetSectionDataFunc	
#undef VwGetSectionDataFunc	
#define VwGetSectionDataFunc		VwGetSectionData
VW_ENTRYSC VOID VW_ENTRYMOD	VwGetSectionDataFunc(VwStreamSectionType VWPTR *, HPROC);
#endif

#ifdef VwSetSectionDataFunc
#undef VwSetSectionDataFunc
#define VwSetSectionDataFunc		VwSetSectionData
VW_ENTRYSC VOID VW_ENTRYMOD	VwSetSectionDataFunc(VwStreamSectionType VWPTR *, HPROC);
#endif

#else

#ifdef VwGetSectionDataFunc	
#undef VwGetSectionDataFunc	
#endif
#define VwGetSectionDataFunc		VwGetSectionData
VW_ENTRYSC VOID VW_ENTRYMOD	VwGetSectionDataFunc(VOID VWPTR *, HPROC);

#ifdef VwSetSectionDataFunc
#undef VwSetSectionDataFunc
#endif
#define VwSetSectionDataFunc		VwSetSectionData
VW_ENTRYSC VOID VW_ENTRYMOD	VwSetSectionDataFunc(VOID VWPTR *, HPROC);

#endif

#ifdef VwLocalUpFunc	
#undef VwLocalUpFunc	
#define VwLocalUpFunc		VwLocalUp
VW_ENTRYSC VOID VW_ENTRYMOD	VwLocalUpFunc(SHORT, BYTE VWPTR *, HPROC);
#endif

#ifdef VwLocalDownFunc	
#undef VwLocalDownFunc	
#define VwLocalDownFunc		VwLocalDown
VW_ENTRYSC VOID VW_ENTRYMOD	VwLocalDownFunc(SHORT, HPROC);
#endif

#ifdef VwAllocProcFunc	
#undef VwAllocProcFunc	
#define VwAllocProcFunc	VwAllocProc
VW_ENTRYSC HPROC VW_ENTRYMOD	VwAllocProcFunc(VOID);
#endif

#ifdef VwFreeProcFunc
#undef VwFreeProcFunc
#define VwFreeProcFunc	VwFreeProc
VW_ENTRYSC VOID VW_ENTRYMOD	VwFreeProcFunc(HPROC);
#endif

#define VwSetUserFunc	VwSetUser
VW_ENTRYSC VOID VW_ENTRYMOD VwSetUserFunc(DWORD,DWORD,HPROC);

#define VwSetSoRtnFunc	VwSetSoRtn
VW_ENTRYSC VOID VW_ENTRYMOD VwSetSoRtnFunc(SHORT, VOID (SO_ENTRYMOD *)(), HPROC);

#ifdef VwStreamStaticType
#define Init	VwStreamStaticName
#endif

#define Proc (hProc->VwData)

	/*
	| Make some standard library functions available
	*/

#ifdef WINDOWS

void far * far _cdecl _fmemmove(void far *, const void far *,	unsigned int);
void far * far _cdecl _fmemcpy(void far *, const void far *,unsigned int);
void far * far _cdecl _fmemset(void far *, int, unsigned int);
// void far * far _cdecl _fmemcmp(void far *, void far *,unsigned int);

int _cdecl atoi(const char *);
long _cdecl atol(const char *);
int Vatoi(char far *);
long Vatol(char far *);

#define strcmp	lstrcmp
#define strcmpi	lstrcmpi
#define strcpy	lstrcpy
#define strcat	lstrcat
#define strlen	lstrlen
#define memcpy	_fmemcpy
#define memset	_fmemset
#define memmove	_fmemmove
#define memcmp	_fmemcmp

int Vatoi(pStr)
char far * pStr;
{
static char locStr[20];

	lstrcpy(locStr,pStr);
	return(atoi(locStr));
}

long Vatol(pStr)
char far * pStr;
{
static char locStr[20];

	lstrcpy(locStr,pStr);
	return(atol(locStr));
}

#define atoi(s)	Vatoi((char far *) s)
#define atol(s)	Vatol((char far *) s)

#define SUAlloc(size,hProc)				GlobalAlloc(GMEM_MOVEABLE,size)
#define SUFree(handle,hProc)				GlobalFree(handle)
#define SULock(handle,hProc)				((VOID FAR *) GlobalLock(handle))
#define SUUnlock(handle,hProc)			GlobalUnlock(handle)
#define SUReAlloc(handle,size,hProc)	GlobalReAlloc(handle,size,0)

#define SUSeekEntry(hF,hProc) {hProc->XioData.hFile = hF;}

#endif /*WINDOWS*/

#ifdef MAC

#include "vsctop.mac"

#define SUAlloc(size,hProc)				NewHandle(size)
#define SUFree(handle,hProc)				DisposHandle(handle)
#define SUUnlock(handle,hProc)			HUnlock(handle)
#define SUReAlloc(handle,size,hProc)	(SetHandleSize(handle,size) == noErr ? (handle) : NULL)

VOID * SULock(HANDLE,HPROC);

VOID * SULock(hMem,hProc)
HANDLE 	hMem;
HPROC	hProc;
{
VOID * locRet;
	
	locRet = NULL;

	if ((OSErr)MoveHHi(hMem) == noErr)
		{
		if ((OSErr)HLock(hMem) == noErr)
			{
			locRet = *hMem;
			}
		}

	return(locRet);
}


#define SUSeekEntry(hF,hProc)

VW_ENTRYSC VOID VW_ENTRYMOD GetCRRoutines(pRtns,wLastRtn)
VWRTNS VWPTR * pRtns;
WORD           wLastRtn;
{
	VwGetRtnsFunc(pRtns,wLastRtn);
}

#endif /*MAC*/

#ifdef VwStreamGenSeekName

VW_ENTRYSC SHORT VW_ENTRYMOD VwStreamSeekFunc(hFile,hProc)
SOFILE	hFile;
HPROC	hProc;
{
	SUSeekEntry(hFile,hProc);
	return(xseek(hFile,Proc.VwStreamSaveName.VwStreamGenSeekName,FR_BOF));
}

VW_ENTRYSC SHORT VW_ENTRYMOD VwStreamTellFunc(hFile,hProc)
SOFILE	hFile;
HPROC	hProc;
{
	Proc.VwStreamSaveName.VwStreamGenSeekName = xtell(hFile);
	return(0);
}

#endif

#ifdef WINDOWS

VW_ENTRYSC HPROC VW_ENTRYMOD VwAllocProcFunc()
{
HANDLE	hData;

	if ((hData = LocalAlloc(LMEM_FIXED | LMEM_ZEROINIT,sizeof(struct PROCtag))) == NULL)
		return(NULL);
	else
		return((HPROC)LocalLock(hData));
}

VW_ENTRYSC VOID VW_ENTRYMOD VwFreeProcFunc(hProc)
HPROC	hProc;
{
HANDLE	hData;

	if ((hData = LocalHandle((WORD)hProc)) != NULL)
		LocalFree(hData);
}

#endif /*WINDOWS*/

#ifdef MAC

VW_ENTRYSC HPROC VW_ENTRYMOD VwAllocProcFunc()
{
	return((HPROC)NewPtr(sizeof(struct PROCtag)));
}

VW_ENTRYSC VOID VW_ENTRYMOD VwFreeProcFunc(hProc)
HPROC	hProc;
{
	DisposPtr(hProc);
}

#endif /*MAC*/

VW_ENTRYSC BOOL VW_ENTRYMOD VwGetInfoFunc(pInfo,wInfoId,hProc)
VOID VWPTR *				pInfo;
WORD							wInfoId;
HPROC						hProc;
{
BOOL	locRet;
WORD	locIndex;

	locRet = TRUE;

	switch (wInfoId)
		{
		case VWINFO_CHECK:
			*(DWORD VWPTR *)pInfo = 0x12345678;
			break;

		case VWINFO_SAVESIZE:
#ifdef VwStreamSaveType
			*(WORD VWPTR *)pInfo = sizeof(VwStreamSaveType);
#else
			*(WORD VWPTR *)pInfo = 0;
#endif
			break;

		case VWINFO_DYNAMICSIZE:
#ifdef VwStreamDynamicType
			*(WORD VWPTR *)pInfo = sizeof(VwStreamDynamicType);
#else
			*(WORD VWPTR *)pInfo = 0;
#endif
			break;

		case VWINFO_STATICSIZE:
#ifdef VwStreamStaticType
			*(WORD VWPTR *)pInfo = sizeof(VwStreamStaticType);
#else
			*(WORD VWPTR *)pInfo = 0;
#endif
			break;

		case VWINFO_SPECLEVEL:
			*(WORD VWPTR *)pInfo = 350;
			break;

		case VWINFO_FILTERLEVEL:
			*(WORD VWPTR *)pInfo = 360;
			break;

		case VWINFO_IDCOUNT:
			*(WORD VWPTR *)pInfo = VwStreamIdCount;
			break;

		case VWINFO_IDS:
			for (locIndex = 0; locIndex < VwStreamIdCount; locIndex++)
				{
				((WORD VWPTR *)pInfo)[locIndex] = VwStreamIdName[locIndex].FilterId;
				}
			break;

		case VWINFO_DATE:
			strcpy((BYTE VWPTR *)pInfo,__DATE__);
			break;

		case VWINFO_TIME:
			strcpy((BYTE VWPTR *)pInfo,__TIME__);
			break;

		case VWINFO_USERSAVESIZE:
#ifdef VwStreamUserSaveType
			*(WORD VWPTR *)pInfo = sizeof(VwStreamUserSaveType);
#else
			*(WORD VWPTR *)pInfo = 0;
#endif
			break;

		case VWINFO_SECTIONSAVESIZE:
#ifdef VwStreamSectionType
			*(WORD VWPTR *)pInfo = sizeof(VwStreamSectionType);
#else
			*(WORD VWPTR *)pInfo = 0;
#endif
			break;

		default:
			locRet = FALSE;
			break;
		}

	return(locRet);
}

VW_ENTRYSC VOID VW_ENTRYMOD VwGetDataFunc(pSaveData,hProc)
VwStreamSaveType VWPTR *	pSaveData;
HPROC							hProc;
{
	*pSaveData = Proc.VwStreamSaveName;
}

VW_ENTRYSC VOID VW_ENTRYMOD VwSetDataFunc(pSaveData,hProc)
VwStreamSaveType VWPTR *	pSaveData;
HPROC							hProc;
{
	Proc.VwStreamSaveName = *pSaveData;
}

#ifdef VwStreamSectionType

VW_ENTRYSC VOID VW_ENTRYMOD VwGetSectionDataFunc(pSectionData,hProc)
VwStreamSectionType VWPTR *	pSectionData;
HPROC								hProc;
{
	*pSectionData = Proc.VwStreamSectionName;
}

VW_ENTRYSC VOID VW_ENTRYMOD VwSetSectionDataFunc(pSectionData,hProc)
VwStreamSectionType VWPTR *	pSectionData;
HPROC								hProc;
{
	Proc.VwStreamSectionName = *pSectionData;
}

#else

VW_ENTRYSC VOID VW_ENTRYMOD VwGetSectionDataFunc(pSectionData,hProc)
VOID VWPTR *	pSectionData;
HPROC			hProc;
{
}

VW_ENTRYSC VOID VW_ENTRYMOD VwSetSectionDataFunc(pSectionData,hProc)
VOID VWPTR *	pSectionData;
HPROC			hProc;
{
}

#endif

VOID FAR SODummy()
{
}

VW_ENTRYSC VOID VW_ENTRYMOD VwLocalUpFunc(hFile,pPath,hProc)
SHORT				hFile;
BYTE VWPTR *		pPath;
HPROC				hProc;
{
//	xinit(&(hProc->XioData),hFile);

	if (pPath)
		strcpy(hProc->Path,pPath);

#ifdef WINDOWS
#if _MSC_VER >= 700
#define CAST	(VOID FAR *)
#else
#define CAST	(VOID (SO_ENTRYMOD *)())
#endif
#endif /*WINDOWS*/

#ifdef MAC



#define CAST	(VOID *)
#endif /*MAC*/

	hProc->SoRtns.SOPutChar = CAST SODummy;
	hProc->SoRtns.SOPutCharX = CAST SODummy;
	hProc->SoRtns.SOPutSpecialCharX = CAST SODummy;
	hProc->SoRtns.SOPutCharAttr = CAST SODummy;
	hProc->SoRtns.SOPutCharHeight = CAST SODummy;
	hProc->SoRtns.SOPutParaAlign = CAST SODummy;
	hProc->SoRtns.SOPutParaIndents = CAST SODummy;
	hProc->SoRtns.SOStartTabStops = CAST SODummy;
	hProc->SoRtns.SOEndTabStops = CAST SODummy;
	hProc->SoRtns.SOPutTabStop = CAST SODummy;
	hProc->SoRtns.SOPutMargins = CAST SODummy;
	hProc->SoRtns.SOPutSubdocInfo = CAST SODummy;
	hProc->SoRtns.SOPutBreak = CAST SODummy;
	hProc->SoRtns.SOPutDataCell = CAST SODummy;
	hProc->SoRtns.SOPutTextCell = CAST SODummy;
	hProc->SoRtns.SOPutMoreText = CAST SODummy;
	hProc->SoRtns.SOPutField = CAST SODummy;
	hProc->SoRtns.SOPutVarField = CAST SODummy;
	hProc->SoRtns.SOPutMoreVarField = CAST SODummy;
	hProc->SoRtns.SOStartColumnInfo = CAST SODummy;
	hProc->SoRtns.SOStartFieldInfo = CAST SODummy;
	hProc->SoRtns.SOPutColumnInfo = CAST SODummy;
	hProc->SoRtns.SOPutFieldInfo = CAST SODummy;
	hProc->SoRtns.SOEndColumnInfo = CAST SODummy;
	hProc->SoRtns.SOEndFieldInfo = CAST SODummy;
	hProc->SoRtns.SOPutSectionType = CAST SODummy;
	hProc->SoRtns.SOPutSectionName = CAST SODummy;
	hProc->SoRtns.SOSetDateBase = CAST SODummy;
	hProc->SoRtns.SOBailOut = CAST SODummy;
	hProc->SoRtns.SOTagBegin = CAST SODummy;
	hProc->SoRtns.SOTagEnd = CAST SODummy;
	hProc->SoRtns.SOGetInfo = CAST SODummy;
	hProc->SoRtns.SOPutString = CAST SODummy;
	hProc->SoRtns.SUUserSaveData = CAST SODummy;
	hProc->SoRtns.SUUserRetrieveData = CAST SODummy;
	hProc->SoRtns.SOPutBitmapHeader  = CAST SODummy;
	hProc->SoRtns.SOStartPalette  = CAST SODummy;
	hProc->SoRtns.SOPutPaletteEntry  = CAST SODummy;
	hProc->SoRtns.SOEndPalette = CAST SODummy;
	hProc->SoRtns.SOPutScanLineData = CAST SODummy;
	hProc->SoRtns.SOStartFontTable = CAST SODummy;
	hProc->SoRtns.SOPutFontTableEntry = CAST SODummy;
	hProc->SoRtns.SOEndFontTable = CAST SODummy;
	hProc->SoRtns.SOPutCharFontById = CAST SODummy;
	hProc->SoRtns.SOPutCharFontByName = CAST SODummy;
	hProc->SoRtns.SOPutParaSpacing = CAST SODummy;
	hProc->SoRtns.SOPutArchiveField = CAST SODummy;
	hProc->SoRtns.SOStartHdrInfo = CAST SODummy;
	hProc->SoRtns.SOEndHdrInfo = CAST SODummy;
	hProc->SoRtns.SOPutHdrEntry = CAST SODummy;
	hProc->SoRtns.SOPutVectorHeader = CAST SODummy;
	hProc->SoRtns.SOVectorObject = CAST SODummy;
	hProc->SoRtns.SOVectorAttr = CAST SODummy; 
	hProc->SoRtns.SOBeginTable = CAST SODummy; 
	hProc->SoRtns.SOEndTable = CAST SODummy; 			
	hProc->SoRtns.SOPutTableRowFormat = CAST SODummy; 
	hProc->SoRtns.SOPutTableCellInfo = CAST SODummy; 	
	hProc->SoRtns.SOPutGraphicObject = CAST SODummy;
	hProc->SoRtns.SOGoToPosition = CAST SODummy;
	hProc->SoRtns.SODrawLine = CAST SODummy;

#undef CAST
}


VW_ENTRYSC VOID VW_ENTRYMOD VwLocalDownFunc(hFile,hProc)
SHORT				hFile;
HPROC			hProc;
{
}



VW_ENTRYSC VOID VW_ENTRYMOD VwSetSoRtnFunc(wRtn,pRtn,hProc)
SHORT				wRtn;
VOID				(SO_ENTRYMOD * pRtn)();
HPROC			hProc;
{
	if (pRtn == NULL)
		pRtn = SODummy;

#ifdef WINDOWS

#if _MSC_VER >= 700
#define CAST	(VOID FAR *)
#else
#define CAST	(VOID (SO_ENTRYMOD *)())
#endif

#endif /*WINDOWS*/

#ifdef MAC
#define CAST	(VOID *)
#endif /*MAC*/

	switch (wRtn)
		{
		case SOPUTCHAR:
			hProc->SoRtns.SOPutChar = CAST pRtn;
			break;
		case SOPUTCHARX:
			hProc->SoRtns.SOPutCharX = CAST pRtn;
			break;
		case SOPUTSPECIALCHARX:
			hProc->SoRtns.SOPutSpecialCharX = CAST pRtn;
			break;
		case SOPUTCHARATTR:
			hProc->SoRtns.SOPutCharAttr = CAST pRtn;
			break;
		case SOPUTCHARHEIGHT:
			hProc->SoRtns.SOPutCharHeight = CAST pRtn;
			break;
		case SOPUTPARAALIGN:
			hProc->SoRtns.SOPutParaAlign = CAST pRtn;
			break;
		case SOPUTPARAINDENTS:
			hProc->SoRtns.SOPutParaIndents = CAST pRtn;
			break;
		case SOSTARTTABSTOPS:
			hProc->SoRtns.SOStartTabStops = CAST pRtn;
			break;
		case SOENDTABSTOPS:
			hProc->SoRtns.SOEndTabStops = CAST pRtn;
			break;
		case SOPUTTABSTOP:
			hProc->SoRtns.SOPutTabStop = CAST pRtn;
			break;
		case SOPUTMARGINS:
			hProc->SoRtns.SOPutMargins = CAST pRtn;
			break;
		case SOPUTSUBDOCINFO:
			hProc->SoRtns.SOPutSubdocInfo = CAST pRtn;
			break;
		case SOPUTBREAK:
			hProc->SoRtns.SOPutBreak = CAST pRtn;
			break;
		case	SOPUTDATACELL:
			hProc->SoRtns.SOPutDataCell = CAST pRtn;
			break;
		case	SOPUTTEXTCELL:	
			hProc->SoRtns.SOPutTextCell = CAST pRtn;
			break;
		case	SOPUTMORETEXT:	
			hProc->SoRtns.SOPutMoreText = CAST pRtn;
			break;
		case	SOPUTFIELD:		
			hProc->SoRtns.SOPutField = CAST pRtn;
			break;
		case	SOPUTVARFIELD:	
			hProc->SoRtns.SOPutVarField = CAST pRtn;
			break;
		case	SOPUTMOREVARFIELD:
			hProc->SoRtns.SOPutMoreVarField = CAST pRtn;
			break;
		case	SOSTARTCOLUMNINFO:
			hProc->SoRtns.SOStartColumnInfo = CAST pRtn;
			break;
		case	SOSTARTFIELDINFO:	
			hProc->SoRtns.SOStartFieldInfo = CAST pRtn;
			break;
		case	SOPUTCOLUMNINFO:	
			hProc->SoRtns.SOPutColumnInfo = CAST pRtn;
			break;
		case	SOPUTFIELDINFO:	
			hProc->SoRtns.SOPutFieldInfo = CAST pRtn;
			break;
		case	SOENDCOLUMNINFO:	
			hProc->SoRtns.SOEndColumnInfo = CAST pRtn;
			break;
		case	SOENDFIELDINFO:	
			hProc->SoRtns.SOEndFieldInfo = CAST pRtn;
			break;
		case	SOPUTSECTIONTYPE:
			hProc->SoRtns.SOPutSectionType = CAST pRtn;
			break;
		case	SOPUTSECTIONNAME:
			hProc->SoRtns.SOPutSectionName = CAST pRtn;
			break;
		case	SOSETDATEBASE:
			hProc->SoRtns.SOSetDateBase = CAST pRtn;
			break;
		case	SOBAILOUT:
			hProc->SoRtns.SOBailOut = CAST pRtn;
			break;
		case	SOTAGBEGIN:
			hProc->SoRtns.SOTagBegin = CAST pRtn;
			break;
		case	SOTAGEND:
			hProc->SoRtns.SOTagEnd = CAST pRtn;
			break;
		case	SOGETINFO:
			hProc->SoRtns.SOGetInfo = CAST pRtn;
			break;
		case	SOPUTSTRING:
			hProc->SoRtns.SOPutString = CAST pRtn;
			break;
		case	SUUSERSAVEDATA:
			hProc->SoRtns.SUUserSaveData = CAST pRtn;
			break;
		case	SUUSERRETRIEVEDATA:
			hProc->SoRtns.SUUserRetrieveData = CAST pRtn;
			break;
		case	SOPUTBITMAPHEADER:
			hProc->SoRtns.SOPutBitmapHeader = CAST pRtn;
			break;
		case	SOSTARTPALETTE:
			hProc->SoRtns.SOStartPalette  = CAST pRtn;
			break;
		case	SOPUTPALETTEENTRY:
			hProc->SoRtns.SOPutPaletteEntry = CAST pRtn;
			break;
		case	SOENDPALETTE:
			hProc->SoRtns.SOEndPalette = CAST pRtn;
			break;
		case	SOPUTSCANLINEDATA:
			hProc->SoRtns.SOPutScanLineData = CAST pRtn;
			break;
		case	SOSTARTFONTTABLE:
			hProc->SoRtns.SOStartFontTable = CAST pRtn;
			break;
		case	SOPUTFONTTABLEENTRY:
			hProc->SoRtns.SOPutFontTableEntry = CAST pRtn;
			break;
		case	SOENDFONTTABLE:
			hProc->SoRtns.SOEndFontTable = CAST pRtn;
			break;
		case	SOPUTCHARFONTBYID:
			hProc->SoRtns.SOPutCharFontById = CAST pRtn;
			break;
		case	SOPUTCHARFONTBYNAME:
			hProc->SoRtns.SOPutCharFontByName = CAST pRtn;
			break;
		case	SOPUTPARASPACING:
			hProc->SoRtns.SOPutParaSpacing = CAST pRtn;
			break;
		case	SOPUTARCHIVEFIELD:
			hProc->SoRtns.SOPutArchiveField = CAST pRtn;
			break;
		case	SOSTARTHDRINFO:
			hProc->SoRtns.SOStartHdrInfo = CAST pRtn;
			break;
		case	SOENDHDRINFO:
	
		hProc->SoRtns.SOEndHdrInfo = CAST pRtn;
			break;
		case	SOPUTHDRENTRY:
			hProc->SoRtns.SOPutHdrEntry = CAST pRtn;
			break;
		case	SOPUTVECTORHEADER:
			hProc->SoRtns.SOPutVectorHeader = CAST pRtn;
			break;
		case	SOVECTOROBJECT: 
			hProc->SoRtns.SOVectorObject = CAST pRtn;
			break;
		case	SOVECTORATTR: 
			hProc->SoRtns.SOVectorAttr = CAST pRtn; 
			break;
		case SOBEGINTABLE:
			hProc->SoRtns.SOBeginTable = CAST pRtn; 
			break;
		case SOENDTABLE:
			hProc->SoRtns.SOEndTable = CAST pRtn; 			
			break;
		case SOPUTTABLEROWFORMAT:
			hProc->SoRtns.SOPutTableRowFormat = CAST pRtn; 
			break;
		case SOPUTTABLECELLINFO:
			hProc->SoRtns.SOPutTableCellInfo = CAST pRtn; 	
			break;
		case SOPUTGRAPHICOBJECT:
			hProc->SoRtns.SOPutGraphicObject = CAST pRtn;
			break;
		case SOGOTOPOSITION:
			hProc->SoRtns.SOGoToPosition = CAST pRtn;
			break;
		case SODRAWLINE:
			hProc->SoRtns.SODrawLine = CAST pRtn;
			break;
		}

#undef CAST
}


VW_ENTRYSC VOID VW_ENTRYMOD VwSetUserFunc(dwUser1,dwUser2,hProc)
DWORD	dwUser1;
DWORD	dwUser2;
HPROC	hProc;
{
	hProc->User1 = dwUser1;
	hProc->User2 = dwUser2;
}


VW_ENTRYSC VOID VW_ENTRYMOD VwGetRtnsFunc(pRtns,wLastRtn)
VWRTNS VWPTR * pRtns;
WORD           wLastRtn;
{

#ifdef WINDOWS

#define FUNCTIONNAME(func) func

#if _MSC_VER >= 700
#define CAST	(VOID FAR *)
#else
#define CAST	(VOID (SO_ENTRYMOD *)())
#endif

#endif /*WINDOWS*/

#ifdef MAC
#define FUNCTIONNAME(func) x##func
#define CAST	(VOID *)
#endif /*MAC*/

#ifdef VwStreamOpenFunc
	pRtns->StreamOpen = FUNCTIONNAME(VwStreamOpen);
#else
	pRtns->StreamOpen = NULL;
#endif

#ifdef VwStreamSectionFunc
	pRtns->StreamSection = FUNCTIONNAME(VwStreamSection);
#else
	pRtns->StreamSection = NULL;
#endif

#ifdef VwStreamReadFunc
	pRtns->StreamRead = FUNCTIONNAME(VwStreamRead);
#else
	pRtns->StreamRead = NULL;
#endif

#ifdef VwStreamTellFunc
	pRtns->StreamTell = FUNCTIONNAME(VwStreamTell);
#else
	pRtns->StreamTell = NULL;
#endif

#ifdef VwStreamSeekFunc
	pRtns->StreamSeek	= FUNCTIONNAME(VwStreamSeek);
#else
	pRtns->StreamSeek	= NULL;
#endif

#ifdef VwGetInfoFunc
	pRtns->GetInfo = FUNCTIONNAME(VwGetInfo);
#else
	pRtns->GetInfo = NULL;
#endif

#ifdef VwGetDataFunc
	pRtns->GetData = CAST FUNCTIONNAME(VwGetData);
#else
	pRtns->GetData = NULL;
#endif

#ifdef VwSetDataFunc
	pRtns->SetData = CAST FUNCTIONNAME(VwSetData);
#else
	pRtns->SetData = NULL;
#endif

#ifdef VwLocalUpFunc
	pRtns->LocalUp = FUNCTIONNAME(VwLocalUp);
#else
	pRtns->LocalUp = NULL;
#endif

#ifdef VwLocalDownFunc
	pRtns->LocalDown = FUNCTIONNAME(VwLocalDown);
#else
	pRtns->LocalDown = NULL;
#endif

#ifdef VwAllocProcFunc
	pRtns->AllocProc =  CAST FUNCTIONNAME(VwAllocProc);
#else
	pRtns->AllocProc = NULL;
#endif

#ifdef VwFreeProcFunc
	pRtns->FreeProc = FUNCTIONNAME(VwFreeProc);
#else
	pRtns->FreeProc = NULL;
#endif

#ifdef VwSetUserFunc
	pRtns->SetUser = FUNCTIONNAME(VwSetUser);
#else
	pRtns->SetUser = NULL;
#endif

#ifdef VwSetSoRtnFunc
	pRtns->SetSoRtn = FUNCTIONNAME(VwSetSoRtn);
#else
	pRtns->SetSoRtn = NULL;
#endif

#ifdef VwStreamCloseFunc
	pRtns->StreamClose = FUNCTIONNAME(VwStreamClose);
#else
	pRtns->StreamClose = NULL;
#endif

#ifdef VwStreamSectionType
#ifdef VwGetSectionDataFunc
	pRtns->GetSectionData = CAST FUNCTIONNAME(VwGetSectionData);
#else
	pRtns->GetSectionData = NULL;
#endif
#else
	pRtns->GetSectionData = NULL;
#endif

#ifdef VwStreamSectionType
#ifdef VwSetSectionDataFunc
	pRtns->SetSectionData = CAST FUNCTIONNAME(VwSetSectionData);
#else
	pRtns->SetSectionData = NULL;
#endif
#else
	pRtns->SetSectionData = NULL;
#endif

#ifdef VwStreamReadRecordFunc
	pRtns->StreamReadRecord = FUNCTIONNAME(VwStreamReadRecord);
#else
	pRtns->StreamReadRecord = NULL;
#endif

	if (wLastRtn >= VWRTN_DOSPECIAL)
		{
#ifdef VwDoSpecialFunc
	pRtns->DoSpecial = FUNCTIONNAME(VwDoSpecial);
#else
	pRtns->DoSpecial = NULL;
#endif
		}

#undef CAST
}

	/*
	| Filter macro for bitmap filters
	*/

#define	SetRGBPixel(pDest,pRGB)	{*(BYTE VWPTR *)pDest++=((BYTE VWPTR *)pRGB)[2];*(BYTE VWPTR *)pDest++=((BYTE VWPTR *)pRGB)[1];*(BYTE VWPTR *)pDest++=*((BYTE VWPTR *)pRGB);}


	/*
	|	SO routine macros
	*/

#define SOPutChar(a,hP)				(hP->SoRtns.SOPutChar)(a,hP->User1,hP->User2)
#define SOPutCharX(a,b,hP)			(hP->SoRtns.SOPutCharX)(a,b,hP->User1,hP->User2)
#define SOPutSpecialCharX(a,b,hP)	(hP->SoRtns.SOPutSpecialCharX)(a,b,hP->User1,hP->User2)
#define SOPutCharAttr(a,b,hP)		(hP->SoRtns.SOPutCharAttr)(a,b,hP->User1,hP->User2)
#define SOPutCharHeight(a,hP)		(hP->SoRtns.SOPutCharHeight)(a,hP->User1,hP->User2)
#define SOPutParaAlign(a,hP)			(hP->SoRtns.SOPutParaAlign)(a,hP->User1,hP->User2)
#define SOPutParaIndents(a,b,c,hP)	(hP->SoRtns.SOPutParaIndents)(a,b,c,hP->User1,hP->User2)
#define SOStartTabStops(hP)			(hP->SoRtns.SOStartTabStops)(hP->User1,hP->User2)
#define SOEndTabStops(hP)				(hP->SoRtns.SOEndTabStops)(hP->User1,hP->User2)
#define SOPutTabStop(a,hP)			(hP->SoRtns.SOPutTabStop)(a,hP->User1,hP->User2)
#define SOPutMargins(a,b,hP)			(hP->SoRtns.SOPutMargins)(a,b,hP->User1,hP->User2)
#define SOPutBreak(a,b,hP)			(hP->SoRtns.SOPutBreak)(a,(DWORD)(b),hP->User1,hP->User2)
#define SOPutSubdocInfo(a,b,hP)		(hP->SoRtns.SOPutSubdocInfo)(a,b,hP->User1,hP->User2)
#define SOPutTextCell(a,b,c,d,hP)	(hP->SoRtns.SOPutTextCell)(a,b,c,d,hP->User1,hP->User2)
#define SOPutMoreText(a,b,c,hP)		(hP->SoRtns.SOPutMoreText)(a,b,c,hP->User1,hP->User2)
#define SOPutDataCell(a,hP)			(hP->SoRtns.SOPutDataCell)(a,hP->User1,hP->User2)
#define SOPutField(a,hP)				(hP->SoRtns.SOPutField)(a,hP->User1,hP->User2)
#define SOPutVarField(a,b,c,hP)		(hP->SoRtns.SOPutVarField)(a,b,c,hP->User1,hP->User2)
#define SOPutMoreVarField(a,b,c,hP)(hP->SoRtns.SOPutMoreVarField)(a,b,c,hP->User1,hP->User2)
#define SOStartColumnInfo(hP)		(hP->SoRtns.SOStartColumnInfo)(hP->User1,hP->User2)
#define SOStartFieldInfo(hP)			(hP->SoRtns.SOStartFieldInfo)(hP->User1,hP->User2)
#define SOPutColumnInfo(a,hP)		(hP->SoRtns.SOPutColumnInfo)(a,hP->User1,hP->User2)
#define SOPutFieldInfo(a,hP)			(hP->SoRtns.SOPutFieldInfo)(a,hP->User1,hP->User2)
#define SOEndColumnInfo(hP)			(hP->SoRtns.SOEndColumnInfo)(hP->User1,hP->User2)
#define SOEndFieldInfo(hP)			(hP->SoRtns.SOEndFieldInfo)(hP->User1,hP->User2)
#define SOPutSectionType(a,hP)		(hP->SoRtns.SOPutSectionType)(a,hP->User1,hP->User2)
#define SOPutSectionName(a,hP)		(hP->SoRtns.SOPutSectionName)(a,hP->User1,hP->User2)
#define SOSetDateBase(a,b,hP)		(hP->SoRtns.SOSetDateBase)(a,b,hP->User1,hP->User2)
#define SOBailOut(a,hP)				(hP->SoRtns.SOBailOut)(a,hP->User1,hP->User2)
#define SOTagBegin(a,hP)				(hP->SoRtns.SOTagBegin)(a,hP->User1,hP->User2)
#define SOTagEnd(hP)					(hP->SoRtns.SOTagEnd)(hP->User1,hP->User2)
#define SOGetInfo(a,b,hP)				(hP->SoRtns.SOGetInfo)(a,b,hP->User1,hP->User2)
#define SUUserSaveData(a,hP)			(hP->SoRtns.SUUserSaveData)(a,hP->User1,hP->User2)
#define SUUserRetrieveData(a,b,hP)	(hP->SoRtns.SUUserRetrieveData)(a,b,hP->User1,hP->User2)
#define SOPutBitmapHeader(a,hP)		(hP->SoRtns.SOPutBitmapHeader)(a,hP->User1,hP->User2)
#define SOStartPalette(hP)				(hP->SoRtns.SOStartPalette)(hP->User1,hP->User2)
#define SOPutPaletteEntry(a,b,c,hP)	(hP->SoRtns.SOPutPaletteEntry)(a,b,c,hP->User1,hP->User2)
#define SOEndPalette(hP)				(hP->SoRtns.SOEndPalette)(hP->User1,hP->User2)
#define SOPutScanLineData(a,hP)		(hP->SoRtns.SOPutScanLineData)(a,hP->User1,hP->User2)
#define SOPutCharFontById(a,hP)		(hP->SoRtns.SOPutCharFontById)(a,hP->User1,hP->User2)
#define SOPutCharFontByName(a,b,hP) 	(hP->SoRtns.SOPutCharFontByName)(a,b,hP->User1,hP->User2)
#define SOPutParaSpacing(a,b,c,d,hP) 	(hP->SoRtns.SOPutParaSpacing)(a,b,c,d,hP->User1,hP->User2)
#define SOStartFontTable(hP) 				(hP->SoRtns.SOStartFontTable)(hP->User1,hP->User2)
#define SOPutFontTableEntry(a,b,c,hP) 	(hP->SoRtns.SOPutFontTableEntry)(a,b,c,hP->User1,hP->User2)
#define SOEndFontTable(hP) 					(hP->SoRtns.SOEndFontTable)(hP->User1,hP->User2)
#define SOPutArchiveField(a,b,c,hP)		(hP->SoRtns.SOPutArchiveField)(a,b,c,hP->User1,hP->User2)
#define SOStartHdrInfo(hP)				(hP->SoRtns.SOStartHdrInfo)(hP->User1,hP->User2)
#define SOEndHdrInfo(hP)					(hP->SoRtns.SOEndHdrInfo)(hP->User1,hP->User2)
#define SOPutHdrEntry(a,b,c,hP)			(hP->SoRtns.SOPutHdrEntry)(a,b,c,hP->User1,hP->User2)
#define SOPutVectorHeader(a,hP)			(hP->SoRtns.SOPutVectorHeader)(a,hP->User1,hP->User2)
#define SOVectorObject(a,b,c,hP)			(hP->SoRtns.SOVectorObject)(a,b,c,hP->User1,hP->User2)
#define SOVectorAttr(a,b,c,hP)			(hP->SoRtns.SOVectorAttr)(a,b,c,hP->User1,hP->User2)
#define SOBeginTable(hP)						(hP->SoRtns.SOBeginTable)(hP->User1,hP->User2)
#define SOEndTable(hP)							(hP->SoRtns.SOEndTable)(hP->User1,hP->User2)
#define SOPutTableRowFormat(a,b,c,d,e,f,hP)	(hP->SoRtns.SOPutTableRowFormat)(a,b,c,d,e,f,hP->User1,hP->User2)
#define SOPutTableCellInfo(a,hP) 		(hP->SoRtns.SOPutTableCellInfo)(a,hP->User1,hP->User2)
#define SOPutGraphicObject(a,hP)			(hP->SoRtns.SOPutGraphicObject)(a,hP->User1,hP->User2)
#define SOGoToPosition(a,hP)				(hP->SoRtns.SOGoToPosition)(a,hP->User1,hP->User2)
#define SODrawLine(a,b,c,d,e,hP)			(hP->SoRtns.SODrawLine)(a,b,c,d,e,hP->User1,hP->User2)
