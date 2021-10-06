/*******************************************************************************
* File Name: InADC.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_InADC_H) /* Pins InADC_H */
#define CY_PINS_InADC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "InADC_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 InADC__PORT == 15 && ((InADC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    InADC_Write(uint8 value);
void    InADC_SetDriveMode(uint8 mode);
uint8   InADC_ReadDataReg(void);
uint8   InADC_Read(void);
void    InADC_SetInterruptMode(uint16 position, uint16 mode);
uint8   InADC_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the InADC_SetDriveMode() function.
     *  @{
     */
        #define InADC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define InADC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define InADC_DM_RES_UP          PIN_DM_RES_UP
        #define InADC_DM_RES_DWN         PIN_DM_RES_DWN
        #define InADC_DM_OD_LO           PIN_DM_OD_LO
        #define InADC_DM_OD_HI           PIN_DM_OD_HI
        #define InADC_DM_STRONG          PIN_DM_STRONG
        #define InADC_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define InADC_MASK               InADC__MASK
#define InADC_SHIFT              InADC__SHIFT
#define InADC_WIDTH              1u

/* Interrupt constants */
#if defined(InADC__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in InADC_SetInterruptMode() function.
     *  @{
     */
        #define InADC_INTR_NONE      (uint16)(0x0000u)
        #define InADC_INTR_RISING    (uint16)(0x0001u)
        #define InADC_INTR_FALLING   (uint16)(0x0002u)
        #define InADC_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define InADC_INTR_MASK      (0x01u) 
#endif /* (InADC__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define InADC_PS                     (* (reg8 *) InADC__PS)
/* Data Register */
#define InADC_DR                     (* (reg8 *) InADC__DR)
/* Port Number */
#define InADC_PRT_NUM                (* (reg8 *) InADC__PRT) 
/* Connect to Analog Globals */                                                  
#define InADC_AG                     (* (reg8 *) InADC__AG)                       
/* Analog MUX bux enable */
#define InADC_AMUX                   (* (reg8 *) InADC__AMUX) 
/* Bidirectional Enable */                                                        
#define InADC_BIE                    (* (reg8 *) InADC__BIE)
/* Bit-mask for Aliased Register Access */
#define InADC_BIT_MASK               (* (reg8 *) InADC__BIT_MASK)
/* Bypass Enable */
#define InADC_BYP                    (* (reg8 *) InADC__BYP)
/* Port wide control signals */                                                   
#define InADC_CTL                    (* (reg8 *) InADC__CTL)
/* Drive Modes */
#define InADC_DM0                    (* (reg8 *) InADC__DM0) 
#define InADC_DM1                    (* (reg8 *) InADC__DM1)
#define InADC_DM2                    (* (reg8 *) InADC__DM2) 
/* Input Buffer Disable Override */
#define InADC_INP_DIS                (* (reg8 *) InADC__INP_DIS)
/* LCD Common or Segment Drive */
#define InADC_LCD_COM_SEG            (* (reg8 *) InADC__LCD_COM_SEG)
/* Enable Segment LCD */
#define InADC_LCD_EN                 (* (reg8 *) InADC__LCD_EN)
/* Slew Rate Control */
#define InADC_SLW                    (* (reg8 *) InADC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define InADC_PRTDSI__CAPS_SEL       (* (reg8 *) InADC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define InADC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) InADC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define InADC_PRTDSI__OE_SEL0        (* (reg8 *) InADC__PRTDSI__OE_SEL0) 
#define InADC_PRTDSI__OE_SEL1        (* (reg8 *) InADC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define InADC_PRTDSI__OUT_SEL0       (* (reg8 *) InADC__PRTDSI__OUT_SEL0) 
#define InADC_PRTDSI__OUT_SEL1       (* (reg8 *) InADC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define InADC_PRTDSI__SYNC_OUT       (* (reg8 *) InADC__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(InADC__SIO_CFG)
    #define InADC_SIO_HYST_EN        (* (reg8 *) InADC__SIO_HYST_EN)
    #define InADC_SIO_REG_HIFREQ     (* (reg8 *) InADC__SIO_REG_HIFREQ)
    #define InADC_SIO_CFG            (* (reg8 *) InADC__SIO_CFG)
    #define InADC_SIO_DIFF           (* (reg8 *) InADC__SIO_DIFF)
#endif /* (InADC__SIO_CFG) */

/* Interrupt Registers */
#if defined(InADC__INTSTAT)
    #define InADC_INTSTAT            (* (reg8 *) InADC__INTSTAT)
    #define InADC_SNAP               (* (reg8 *) InADC__SNAP)
    
	#define InADC_0_INTTYPE_REG 		(* (reg8 *) InADC__0__INTTYPE)
#endif /* (InADC__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_InADC_H */


/* [] END OF FILE */
