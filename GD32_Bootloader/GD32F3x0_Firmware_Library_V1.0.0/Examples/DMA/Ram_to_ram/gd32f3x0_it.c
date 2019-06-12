/*!
    \file  gd32f3x0_it.c
    \brief interrupt service routines
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-06, V1.0.0, firmware for GD32F3x0
*/

#include "gd32f3x0_it.h"

extern __IO uint8_t g_dmacomplete_flag;

/*!
    \brief      this function handles NMI exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void NMI_Handler(void)
{
}

/*!
    \brief      this function handles HardFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void HardFault_Handler(void)
{
    /* if Hard Fault exception occurs, go to infinite loop */
    while (1);
}

/*!
    \brief      this function handles MemManage exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void MemManage_Handler(void)
{
    /* if Memory Manage exception occurs, go to infinite loop */
    while (1);
}

/*!
    \brief      this function handles BusFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void BusFault_Handler(void)
{
    /* if Bus Fault exception occurs, go to infinite loop */
    while (1);
}

/*!
    \brief      this function handles UsageFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void UsageFault_Handler(void)
{
    /* if Usage Fault exception occurs, go to infinite loop */
    while (1);
}

/*!
    \brief      this function handles SVC exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SVC_Handler(void)
{
}

/*!
    \brief      this function handles DebugMon exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DebugMon_Handler(void)
{
}

/*!
    \brief      this function handles PendSV exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PendSV_Handler(void)
{
}

/*!
    \brief      this function handles SysTick exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SysTick_Handler(void)
{
}

/*!
    \brief      this function handles DMA_Channel1_2_IRQHandler interrupt
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DMA_Channel1_2_IRQHandler(void)
{
    if(dma_interrupt_flag_get(DMA_CH1, DMA_INT_FLAG_FTF)){     
        dma_interrupt_flag_clear(DMA_CH1, DMA_INT_FLAG_G);
        g_dmacomplete_flag |= (1 << 0);
    }
    
    if(dma_interrupt_flag_get(DMA_CH2, DMA_INT_FLAG_FTF)){     
        dma_interrupt_flag_clear(DMA_CH2, DMA_INT_FLAG_G);
        g_dmacomplete_flag |= (1 << 1);
    }
}

/*!
    \brief      this function handles DMA_Channel1_2_IRQHandler interrupt
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DMA_Channel3_4_IRQHandler(void)
{
    if(dma_interrupt_flag_get(DMA_CH3, DMA_INT_FLAG_FTF)){     
    dma_interrupt_flag_clear(DMA_CH3, DMA_INT_FLAG_G);
    g_dmacomplete_flag |= (1 << 2);
    }
    
    if(dma_interrupt_flag_get(DMA_CH4, DMA_INT_FLAG_FTF)){     
        dma_interrupt_flag_clear(DMA_CH4, DMA_INT_FLAG_G);
        g_dmacomplete_flag |= (1 << 3);
    }
}