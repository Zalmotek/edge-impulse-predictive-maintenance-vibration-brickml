/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = r_icu_isr, /* ICU IRQ9 (External pin interrupt 9) */
            [1] = fcu_frdyi_isr, /* FCU FRDYI (Flash ready interrupt) */
            [2] = fcu_fiferr_isr, /* FCU FIFERR (Flash access error interrupt) */
            [3] = sci_uart_rxi_isr, /* SCI0 RXI (Receive data full) */
            [4] = sci_uart_txi_isr, /* SCI0 TXI (Transmit data empty) */
            [5] = sci_uart_tei_isr, /* SCI0 TEI (Transmit end) */
            [6] = sci_uart_eri_isr, /* SCI0 ERI (Receive error) */
            [7] = usbfs_interrupt_handler, /* USBFS INT (USBFS interrupt) */
            [8] = usbfs_resume_handler, /* USBFS RESUME (USBFS resume interrupt) */
            [9] = usbfs_d0fifo_handler, /* USBFS FIFO 0 (DMA transfer request 0) */
            [10] = usbfs_d1fifo_handler, /* USBFS FIFO 1 (DMA transfer request 1) */
            [11] = usbhs_interrupt_handler, /* USBHS USB INT RESUME (USBHS interrupt) */
            [12] = sci_i2c_txi_isr, /* SCI9 TXI (Transmit data empty) */
            [13] = sci_i2c_tei_isr, /* SCI9 TEI (Transmit end) */
            [14] = iic_master_rxi_isr, /* IIC1 RXI (Receive data full) */
            [15] = iic_master_txi_isr, /* IIC1 TXI (Transmit data empty) */
            [16] = iic_master_tei_isr, /* IIC1 TEI (Transmit end) */
            [17] = iic_master_eri_isr, /* IIC1 ERI (Transfer error) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ9), /* ICU IRQ9 (External pin interrupt 9) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_FCU_FRDYI), /* FCU FRDYI (Flash ready interrupt) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_FCU_FIFERR), /* FCU FIFERR (Flash access error interrupt) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_SCI0_RXI), /* SCI0 RXI (Receive data full) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TXI), /* SCI0 TXI (Transmit data empty) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TEI), /* SCI0 TEI (Transmit end) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_SCI0_ERI), /* SCI0 ERI (Receive error) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_USBFS_INT), /* USBFS INT (USBFS interrupt) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_USBFS_RESUME), /* USBFS RESUME (USBFS resume interrupt) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_USBFS_FIFO_0), /* USBFS FIFO 0 (DMA transfer request 0) */
            [10] = BSP_PRV_IELS_ENUM(EVENT_USBFS_FIFO_1), /* USBFS FIFO 1 (DMA transfer request 1) */
            [11] = BSP_PRV_IELS_ENUM(EVENT_USBHS_USB_INT_RESUME), /* USBHS USB INT RESUME (USBHS interrupt) */
            [12] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TXI), /* SCI9 TXI (Transmit data empty) */
            [13] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TEI), /* SCI9 TEI (Transmit end) */
            [14] = BSP_PRV_IELS_ENUM(EVENT_IIC1_RXI), /* IIC1 RXI (Receive data full) */
            [15] = BSP_PRV_IELS_ENUM(EVENT_IIC1_TXI), /* IIC1 TXI (Transmit data empty) */
            [16] = BSP_PRV_IELS_ENUM(EVENT_IIC1_TEI), /* IIC1 TEI (Transmit end) */
            [17] = BSP_PRV_IELS_ENUM(EVENT_IIC1_ERI), /* IIC1 ERI (Transfer error) */
        };
        #endif
