/*
 * tclexpat.c --
 *
 *	A Tcl interface to James Clark's expat XML parser
 *
 * Copyright (c) 1998 Steve Ball, Zveno Pty Ltd
 *
 * Zveno Pty Ltd makes this software and associated documentation
 * available free of charge for any purpose.  You may make copies
 * of the software but you must include all of this notice on any copy.
 *
 * Zveno Pty Ltd does not warrant that this software is error free
 * or fit for any purpose.  Zveno Pty Ltd disclaims any liability for
 * all claims, expenses, losses, damages and costs any user may incur
 * as a result of using, copying or modifying the software.
 *
 * $Id: nsexpat.c,v 1.3 2007/04/25 21:28:41 seryakov Exp $
 *
 */

#define USE_TCL8X

#include <ns.h>
#include <tcl.h>
#include "tclexpat.h"

int Ns_ModuleVersion = 1;

/*
 *----------------------------------------------------------------------------
 *
 * TclExpat_Init --
 *
 *	Initialisation routine for loadable module
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Defines "expat" command in the interpreter.
 *
 *----------------------------------------------------------------------------
 */

int Tclexpat_Init(Tcl_Interp * interp, const void *context)
{
    Tcl_CreateObjCommand(interp, "expat", TclExpatObjCmd, NULL, NULL);
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * Ns_ModuleInit --
 *
 *	Load the config parameters, setup the structures, and
 *	listen on the trap port.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	None
 *
 *----------------------------------------------------------------------
 */

int Ns_ModuleInit(char *hServer, char *hModule)
{
    Ns_TclRegisterTrace(hServer, Tclexpat_Init, 0, NS_TCL_TRACE_CREATE);
    return NS_OK;
}

