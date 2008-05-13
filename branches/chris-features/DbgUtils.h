//----------------------------------------------------------------------------------------
//	DbgUtils.h - Cocoa debugging and error handling
//
//	Copyright © Chris, 2003 - 2008.  All rights reserved.
//----------------------------------------------------------------------------------------

#pragma once

#include "CommonUtils.h"

#ifndef qDebug
	#define qDebug		1
#endif
#ifndef kAppName
	#define	kAppName	"svnX"
#endif

#define	qTime		(qDebug && 0)


//----------------------------------------------------------------------------------------
#pragma mark -
//----------------------------------------------------------------------------------------
#if qDebug

	#define	_F_L_F_							__FILE__, __LINE__, __PRETTY_FUNCTION__
	#define	WarnIf(expr)					DbgWarnIf(_F_L_F_, (expr))
	#define	WarnIfNot(expr, ex)				DbgWarnIfNot(_F_L_F_, (expr), (ex))
	#define	Assert(expr)					do { if (!(expr)) DbgAssert(_F_L_F_, #expr); } while (0)
	#define Log(expr)						DbgLog(_F_L_F_, #expr)
	#define dprintf(fmt, args...)			DbgLogF(_F_L_F_, fmt, args)
	#define ReportCatch(expr)				DbgReportCatch(_F_L_F_, (expr))

	ConstCStr	LeafName		(ConstCStr file);
	ConstCStr	Demangle		(ConstCStr func);
	OSStatus	DbgWarnIf		(ConstCStr file, int line, ConstCStr func, OSStatus err);
	OSStatus	DbgWarnIfNot	(ConstCStr file, int line, ConstCStr func, OSStatus err, OSStatus exclude);
	void		DbgAssert		(ConstCStr file, int line, ConstCStr func, ConstCStr expr);
	void		DbgLogF			(ConstCStr file, int line, ConstCStr func, ConstCStr fmt, ...);
	void		DbgLog			(ConstCStr file, int line, ConstCStr func, ConstCStr msg);
	void		DbgReportCatch	(ConstCStr file, int line, ConstCStr func, NSObject* err);


//----------------------------------------------------------------------------------------
#elif !qDebug

	#define	WarnIf(expr)					(expr)
	#define	WarnIfNot(expr, ex)				(expr)
	#define	Assert(expr)					/*DbgAssert(_F_L_F_, #expr)*/
	#define Log(expr)						/*DbgLog(_F_L_F_, #expr)*/
	#define dprintf(fmt, args...)			/*DbgLog(_F_L_F_, fmt, args)*/
	#define ReportCatch(expr)				/*DbgReportCatch(_F_L_F_, (expr))*/

#endif


//----------------------------------------------------------------------------------------
// End of DbgUtils.h
