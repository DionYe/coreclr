//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information. 
//

/*=============================================================================
**
** Source: dllmain.c
**
** Purpose: Test to ensure DllMain() is called with THREAD_DETACH
**          when a thread in the application calls ExitThread().
** 
** Dependencies: none
** 

**
**===========================================================================*/

#include <palsuite.h>

/* count of the number of times DllMain() was called with THREAD_DETACH */
static int g_detachCount = 0;


/* standard DllMain() */
BOOL PALAPI DllMain(HINSTANCE hinstDLL, DWORD reason, LPVOID lpvReserved)
{
    switch( reason )
    {
        case DLL_PROCESS_ATTACH:
        {
            break;
        }
    
        case DLL_PROCESS_DETACH:
        {
            break;
        }
        
        case DLL_THREAD_ATTACH:
            break;
    
        case DLL_THREAD_DETACH:
            /* increment g_detachCount */
            g_detachCount++;
            break;
    }
    return TRUE;
}

#ifdef WIN32
BOOL __stdcall _DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    return DllMain(hinstDLL, fdwReason, lpvReserved);
}
#endif


/* function to return the current detach count */
#ifdef WIN32
__declspec(dllexport)
#endif
int PALAPI GetDetachCount( void )
{
    return g_detachCount;
}
