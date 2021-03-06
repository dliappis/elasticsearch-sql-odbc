/*
 * Copyright Elasticsearch B.V. and/or licensed to Elasticsearch B.V. under one
 * or more contributor license agreements. Licensed under the Elastic License;
 * you may not use this file except in compliance with the Elastic License.
 */

#ifndef __INFO_H__
#define __INFO_H__

#include "sqlext.h"

#if ODBCVER == 0x0380
/* String constant for supported ODBC version */
#define ESODBC_SQL_SPEC_STRING	"03.80"
#else /* ver==3.8 */
#error "unsupported ODBC version"
#endif /* ver==3.8 */

SQLRETURN EsSQLGetInfoW(SQLHDBC ConnectionHandle,
	SQLUSMALLINT InfoType,
	_Out_writes_bytes_opt_(BufferLength) SQLPOINTER InfoValue,
	SQLSMALLINT BufferLength,
	_Out_opt_ SQLSMALLINT *StringLengthPtr);

SQLRETURN EsSQLGetDiagFieldW(
	SQLSMALLINT HandleType,
	SQLHANDLE Handle,
	SQLSMALLINT RecNumber,
	SQLSMALLINT DiagIdentifier,
	_Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER DiagInfoPtr,
	SQLSMALLINT BufferLength,
	_Out_opt_ SQLSMALLINT *StringLengthPtr);

SQLRETURN EsSQLGetDiagRecW(
	SQLSMALLINT HandleType,
	SQLHANDLE Handle,
	SQLSMALLINT RecNumber,
	_Out_writes_opt_(6) SQLWCHAR *Sqlstate,
	SQLINTEGER *NativeError,
	_Out_writes_opt_(BufferLength) SQLWCHAR *MessageText,
	SQLSMALLINT BufferLength,
	_Out_opt_ SQLSMALLINT *TextLength);

SQLRETURN EsSQLGetFunctions(SQLHDBC ConnectionHandle,
	SQLUSMALLINT FunctionId,
	_Out_writes_opt_
	(_Inexpressible_("Buffer length pfExists points to depends on fFunction value."))
	SQLUSMALLINT *Supported);

SQLRETURN EsSQLGetTypeInfoW(SQLHSTMT StatementHandle, SQLSMALLINT DataType);

#endif /* __INFO_H__ */

/* vim: set noet fenc=utf-8 ff=dos sts=0 sw=4 ts=4 : */
