#ifndef __EEP_8000_H
#define __EEP_8000_H

/*******************************************************************************
 * Copyright (c) PLX Technology, Inc.
 *
 * PLX Technology Inc. licenses this source file under the GNU Lesser General Public
 * License (LGPL) version 2.  This source file may be modified or redistributed
 * under the terms of the LGPL and without express permission from PLX Technology.
 *
 * PLX Technology, Inc. provides this software AS IS, WITHOUT ANY WARRANTY,
 * EXPRESS OR IMPLIED, INCLUDING, WITHOUT LIMITATION, ANY WARRANTY OF
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  PLX makes no guarantee
 * or representations regarding the use of, or the results of the use of,
 * the software and documentation in terms of correctness, accuracy,
 * reliability, currentness, or otherwise; and you rely on the software,
 * documentation and results solely at your own risk.
 *
 * IN NO EVENT SHALL PLX BE LIABLE FOR ANY LOSS OF USE, LOSS OF BUSINESS,
 * LOSS OF PROFITS, INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES
 * OF ANY KIND.
 *
 ******************************************************************************/

/******************************************************************************
 *
 * File Name:
 *
 *      Eep_8000.h
 *
 * Description:
 *
 *      The include file for 8000-series EEPROM support functions
 *
 * Revision History:
 *
 *      12-01-07 : PLX SDK v5.20
 *
 ******************************************************************************/


#include "DrvDefs.h"


#ifdef __cplusplus
extern "C" {
#endif




/**********************************************
*               Definitions
**********************************************/
#define CONST_CRC_XOR_VALUE             0xDB710641          // Constant used in CRC calculations

// PLX 8000-series EEPROM definitions
#define PLX8000_EE_CMD_READ             3
#define PLX8000_EE_CMD_READ_STATUS      5
#define PLX8000_EE_CMD_WRITE_ENABLE     6
#define PLX8000_EE_CMD_WRITE_DISABLE    4
#define PLX8000_EE_CMD_WRITE            2
#define PLX8000_EE_CMD_WRITE_STATUS     1




/**********************************************
*               Functions
**********************************************/
PLX_STATUS
Plx8000_EepromPresent(
    DEVICE_EXTENSION *pdx,
    U8               *pStatus
    );

PLX_STATUS
Plx8000_EepromSetAddressWidth(
    DEVICE_EXTENSION *pdx,
    U8                width
    );

PLX_STATUS
Plx8000_EepromCrcGet(
    DEVICE_EXTENSION *pdx,
    U32              *pCrc,
    U8               *pCrcStatus
    );

PLX_STATUS
Plx8000_EepromCrcUpdate(
    DEVICE_EXTENSION *pdx,
    U32              *pCrc,
    BOOLEAN           bUpdateEeprom
    );

PLX_STATUS
Plx8000_EepromReadByOffset(
    DEVICE_EXTENSION *pdx,
    U16               offset,
    U32              *pValue
    );

PLX_STATUS
Plx8000_EepromWriteByOffset(
    DEVICE_EXTENSION *pdx,
    U16               offset,
    U32               value
    );

BOOLEAN
Plx8000_EepromWaitIdle(
    DEVICE_EXTENSION *pdx
    );

BOOLEAN
Plx8000_EepromSendCommand(
    DEVICE_EXTENSION *pdx,
    U32               command
    );

VOID
Plx8000_EepromComputeNextCrc(
    U32 *pCrc,
    U32  NextEepromValue
    );



#ifdef __cplusplus
}
#endif

#endif
